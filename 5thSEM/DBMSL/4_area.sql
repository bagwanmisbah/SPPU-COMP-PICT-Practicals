create table area
(radius float,
areas float);

delimiter # 

create or replace procedure calc_area(in radius float)
begin
declare area float;

 if radius between 5 and 9 then
  set area=3.1415 * radius * radius;
  insert into area values(radius,area);
  select area," for radius",radius," inserted successfully" ;
 
 else
  signal sqlstate '45000'
  set message_text ="please enter a radius value between 5 and 9";
 
 end if;
 end;
 
#
call calc_area(5);
call calc_area(6);
call calc_area(7);
call calc_area(8);
call calc_area(9);
select * from area;
call calc_area(14);
----------------------------------------------------------------------------------------------------------------------------------------------------------------------

create table Borrower
(
roll int,
name varchar(50),
doi date,
bookname varchar(100),
status varchar(50)
);

create table Fine
(
rollno int,
rdate date,
amt float);
-- DELIMITER //


insert into Borrower values(55,"Misbah Bagwan",'2024-09-01',
"Harry Potter and the Prisoner of Azkaban","I");

insert into Borrower values(27,"Walter White",'2024-03-01',
"A Guide to Methilicious Chemistry","I");

insert into Borrower values(69,"Saul Goodman",'2024-08-21',
"Fact is:Walter White couldn't have done it without me","I");

insert into Borrower values(13,"Heisenberg",'2023-03-01',
"Say my Name","I");

insert into Borrower values(11,"Gustavo Fring",'2024-11-01',
"Selling Perfect Chicken","I");

insert into Borrower values(85,"Jessie Pinkman",'2024-10-04',
"Yo,Bitch i need to make a living","I");

insert into Borrower values(17,"Flynn White(jr)",'2024-10-28',
"Breaking breakfast","R");

insert into Borrower values(42,"Holly White",'2024-9-05',
"How to not get kidnapped by your own father","R");

DELIMITER //

CREATE OR REPLACE PROCEDURE calc_fine(IN roll_no INT, IN book_name VARCHAR(100))
BEGIN
    DECLARE days INT;
    DECLARE fine_amount FLOAT;
    DECLARE error INT DEFAULT 0;
    DECLARE issue_date DATE;

    -- Set error handler for foreign key violation (error code 1452)
    DECLARE EXIT HANDLER FOR 1452 
    BEGIN
        SET error = 1;
    END;

    -- Retrieve the issue date and current status for the specified roll number and book
    SELECT doi INTO issue_date 
    FROM Borrower 
    WHERE roll = roll_no AND bookname = book_name;

    -- Check if issue_date is NULL (indicating no such record was found)
    IF issue_date IS NULL THEN
        SET error = 1;
    ELSE
        -- Calculate the number of days since the issue date
        SET days = DATEDIFF(CURDATE(), issue_date);

        -- Determine fine based on the number of days overdue
        IF days >= 15 AND days <= 30 THEN
            SET fine_amount = 5 * days;
        ELSEIF days > 30 THEN
            SET fine_amount = 50 * days;
        ELSE
            SET fine_amount = 0;
        END IF;

        -- Only insert fine if there is a positive fine amount
        IF fine_amount > 0 THEN
            INSERT INTO Fine (rollno, rdate, amt) VALUES (roll_no, CURDATE(), fine_amount);
        END IF;

        -- Update the status in the Borrower table to 'R' for returned
        UPDATE Borrower SET status = 'R' 
        WHERE roll = roll_no AND bookname = book_name;
    END IF;

    -- Output message based on success or error
    IF error = 1 THEN
        SELECT 'Invalid Roll No or Book Name' AS message;
    ELSE
        SELECT 'Fine amount inserted in table' AS message;
    END IF;

END //

-- DELIMITER ;


select * from Borrower;
select * from Fine;
CALL calc_fine(55, "Harry Potter and the Prisoner of Azkaban");
CALL calc_fine(27, "A Guide to Methilicious Chemistry");
CALL calc_fine(69, "Fact is:Walter White couldn't have done it without me");
CALL calc_fine(13, "Say my Name");
CALL calc_fine(11, "Selling Perfect Chicken");
CALL calc_fine(85, "Yo,Bitch i need to make a living");
CALL calc_fine(17, "Breaking breakfast");
CALL calc_fine(85, "How to not get kidnapped by your own father");


