import wx
import os
import eyed3
import glob

# Main application frame
class MP3TagEditorFrame(wx.Frame):
    def __init__(self, *args, **kwargs):
        super(MP3TagEditorFrame, self).__init__(*args, **kwargs)
        
        # Create a panel
        panel = wx.Panel(self)
        
        # Create a menu bar
        menu_bar = wx.MenuBar()
        
        # Create a File menu
        file_menu = wx.Menu()
        open_folder = file_menu.Append(wx.ID_OPEN, 'Open Folder')
        exit_app = file_menu.Append(wx.ID_EXIT, 'Exit')
        menu_bar.Append(file_menu, '&File')
        self.SetMenuBar(menu_bar)
        
        # Bind menu events
        self.Bind(wx.EVT_MENU, self.on_open_folder, open_folder)
        self.Bind(wx.EVT_MENU, self.on_exit, exit_app)
        
        # Create ListCtrl to show MP3 file tags
        self.list_ctrl = wx.ListCtrl(panel, style=wx.LC_REPORT | wx.BORDER_SUNKEN)
        self.list_ctrl.InsertColumn(0, 'File Name', width=200)
        self.list_ctrl.InsertColumn(1, 'Artist', width=140)
        self.list_ctrl.InsertColumn(2, 'Album', width=140)
        self.list_ctrl.InsertColumn(3, 'Title', width=140)
        
        # Create buttons for editing tags
        edit_button = wx.Button(panel, label="Edit Tag")
        edit_button.Bind(wx.EVT_BUTTON, self.on_edit)
        
        # Use sizer to layout widgets
        sizer = wx.BoxSizer(wx.VERTICAL)
        sizer.Add(self.list_ctrl, 1, wx.EXPAND | wx.ALL, 5)
        sizer.Add(edit_button, 0, wx.ALL | wx.CENTER, 5)
        panel.SetSizer(sizer)
        
        # Set up the main frame
        self.SetTitle('MP3 Tag Editor')
        self.SetSize((600, 400))
        self.Centre()
    
    def on_open_folder(self, event):
        """Open directory dialog to select folder with MP3 files."""
        dialog = wx.DirDialog(self, "Choose MP3 Directory")
        if dialog.ShowModal() == wx.ID_OK:
            folder_path = dialog.GetPath()
            self.load_mp3_files(folder_path)
        dialog.Destroy()

    def load_mp3_files(self, folder_path):
        """Load MP3 files from the selected folder."""
        self.list_ctrl.DeleteAllItems()  # Clear the current list
        mp3_files = glob.glob(os.path.join(folder_path, "*.mp3"))
        
        for mp3_file in mp3_files:
            audiofile = eyed3.load(mp3_file)
            if audiofile is not None and audiofile.tag is not None:
                artist = audiofile.tag.artist if audiofile.tag.artist else "Unknown"
                album = audiofile.tag.album if audiofile.tag.album else "Unknown"
                title = audiofile.tag.title if audiofile.tag.title else "Unknown"
                
                index = self.list_ctrl.InsertItem(self.list_ctrl.GetItemCount(), os.path.basename(mp3_file))
                self.list_ctrl.SetItem(index, 1, artist)
                self.list_ctrl.SetItem(index, 2, album)
                self.list_ctrl.SetItem(index, 3, title)

    def on_edit(self, event):
        """Edit the selected MP3 tag."""
        selected_item = self.list_ctrl.GetFocusedItem()
        if selected_item != -1:
            file_name = self.list_ctrl.GetItemText(selected_item)
            artist = self.list_ctrl.GetItem(selected_item, 1).GetText()
            album = self.list_ctrl.GetItem(selected_item, 2).GetText()
            title = self.list_ctrl.GetItem(selected_item, 3).GetText()
            
            # Open the edit dialog
            edit_dialog = EditTagDialog(self, file_name, artist, album, title)
            if edit_dialog.ShowModal() == wx.ID_OK:
                new_artist, new_album, new_title = edit_dialog.get_values()
                
                # Update the list
                self.list_ctrl.SetItem(selected_item, 1, new_artist)
                self.list_ctrl.SetItem(selected_item, 2, new_album)
                self.list_ctrl.SetItem(selected_item, 3, new_title)

            edit_dialog.Destroy()

    def on_exit(self, event):
        """Close the application."""
        self.Close()

# Edit dialog for MP3 tags
class EditTagDialog(wx.Dialog):
    def __init__(self, parent, file_name, artist, album, title):
        super().__init__(parent, title=f"Edit Tags for {file_name}")
        
        self.artist_ctrl = wx.TextCtrl(self, value=artist)
        self.album_ctrl = wx.TextCtrl(self, value=album)
        self.title_ctrl = wx.TextCtrl(self, value=title)
        
        # Layout with sizers
        sizer = wx.BoxSizer(wx.VERTICAL)
        
        sizer.Add(wx.StaticText(self, label="Artist:"), 0, wx.ALL, 5)
        sizer.Add(self.artist_ctrl, 0, wx.EXPAND | wx.ALL, 5)
        
        sizer.Add(wx.StaticText(self, label="Album:"), 0, wx.ALL, 5)
        sizer.Add(self.album_ctrl, 0, wx.EXPAND | wx.ALL, 5)
        
        sizer.Add(wx.StaticText(self, label="Title:"), 0, wx.ALL, 5)
        sizer.Add(self.title_ctrl, 0, wx.EXPAND | wx.ALL, 5)
        
        # OK and Cancel buttons
        btn_sizer = self.CreateButtonSizer(wx.OK | wx.CANCEL)
        sizer.Add(btn_sizer, 0, wx.ALL | wx.CENTER, 10)
        
        self.SetSizer(sizer)
        self.Fit()
    
    def get_values(self):
        """Return the updated artist, album, and title."""
        return self.artist_ctrl.GetValue(), self.album_ctrl.GetValue(), self.title_ctrl.GetValue()

# Main Application Entry Point
if __name__ == "__main__":
    app = wx.App(False)
    frame = MP3TagEditorFrame(None)
    frame.Show()
    app.MainLoop()
