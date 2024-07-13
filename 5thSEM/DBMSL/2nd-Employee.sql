-------------------------------------------------------------------------------------------------------------------
/* Create the Dept1 table */
CREATE TABLE Dept1 (
Dept_id INT NOT NULL,
Dept_name VARCHAR(50),
Dept_location VARCHAR(50),
PRIMARY KEY (Dept_id)
);
/* Create the Employee1 table */
CREATE TABLE Employee1 (
Emp_id INT NOT NULL,
Dept_id INT,
Emp_fname VARCHAR(50),
Emp_lname VARCHAR(50),
Emp_position VARCHAR(50),
Emp_salary DECIMAL(10, 2),
Emp_JoinDate DATE,
PRIMARY KEY (Emp_id),
FOREIGN KEY (Dept_id) REFERENCES Dept1(Dept_id) ON DELETE CASCADE
);
/* Create the Project1 table */
CREATE TABLE Project1 (
Proj_id INT NOT NULL,
Dept_id INT,
Proj_Name VARCHAR(100),
Proj_Location VARCHAR(50),
Proj_cost DECIMAL(10, 2),
Proj_year DATE,
PRIMARY KEY (Proj_id),
FOREIGN KEY (Dept_id) REFERENCES Dept1(Dept_id) ON DELETE CASCADE
);
/* Insert into Dept1 table */
INSERT INTO Dept1 (Dept_id, Dept_name, Dept_location) VALUES
(20, 'IT', 'Mumbai'),
(25, 'Computer', 'Pune'),
(30, 'ENTC', 'Nashik');
/* Insert into Employee1 table */
INSERT INTO Employee1 VALUES
(100, 20, 'Misbah', 'Bagwan', 'Engineer', 25000.0, '2012-02-26'),
(101, 25, 'Raj', 'Sharma', 'Clerk', 15000.0, '1985-07-16'),
(102, 30, 'Manu', 'Kapoor', 'Receptionist', 10000.0, '2014-04-02'),
(103, 25, 'Sakshi', 'Dixit', 'HOD-IT', 80000.0, '2012-07-09'),
(104, 30, 'Rakhi', 'Nevase', 'Peon', 8000.0, '2013-08-04'),
(105, 20, 'Renuka', 'Dharmadhikari', 'Manager', 55000.0, '2011-09-03'),
(106, 25, 'Harsh', 'Devgan', 'Engineer', 35000.0, '2008-03-08'),
(107, 20, 'Priti', 'Yadav', 'CEO', 100000.0, '2006-12-07'),

(108, 25, 'Priya', 'Patil', 'Manager', 45000.0, '1981-11-05'),
(109, 30, 'Hari', 'Tiwari', 'Engineer', 30000.0, '1978-10-25');
/* Insert into Project1 table */
INSERT INTO Project1 VALUES
(200, 20, 'Project A', 'Mumbai', 120000.0, '2003-01-15'),
(201, 25, 'Project B', 'Pune', 80000.0, '2007-07-16'),
(202, 30, 'Project C', 'Nashik', 150000.0, '2004-04-02'),
(203, 20, 'Project D', 'Mumbai', 90000.0, '2007-07-09'),
(204, 25, 'Project E', 'Pune', 200000.0, '2021-08-04'),
(205, 30, 'Project F', 'Nashik', 300000.0, '2020-09-03'),
(206, 20, 'Project G', 'Mumbai', 180000.0, '2005-03-08'),
(207, 25, 'Project H', 'Pune', 250000.0, '2005-12-07'),
(208, 30, 'Project I', 'Nashik', 400000.0, '2004-11-05'),
(209, 20, 'Project J', 'Mumbai', 350000.0, '2007-10-25');
/* Select from Employee1 table */
SELECT e.Emp_id, e.Emp_fname, e.Emp_lname, e.Emp_position, e.Emp_salary, e.Emp_JoinDate,
d.Dept_name, d.Dept_location
FROM Employee1 e
JOIN Dept1 d ON e.Dept_id = d.Dept_id
WHERE d.Dept_name IN ('IT', 'Computer')
AND (e.Emp_fname LIKE 'P%' OR e.Emp_fname LIKE 'H%');
/* Count employees by position in Employee1 table */
SELECT Emp_position, COUNT(*) AS Num_Employees
FROM Employee1
GROUP BY Emp_position;
/* Update salary in Employee1 table */
UPDATE Employee1
SET Emp_salary = Emp_salary * 1.1
WHERE YEAR(Emp_JoinDate) < 1985;
/* Select employees joined before 1985 from Employee1 table */
SELECT * FROM Employee1 WHERE YEAR(Emp_JoinDate) < 1985;
/* Delete departments from Dept1 table where location is 'Mumbai' */
DELETE FROM Dept1
WHERE Dept_location = 'Mumbai';
/* Select all records from Dept1 table after deletion */
SELECT * FROM Dept1;
/* Select project names from Project1 table where location is 'Pune' */
SELECT Proj_Name
FROM Project1
WHERE Proj_Location = 'Pune';
/* Select projects from Project1 table with cost between 100000 and 500000 */
SELECT *
FROM Project1
WHERE Proj_cost >= 100000 AND Proj_cost <= 500000;
/* Select project with maximum cost from Project1 table */
SELECT *
FROM Project1

