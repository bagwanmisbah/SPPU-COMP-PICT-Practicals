/**
 *
 */
/**
 *
 */
import java.sql.*;
import java.util.*;
class Dbms_assgn8 {
void insert(Statement st) throws SQLException{
String ename="";
   Scanner sc=new Scanner(System.in);
   System.out.println("Enter STOP to stop insertion");
   String query;
   while(true){
    System.out.println("Enter student name to insert into table: ");
    ename = sc.next();
   if(ename.equals("STOP")) {
    break;
   }
   query = "Insert into stud(s_name) values('"+ename+"')";
   st.executeUpdate(query);
   }
   System.out.println("Records inserted successfully!");
}
void delete(Statement st) throws SQLException{
Scanner sc=new Scanner(System.in);
String col;
   String val;
   System.out.println("Enter column name for deletion: ");
   col=sc.next();
   System.out.println("Enter "+col+ " to delete record from table: ");
   val=sc.next();
   String query = "delete from stud where "+col+"= '"+val+"' ";
   st.executeUpdate(query);
   System.out.println("Records deleted successfully!");
   
}
void update(Statement st) throws SQLException{
Scanner sc=new Scanner(System.in);
String col;
   String val;
   String id;
   System.out.println("Enter s_id of record to be updated: ");
   id=sc.next();
   System.out.println("Enter column name for updation: ");
   col=sc.next();
   System.out.println("Enter new "+col+ " to update record from table: ");
   val=sc.next();
   String query = "update stud set "+col+"= '"+val+"' where s_id="+id;
   st.executeUpdate(query);
   System.out.println("Records updated successfully!");
}
void fetch(Statement st) throws SQLException{
ResultSet rs;
String query="select * from stud";
System.out.println("Contents of table are as follows: ");
   rs = st.executeQuery(query); // Execute query
   while(rs.next()) {
    System.out.println("id: " + rs.getInt("s_id") + " Name: " + rs.getString("s_name"));
   }
   rs.close();
}
public static void main(String args[]) {
try {
Class.forName("com.mysql.cj.jdbc.Driver"); // Driver name
Scanner sc = new Scanner(System.in);
String url = "jdbc:mysql://10.10.13.97/te31455_db"; // table details
   String username = "te31455"; // MySQL credentials
   String password = "te31455";
   Connection con = DriverManager.getConnection(url, username, password);
   System.out.println("Connection Established successfully");
   Statement st = con.createStatement();
 
   
   String query= "Create table stud(s_id int auto_increment,s_name varchar(30),primary key(s_id))";
//    ResultSet rs;
   st.executeUpdate(query);
   
   Dbms_assgn8 obj=new Dbms_assgn8();
   
   obj.insert(st);
   
   obj.fetch(st);
   
   int choice;
   char ans='n';
   while(ans=='n') {
    System.out.println("Menu\n 1. Fetch records\n 2. Insert records\n 3. Delete records\n 4. Update records\n 5. Exit");
   System.out.println("Enter choice: ");
   choice=sc.nextInt();
   switch(choice) {
   case 1:
    obj.fetch(st);
    break;
   case 2:
    obj.insert(st);
    break;
   case 3:
    obj.delete(st);
    break;
   case 4:
    obj.update(st);
    break;
   case 5:
    ans='y';
    break;
   }
   
   
   }
   
   query="drop table stud";
   st.executeUpdate(query);
   
//    rs.close();
   st.close(); // close statement
   con.close(); // close connection
   System.out.println("Connection Closed....");

}catch(Exception e) {
e.printStackTrace();
}

}

}
