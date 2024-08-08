
mysql> use te31455_db
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
mysql> /*1. Find Employee details and Department details using NATURAL JOIN*/
SELECT *  FROM Employee2 NATURAL JOIN Dept2;
+---------+--------+-----------+-----------+--------------+------------+--------------+-----------+---------------+
| Dept_id | Emp_id | Emp_fname | Emp_lname | Emp_position | Emp_salary | Emp_JoinDate | Dept_name | Dept_location |
+---------+--------+-----------+-----------+--------------+------------+--------------+-----------+---------------+
|      25 |    101 | Raj       | Sharma    | Clerk        |   15000.00 | 1985-07-16   | Computer  | Pune          |
|      30 |    102 | Manu      | Kapoor    | Receptionist |   10000.00 | 2014-04-02   | ENTC      | Nashik        |
|      25 |    103 | Sakshi    | Dixit     | HOD-IT       |   80000.00 | 2012-07-09   | Computer  | Pune          |
|      30 |    104 | Rakhi     | Nevase    | Peon         |    8000.00 | 2013-08-04   | ENTC      | Nashik        |
|      25 |    106 | Harsh     | Devgan    | Engineer     |   35000.00 | 2008-03-08   | Computer  | Pune          |
|      25 |    108 | Priya     | Patil     | Manager      |   49500.00 | 1981-11-05   | Computer  | Pune          |
|      30 |    109 | Hari      | Tiwari    | Engineer     |   33000.00 | 1978-10-25   | ENTC      | Nashik        |
+---------+--------+-----------+-----------+--------------+------------+--------------+-----------+---------------+
7 rows in set (0.00 sec)

mysql> /*2. Find the emp_fname,Emp_position,location,Emp_JoinDate who have same Dept id. */
SELECT e.Emp_fname, e.Emp_position, d.dept_location, e.Emp_JoinDate  FROM Employee2 e  INNER JOIN Dept2 d ON e.Dept_id = d.Dept_id;
+-----------+--------------+---------------+--------------+
| Emp_fname | Emp_position | dept_location | Emp_JoinDate |
+-----------+--------------+---------------+--------------+
| Raj       | Clerk        | Pune          | 1985-07-16   |
| Manu      | Receptionist | Nashik        | 2014-04-02   |
| Sakshi    | HOD-IT       | Pune          | 2012-07-09   |
| Rakhi     | Peon         | Nashik        | 2013-08-04   |
| Harsh     | Engineer     | Pune          | 2008-03-08   |
| Priya     | Manager      | Pune          | 1981-11-05   |
| Hari      | Engineer     | Nashik        | 1978-10-25   |
+-----------+--------------+---------------+--------------+
7 rows in set (0.00 sec)

mysql> /*3. Find the Employee details ,Proj_id,Project cost who does not have Project
location as ‘Hyderabad’.*/SELECT e.*, p.Proj_id, p.Proj_cost
    -> FROM Employee2 e 
    -> JOIN Project2 p ON e.Dept_id = p.Dept_id
    -> WHERE p.Proj_Location <> 'Hyderabad';
