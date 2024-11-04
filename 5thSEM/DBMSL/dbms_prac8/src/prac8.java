
// --------------------------------------------------------------------------------------------
import java.sql.*;
import java.util.*;

class prac8 {
    void insert(Statement st) throws SQLException {
        String ename = "";
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter stop to stop insertion");
        String query;
        while (true) {
            System.out.println("Enter Student Name to insert into table: ");
            ename = sc.next();
            if (ename.equals("stop")) {
                break;
            }
            query = "Insert into stud(s_name) values('" + ename + "')";
            st.executeUpdate(query);
        }
        System.out.println("Records inserted successfully!");
    }

    void delete(Statement st) throws SQLException {
        Scanner sc = new Scanner(System.in);
        String col, val;
        System.out.println("Enter column name for deletion: ");
        col = sc.next();
        System.out.println("Enter " + col + "to delete record from table: ");
        val = sc.next();
        String query = "delete from stud where " + col + "=' " + val + " ' ";
        st.executeUpdate(query);
        System.out.println("Record deleted successfully");

    }

    void update(Statement st) throws SQLException {
        Scanner sc = new Scanner(System.in);
        String col, val, id;
        System.out.println("Enter s_id of record to be updated: ");
        id = sc.next();
        System.out.print("Enter column value for updation: ");
        col = sc.next();
        System.out.println("Enter new " + col + " to update record from table:");
        val = sc.next();
        String query = "update stud set " + col + "=' " + val + " ' where s_id =" +
                id;
        st.executeUpdate(query);
        System.out.println("Records updated successfully");
    }

    void fetch(Statement st) throws SQLException {
        ResultSet rs;
        String query = "select * from stud";
        System.out.println("Contents of Table stud are follows: ");
        rs = st.executeQuery(query);
        while (rs.next()) {
            System.out.println("id: " + rs.getInt("s_id") + "Name:" +
                    rs.getString("s_name"));
        }
        rs.close();
    }

    public static void main(String args[]) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Scanner sc = new Scanner(System.in);
            // String url = "jdbc:mysql://10.10.13.97/te31455_db"; // table details
            // String username = "te31455"; // MySQL credentials
            // String password = "te31455";

            String url = "jdbc:mysql://localhost:3306/misbah_db";
            String username = "root";
            String pw = "mishu@777";

            Connection con = DriverManager.getConnection(url, username, pw);
            System.out.println("Connection estabilished ");
            Statement st = con.createStatement();
            String query = " create table stud( s_id int auto_increment,s_name varchar(50), primary key(s_id))";
            st.executeUpdate(query);
            prac8 obj = new prac8();
            obj.insert(st);
            obj.fetch(st);

            Integer choice;
            char ans = 'n';
            while (ans == 'n') {
                System.out.println(
                        "Menu \n 1.Fetch records \n 2.Insert records \n3.Delete records \n 4.Update records \n 5.Exit");
                System.out.println("Enter choice: ");
                choice = sc.nextInt();
                switch (choice) {
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
                        ans = 'y';
                        break;
                }
            }
            query = "drop table stud";
            st.executeUpdate(query);

            st.close();
            con.close();
            System.out.println("Connection closed ");
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}

// public class App
// {
// public static void main(String[] args) throws Exception {
// System.out.println("Hello, World!");
// }
// }