WHERE Proj_cost = (SELECT MAX(Proj_cost) FROM Project1);
/* Calculate average project cost in Project1 table */
SELECT AVG(Proj_cost) AS Avg_Project_Cost
FROM Project1;
/* Select employee ID and name from Employee1 table ordered by Emp_lname descending */
SELECT Emp_id, CONCAT(Emp_fname, ' ', Emp_lname) AS Emp_name
FROM Employee1
ORDER BY Emp_lname DESC;
/* Select project name, location, and cost from Project1 table where year is 2004, 2005, or 2007 */
SELECT Proj_Name, Proj_Location, Proj_cost
FROM Project1
WHERE YEAR(Proj_year) IN ('2004', '2005', '2007');

-- -- Create the Dept table
-- CREATE TABLE Dept (
-- Dept_id INT NOT NULL,
-- Dept_name VARCHAR(50),
-- Dept_location VARCHAR(50),
-- PRIMARY KEY (Dept_id)
-- );
-- -- Create the Employee table
-- CREATE TABLE Employee (
-- Emp_id INT NOT NULL,
-- Dept_id INT,
-- Emp_fname VARCHAR(50),
-- Emp_lname VARCHAR(50),
-- Emp_position VARCHAR(50),
-- Emp_salary DECIMAL(10, 2),
-- Emp_JoinDate DATE,
-- PRIMARY KEY (Emp_id),
-- FOREIGN KEY (Dept_id) REFERENCES Dept(Dept_id) ON DELETE CASCADE
-- );
-- -- Create the Project table
-- CREATE TABLE Project (
-- Proj_id INT NOT NULL,
-- Dept_id INT,
-- Proj_Name VARCHAR(100),
-- Proj_Location VARCHAR(50),
-- Proj_cost DECIMAL(10, 2),
-- Proj_year DATE,
-- PRIMARY KEY (Proj_id),
-- FOREIGN KEY (Dept_id) REFERENCES Dept(Dept_id) ON DELETE CASCADE
-- );
-- -- Insert into Dept table
-- INSERT INTO Dept (Dept_id, Dept_name, Dept_location) VALUES
-- (20, 'IT', 'Mumbai'),
-- (25, 'Computer', 'Pune'),
-- (30, 'ENTC', 'Nashik');
-- -- Insert into Employee table
-- INSERT INTO Employee VALUES
-- (100, 20, 'Misbah', 'Bagwan', 'Engineer', 25000.0, '2012-02-26'),
-- (101, 25, 'Raj', 'Sharma', 'Clerk', 15000.0, '1985-07-16'),
-- (102, 30, 'Manu', 'Kapoor', 'Receptionist', 10000.0, '2014-04-02'),
-- (103, 25, 'Sakshi', 'Dixit', 'HOD-IT', 80000.0, '2012-07-09'),
-- (104, 30, 'Rakhi', 'Nevase', 'Peon', 8000.0, '2013-08-04'),
-- (105, 20, 'Renuka', 'Dharmadhikari', 'Manager', 55000.0, '2011-09-03'),
-- (106, 25, 'Harsh', 'Devgan', 'Engineer', 35000.0, '2008-03-08'),
-- (107, 20, 'Priti', 'Yadav', 'CEO', 100000.0, '2006-12-07'),
-- (108, 25, 'Priya', 'Patil', 'Manager', 45000.0, '1981-11-05'),
-- (109, 30, 'Hari', 'Tiwari', 'Engineer', 30000.0, '1978-10-25');
-- -- Insert into Project table
-- INSERT INTO Project VALUES
-- (200, 20, 'Project A', 'Mumbai', 120000.0, '2003-01-15'),
-- (201, 25, 'Project B', 'Pune', 80000.0, '2007-07-16'),

