#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <windows.h>
using namespace std;

void go_back_n(int ws_bits, int num_frames)
{
    int window_size = pow(2, ws_bits) - 1;
    cout << "Window size: " << window_size << "\n";
    srand(100);

    int i = 1;
    while (i <= num_frames)
    {
        int acknowledged = 0;
        bool ack_lost_or_delayed = false;

        // Sending frames in the current window
        for (int j = i; j < i + window_size && j <= num_frames; j++)
        {
            cout << "Sent frame " << j << "\n";
            Sleep(1000);
        }

        // Receiving acknowledgments
        for (int j = i; j < i + window_size && j <= num_frames; j++)
        {
            int ack = rand() % 3; // 0: lost, 1: delayed, 2: received

            if (ack == 2) // ACK received
            {
                cout << "Ack received for frame " << j << "\n";
                acknowledged++;
                Sleep(1000);
            }
            else if (ack == 1) // ACK delayed
            {
                cout << "Ack delayed for frame " << j << "\n";
                Sleep(2000); // Simulating delay
                cout << "Ack received for frame " << j << " (delayed)\n";
                acknowledged++;
                Sleep(1000);
            }
            else // ACK lost
            {
                cout << "Ack lost for frame " << j << "\n";
                ack_lost_or_delayed = true;
                Sleep(1000);
                cout << "Retransmitting the window\n";
                Sleep(1000);
                break;
            }
        }

        // Only slide the window if at least one frame was acknowledged
        if (acknowledged > 0 && !ack_lost_or_delayed)
        {
            i += acknowledged; // Move the window forward by the number of acknowledged frames
            cout << "\n<--- Window slides --->\n\n";
        }
    }
}
void selective_repeat(int ws_bits, int num_frames)
{
    int window_size = pow(2, ws_bits - 1);
    cout << "Window size: " << window_size << "\n";

    vector<int> recv_window(window_size, -1);

    int next_frame_to_send = 1;
    int total_acked = 0;
    srand(100); // Seed random number generator

    while (total_acked < num_frames)
    {
        // Send frames in the current window
        for (int i = 0; i < window_size && next_frame_to_send <= num_frames; ++i)
        {
            if (recv_window[i] == -1)
            {
                cout << "Sent frame " << next_frame_to_send << "\n";
                recv_window[i] = next_frame_to_send;
                next_frame_to_send++;
                Sleep(1000);
            }
        }

        // Process ACK/NAK for each frame in the window
        bool window_slid = false;
        for (int i = 0; i < window_size; ++i)
        {
            if (recv_window[i] != -1)
            {
                int ack_status = rand() % 3; // 0: lost, 1: delayed, 2: received

                if (ack_status == 2) // ACK received
                {
                    cout << "Ack received for frame " << recv_window[i] << "\n";
                    recv_window[i] = -1;
                    total_acked++;
                    window_slid = true;
                }
                else if (ack_status == 1) // ACK delayed
                {
                    cout << "Ack delayed for frame " << recv_window[i] << "\n";
                    Sleep(2000); // Simulating delay
                    cout << "Ack received for frame " << recv_window[i] << " (delayed)\n";
                    recv_window[i] = -1;
                    total_acked++;
                    window_slid = true;
                }
                else // ACK lost
                {
                    cout << "Ack lost for frame " << recv_window[i] << "\n";
                    cout << "Retransmitting frame " << recv_window[i] << "\n";
                    Sleep(1000);
                }
            }
        }

        // Slide the window if any frame was acknowledged
        if (window_slid)
        {
            int shift = 0;
            for (int i = 0; i < window_size; ++i)
            {
                if (recv_window[i] == -1)
                {
                    shift++;
                }
                else if (shift > 0)
                {
                    recv_window[i - shift] = recv_window[i];
                    recv_window[i] = -1;
                }
            }

            cout << "\n<--- Window slides --->\n\n";
        }
    }
}

int main()
{
    int num_frames, ws_bits;
    cout << "Sliding Window Protocols\n";
    cout << "Enter the number of frames: ";
    cin >> num_frames;
    cout << "Enter the number of bits for window size: ";
    cin >> ws_bits;

    int choice;
    while (true)
    {
        cout << "\n1. Go-Back-N\n2. Selective Repeat\n3. Exit\n";
        cin >> choice;
        if (choice == 1)
        {
            go_back_n(ws_bits, num_frames);
        }
        else if (choice == 2)
        {
            selective_repeat(ws_bits, num_frames);
        }
        else if (choice == 3)
        {
            exit(0);
        }
    }
}