+--------+---------+-----------+-----------+--------------+------------+--------------+---------+-----------+
| Emp_id | Dept_id | Emp_fname | Emp_lname | Emp_position | Emp_salary | Emp_JoinDate | Proj_id | Proj_cost |
+--------+---------+-----------+-----------+--------------+------------+--------------+---------+-----------+
|    101 |      25 | Raj       | Sharma    | Clerk        |   15000.00 | 1985-07-16   |     201 |  80000.00 |
|    101 |      25 | Raj       | Sharma    | Clerk        |   15000.00 | 1985-07-16   |     204 | 200000.00 |
|    101 |      25 | Raj       | Sharma    | Clerk        |   15000.00 | 1985-07-16   |     207 | 250000.00 |
|    102 |      30 | Manu      | Kapoor    | Receptionist |   10000.00 | 2014-04-02   |     202 | 150000.00 |
|    102 |      30 | Manu      | Kapoor    | Receptionist |   10000.00 | 2014-04-02   |     205 | 300000.00 |
|    102 |      30 | Manu      | Kapoor    | Receptionist |   10000.00 | 2014-04-02   |     208 | 400000.00 |
|    103 |      25 | Sakshi    | Dixit     | HOD-IT       |   80000.00 | 2012-07-09   |     201 |  80000.00 |
|    103 |      25 | Sakshi    | Dixit     | HOD-IT       |   80000.00 | 2012-07-09   |     204 | 200000.00 |
|    103 |      25 | Sakshi    | Dixit     | HOD-IT       |   80000.00 | 2012-07-09   |     207 | 250000.00 |
|    104 |      30 | Rakhi     | Nevase    | Peon         |    8000.00 | 2013-08-04   |     202 | 150000.00 |
|    104 |      30 | Rakhi     | Nevase    | Peon         |    8000.00 | 2013-08-04   |     205 | 300000.00 |
|    104 |      30 | Rakhi     | Nevase    | Peon         |    8000.00 | 2013-08-04   |     208 | 400000.00 |
|    106 |      25 | Harsh     | Devgan    | Engineer     |   35000.00 | 2008-03-08   |     201 |  80000.00 |
|    106 |      25 | Harsh     | Devgan    | Engineer     |   35000.00 | 2008-03-08   |     204 | 200000.00 |
|    106 |      25 | Harsh     | Devgan    | Engineer     |   35000.00 | 2008-03-08   |     207 | 250000.00 |
|    108 |      25 | Priya     | Patil     | Manager      |   49500.00 | 1981-11-05   |     201 |  80000.00 |
|    108 |      25 | Priya     | Patil     | Manager      |   49500.00 | 1981-11-05   |     204 | 200000.00 |
|    108 |      25 | Priya     | Patil     | Manager      |   49500.00 | 1981-11-05   |     207 | 250000.00 |
|    109 |      30 | Hari      | Tiwari    | Engineer     |   33000.00 | 1978-10-25   |     202 | 150000.00 |
|    109 |      30 | Hari      | Tiwari    | Engineer     |   33000.00 | 1978-10-25   |     205 | 300000.00 |
|    109 |      30 | Hari      | Tiwari    | Engineer     |   33000.00 | 1978-10-25   |     208 | 400000.00 |
+--------+---------+-----------+-----------+--------------+------------+--------------+---------+-----------+
21 rows in set (0.01 sec)

mysql> /*4. Find Department Name ,employee name, Emp_position for which project year
 is 2020,*/
SELECT d.Dept_name, e.Emp_fname, e.Emp_lname, e.Emp_position
    -> FROM Employee2 e
    -> JOIN Dept2 d ON e.Dept_id = d.Dept_id
    -> JOIN Project2 p ON d.Dept_id = p.Dept_id
    -> WHERE YEAR(p.Proj_year) = 2020;
+-----------+-----------+-----------+--------------+
| Dept_name | Emp_fname | Emp_lname | Emp_position |
+-----------+-----------+-----------+--------------+
| ENTC      | Manu      | Kapoor    | Receptionist |
| ENTC      | Rakhi     | Nevase    | Peon         |
| ENTC      | Hari      | Tiwari    | Engineer     |
+-----------+-----------+-----------+--------------+
3 rows in set (0.01 sec)

mysql> /*5. Display emp_position,D_name who have Project cost >30000*/
SELECT e.Emp_position, d.Dept_name
    -> FROM Employee2 e
    -> JOIN Dept2 d ON e.Dept_id = d.Dept_id
    -> JOIN Project2 p ON d.Dept_id = p.Dept_id
    -> WHERE p.Proj_cost > 30000;