-- (202, 30, 'Project C', 'Nashik', 150000.0, '2004-04-02'),
-- (203, 20, 'Project D', 'Mumbai', 90000.0, '2007-07-09'),
-- (204, 25, 'Project E', 'Pune', 200000.0, '2021-08-04'),
-- (205, 30, 'Project F', 'Nashik', 300000.0, '2020-09-03'),
-- (206, 20, 'Project G', 'Mumbai', 180000.0, '2005-03-08'),
-- (207, 25, 'Project H', 'Pune', 250000.0, '2005-12-07'),
-- (208, 30, 'Project I', 'Nashik', 400000.0, '2004-11-05'),
-- (209, 20, 'Project J', 'Mumbai', 350000.0, '2007-10-25');
-- SELECT e.Emp_id, e.Emp_fname, e.Emp_lname, e.Emp_position, e.Emp_salary, e.Emp_JoinDate,
-- d.Dept_name, d.Dept_location
-- FROM Employee e
-- JOIN Dept d ON e.Dept_id = d.Dept_id
-- WHERE d.Dept_name IN ('IT', 'Computer')
-- AND (e.Emp_fname LIKE 'P%' OR e.Emp_fname LIKE 'H%');
-- SELECT Emp_position, COUNT(*) AS Num_Employees
-- FROM Employee
-- GROUP BY Emp_position;
-- UPDATE Employee
-- SET Emp_salary = Emp_salary * 1.1
-- WHERE YEAR(Emp_JoinDate) < 1985;
-- DELETE FROM Dept
-- WHERE Dept_location = 'Mumbai';
-- --after deleting
-- select * from Dept;

-- SELECT Proj_Name
-- FROM Project
-- WHERE Proj_Location = 'Pune';
-- SELECT *
-- FROM Project
-- WHERE Proj_cost >=100000 AND Proj_cost<= 500000;
-- -- Find project with maximum price
-- SELECT *
-- FROM Project
-- WHERE Proj_cost = (SELECT MAX(Proj_cost) FROM Project);
-- -- Find average project cost
-- SELECT AVG(Proj_cost) AS Avg_Project_Cost
-- FROM Project;

-- --two ways
-- --with operator and function
-- SELECT Emp_id, CONCAT(Emp_fname, ' ', Emp_lname) AS Emp_name
-- FROM Employee
-- ORDER BY Emp_lname DESC;
-- SELECT Emp_id, Emp_fname + ' ' + Emp_lname AS Emp_name

-- FROM Employee
-- ORDER BY Emp_lname DESC;
-- SELECT Proj_Name, Proj_Location, Proj_cost
-- FROM Project
-- WHERE YEAR(Proj_year) IN ('2004', '2005', '2007');