select * from Borrower;
select * from Fine;
-----------------------------------------------------------------------------------------------------------------------------------------------------
Output:
+---------+-------------+--------+------------------------+
| area    | for radius  | radius | inserted successfully  |
+---------+-------------+--------+------------------------+
| 78.5375 |  for radius |      5 |  inserted successfully |
+---------+-------------+--------+------------------------+
+---------+-------------+--------+------------------------+
| area    | for radius  | radius | inserted successfully  |
+---------+-------------+--------+------------------------+
| 113.094 |  for radius |      6 |  inserted successfully |
+---------+-------------+--------+------------------------+
+---------+-------------+--------+------------------------+
| area    | for radius  | radius | inserted successfully  |
+---------+-------------+--------+------------------------+
| 153.934 |  for radius |      7 |  inserted successfully |
+---------+-------------+--------+------------------------+
+---------+-------------+--------+------------------------+
| area    | for radius  | radius | inserted successfully  |
+---------+-------------+--------+------------------------+
| 201.056 |  for radius |      8 |  inserted successfully |
+---------+-------------+--------+------------------------+
+---------+-------------+--------+------------------------+
| area    | for radius  | radius | inserted successfully  |
+---------+-------------+--------+------------------------+
| 254.462 |  for radius |      9 |  inserted successfully |
+---------+-------------+--------+------------------------+
+--------+---------+
| radius | areas   |
+--------+---------+
|      5 | 78.5375 |
|      6 | 113.094 |
|      7 | 153.934 |
|      8 | 201.056 |
|      9 | 254.462 |
+--------+---------+

ERROR 1644 (45000) at line 24: please enter a radius value between 5 and 9
-------------------------------------------------------------------------------------------------------------------------------------------------------------------

Output:
+------+-----------------+------------+-------------------------------------------------------+--------+
| roll | name            | doi        | bookname                                              | status |
+------+-----------------+------------+-------------------------------------------------------+--------+
|   55 | Misbah Bagwan   | 2024-09-01 | Harry Potter and the Prisoner of Azkaban              | I      |
|   27 | Walter White    | 2024-03-01 | A Guide to Methilicious Chemistry                     | I      |
|   69 | Saul Goodman    | 2024-08-21 | Fact is:Walter White couldn't have done it without me | I      |
|   13 | Heisenberg      | 2023-03-01 | Say my Name                                           | I      |
|   11 | Gustavo Fring   | 2024-11-01 | Selling Perfect Chicken                               | I      |
|   85 | Jessie Pinkman  | 2024-10-04 | Yo,***** i need to make a living                      | I      |
|   17 | Flynn White(jr) | 2024-10-28 | Breaking breakfast                                    | R      |
|   42 | Holly White     | 2024-09-05 | How to not get kidnapped by your own father           | R      |
+------+-----------------+------------+-------------------------------------------------------+--------+
+-----------------------------------+
| message                           |
+-----------------------------------+
| Fine amount inserted successfully |
+-----------------------------------+
+-----------------------------------+
| message                           |
+-----------------------------------+
| Fine amount inserted successfully |
+-----------------------------------+
+-----------------------------------+
| message                           |
+-----------------------------------+
| Fine amount inserted successfully |
+-----------------------------------+
+-----------------------------------+
| message                           |
+-----------------------------------+
| Fine amount inserted successfully |
+-----------------------------------+
+-----------------------------------+
| message                           |
+-----------------------------------+
| Fine amount inserted successfully |
+-----------------------------------+
+-----------------------------------+
| message                           |
+-----------------------------------+
| Fine amount inserted successfully |
+-----------------------------------+
+-----------------------------------+
| message                           |
+-----------------------------------+
| Fine amount inserted successfully |
+-----------------------------------+
+------------------------------+
| message                      |
+------------------------------+
| Invalid Roll No or Book Name |
+------------------------------+
+------+-----------------+------------+-------------------------------------------------------+--------+
| roll | name            | doi        | bookname                                              | status |
+------+-----------------+------------+-------------------------------------------------------+--------+
|   55 | Misbah Bagwan   | 2024-09-01 | Harry Potter and the Prisoner of Azkaban              | R      |
|   27 | Walter White    | 2024-03-01 | A Guide to Methilicious Chemistry                     | R      |
|   69 | Saul Goodman    | 2024-08-21 | Fact is:Walter White couldn't have done it without me | R      |
|   13 | Heisenberg      | 2023-03-01 | Say my Name                                           | R      |
|   11 | Gustavo Fring   | 2024-11-01 | Selling Perfect Chicken                               | R      |
|   85 | Jessie Pinkman  | 2024-10-04 | Yo,***** i need to make a living                      | R      |
|   17 | Flynn White(jr) | 2024-10-28 | Breaking breakfast                                    | R      |
|   42 | Holly White     | 2024-09-05 | How to not get kidnapped by your own father           | R      |
+------+-----------------+------------+-------------------------------------------------------+--------+
+--------+------------+-------+
| rollno | rdate      | amt   |
+--------+------------+-------+
|     55 | 2024-11-02 |  3100 |
|     27 | 2024-11-02 | 12300 |
|     69 | 2024-11-02 |  3650 |
|     13 | 2024-11-02 | 30600 |
|     85 | 2024-11-02 |   145 |
+--------+------------+-------+
+------------------------------+
| message                      |
+------------------------------+
| Invalid Roll No or Book Name |
+------------------------------+


