download jar files from : https://dev.mysql.com/downloads/connector/j/
in lib folder: copy jar file 
ctrl+shift+p : type java:configure classpath
go to edit workspace or simply add in libraries jar file in Project Settings 

![image](https://github.com/user-attachments/assets/7e98bd1d-d892-4ddb-b1f4-bfd22e9ecffb)


Connection estabilished 
Enter stop to stop insertion
Enter Student Name to insert into table: 
misbah
Enter Student Name to insert into table: 
awaiz
Enter Student Name to insert into table: 
iqbal
Enter Student Name to insert into table: 
shainaaz
Enter Student Name to insert into table: 
xyz
Enter Student Name to insert into table: 
abc
Enter Student Name to insert into table: 
stop
Records inserted successfully!      
Contents of Table stud are follows: 
id: 1Name:misbah
id: 2Name:awaiz
id: 3Name:iqbal
id: 4Name:shainaaz
id: 5Name:xyz
id: 6Name:abc
Menu
 1.Fetch records
 2.Insert records
3.Delete records
 4.Update records
 5.Exit
Enter choice:
1
Contents of Table stud are follows: 
id: 1Name:misbah
id: 2Name:awaiz
id: 3Name:iqbal
id: 4Name:shainaaz
id: 5Name:xyz
id: 6Name:abc
Menu
 1.Fetch records
 2.Insert records
3.Delete records
 4.Update records
 5.Exit
Enter choice:
2
Enter stop to stop insertion
Enter Student Name to insert into table:
batata_tamata
Enter Student Name to insert into table:
stop
Records inserted successfully!
Menu
 1.Fetch records
 2.Insert records
3.Delete records
 4.Update records
 5.Exit
Enter choice:
3
Enter column name for deletion: 
s_name
Enter s_nameto delete record from table: 
batata_tamata
Record deleted successfully
Menu
 1.Fetch records
 2.Insert records
3.Delete records
 4.Update records
 5.Exit
Enter choice:
1
Contents of Table stud are follows: 
id: 1Name:misbah
id: 2Name:awaiz
id: 3Name:iqbal
id: 4Name:shainaaz
id: 5Name:xyz
id: 6Name:abc
id: 7Name:batata_tamata
Menu
 1.Fetch records
 2.Insert records
3.Delete records
 4.Update records
 5.Exit
Enter choice:
4
Enter s_id of record to be updated: 
7
Enter column value for updation: s_name
Enter new s_name to update record from table:
batata
Records updated successfully
Menu 
 1.Fetch records
 2.Insert records
3.Delete records
 4.Update records
 5.Exit
Enter choice:
1
Contents of Table stud are follows: 
id: 1Name:misbah
id: 2Name:awaiz
id: 3Name:iqbal
id: 4Name:shainaaz
id: 5Name:xyz
id: 6Name:abc
id: 7Name: batata
Menu
 1.Fetch records
 2.Insert records
3.Delete records
 4.Update records
 5.Exit
Enter choice:
3
Enter column name for deletion: 
s_id  
Enter s_idto delete record from table: 
7
Record deleted successfully
Menu
 1.Fetch records
 2.Insert records
3.Delete records
 4.Update records
 5.Exit
Enter choice:
1
Contents of Table stud are follows: 
id: 1Name:misbah
id: 2Name:awaiz
id: 3Name:iqbal
id: 4Name:shainaaz
id: 5Name:xyz
id: 6Name:abc
Menu
 1.Fetch records
 2.Insert records
3.Delete records
 4.Update records
 5.Exit
Enter choice:


--------------------------------------------------------------------------------------------------

## Getting Started

Welcome to the VS Code Java world. Here is a guideline to help you get started to write Java code in Visual Studio Code.

## Folder Structure

The workspace contains two folders by default, where:

- `src`: the folder to maintain sources
- `lib`: the folder to maintain dependencies

Meanwhile, the compiled output files will be generated in the `bin` folder by default.

> If you want to customize the folder structure, open `.vscode/settings.json` and update the related settings there.

## Dependency Management

The `JAVA PROJECTS` view allows you to manage your dependencies. More details can be found [here](https://github.com/microsoft/vscode-java-dependency#manage-dependencies).