+--------------+-----------+
| Emp_position | Dept_name |
+--------------+-----------+
| Clerk        | Computer  |
| Clerk        | Computer  |
| Clerk        | Computer  |
| Receptionist | ENTC      |
| Receptionist | ENTC      |
| Receptionist | ENTC      |
| HOD-IT       | Computer  |
| HOD-IT       | Computer  |
| HOD-IT       | Computer  |
| Peon         | ENTC      |
| Peon         | ENTC      |
| Peon         | ENTC      |
| Engineer     | Computer  |
| Engineer     | Computer  |
| Engineer     | Computer  |
| Manager      | Computer  |
| Manager      | Computer  |
| Manager      | Computer  |
| Engineer     | ENTC      |
| Engineer     | ENTC      |
| Engineer     | ENTC      |
+--------------+-----------+
21 rows in set (0.00 sec)

mysql> /*6. Find the names of all the Projects that started in the year 2015.*/
SELECT Proj_Name
    -> FROM Project2
    -> WHERE YEAR(Proj_year) = 2015;
+-----------+
| Proj_Name |
+-----------+
| Project K |
| Project L |
| Project M |
| Project N |
| Project O |
+-----------+
5 rows in set (0.00 sec)

mysql> /*7. List the Dept_name having no_of_emp=10*/
SELECT d.Dept_name
    -> FROM dept3 d
    -> JOIN emp3 e ON d.Dept_id = e.Dept_id
    -> GROUP BY d.Dept_id, d.Dept_name
    -> HAVING COUNT(e.Emp_id) = 10;
+-----------+
| Dept_name |
+-----------+
| IT        |
+-----------+
1 row in set (0.00 sec)

mysql> /*8.Display the total number of employee who have joined any project before 2009*/
SELECT COUNT(DISTINCT e.Emp_id) AS total_employees
    -> FROM Employee2 e
    -> JOIN Project2 p ON e.Dept_id = p.Dept_id
    -> WHERE YEAR(p.Proj_year) < 2009;
+-----------------+
| total_employees |
+-----------------+
|              23 |
+-----------------+
1 row in set (0.00 sec)

mysql> /*9. Create a view showing the employee and Department details. */
SELECT COUNT(DISTINCT e.Emp_id) AS total_employees
    -> FROM Employee2 e
    -> JOIN Project2 p ON e.Dept_id = p.Dept_id
    -> WHERE YEAR(p.Proj_year) < 2009;
+-----------------+
| total_employees |
+-----------------+
|              23 |
+-----------------+
1 row in set (0.00 sec)

mysql> /*10. Perform Manipulation on simple view-Insert, update, delete, drop view. */
CREATE VIEW empdeptview3 AS
    -> SELECT 
    ->     e.Emp_id,
    ->     e.Emp_fname,
    ->     e.Emp_lname,
    ->     e.Emp_Position,
    ->     e.Emp_salary,
    ->     e.Emp_JoinDate,
    ->     d.Dept_id,
    ->     d.Dept_name,
    ->     d.Dept_location
    -> FROM 
    ->     Employee2 e
    -> JOIN 
    ->     Dept2 d ON e.Dept_id = d.Dept_id;
Query OK, 0 rows affected (0.03 sec)

mysql> INSERT INTO Employee2 (Emp_id, Dept_id, Emp_fname, Emp_lname, Emp_Position, Emp_salary, Emp_JoinDate) VALUES 
    ->     (130, 25, 'Zara', 'Khan', 'Engineer', 26000.0, '2020-01-01');
Query OK, 1 row affected (0.02 sec)

mysql> UPDATE Employee2
    -> SET Emp_salary = Emp_salary + 1000
    -> WHERE Emp_id = 130;
Query OK, 1 row affected (0.04 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> DELETE FROM Employee2
    -> WHERE Emp_id = 130;
Query OK, 1 row affected (0.03 sec)

mysql> DROP VIEW EmployeeDeptView2;
Query OK, 0 rows affected (0.00 sec)

mysql> 


