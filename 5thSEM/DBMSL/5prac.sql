
CREATE TABLE stud_marks (
    rollno INT NOT NULL AUTO_INCREMENT,
    name VARCHAR(50),
    marks INT,
    PRIMARY KEY(rollno)
);


INSERT INTO stud_marks(name, marks) VALUES ("Misbah Bagwan", 1150);
INSERT INTO stud_marks(name, marks) VALUES ("Iqbal Noormhommad", 1500);
INSERT INTO stud_marks(name, marks) VALUES ("Mariyam", 910);
INSERT INTO stud_marks(name, marks) VALUES ("Shainaaz", 1400);
INSERT INTO stud_marks(name, marks) VALUES ("Sabiha", 995);
INSERT INTO stud_marks(name, marks) VALUES ("Sajeeda", 870);
INSERT INTO stud_marks(name, marks) VALUES ("Aashna", 925);
INSERT INTO stud_marks(name, marks) VALUES ("Awaiz", 850);
INSERT INTO stud_marks(name, marks) VALUES ("Saira", 835);
INSERT INTO stud_marks(name, marks) VALUES ("Faisal", 1200);
INSERT INTO stud_marks(name, marks) VALUES ("Amina", 1250);
INSERT INTO stud_marks(name, marks) VALUES ("Saleema", 850);
INSERT INTO stud_marks(name, marks) VALUES ("Abdul Rehman", 1345);


SELECT * FROM stud_marks;


CREATE TABLE result (
    rollno INT,
    studname VARCHAR(50),
    class VARCHAR(50),
    FOREIGN KEY(rollno) REFERENCES stud_marks(rollno) ON DELETE CASCADE
);


DELIMITER #


CREATE FUNCTION proc_Grade(r INT) RETURNS VARCHAR(30)
BEGIN
    DECLARE sclass VARCHAR(30);
    DECLARE m INT;
    DECLARE n VARCHAR(50);

    
    SELECT name, marks INTO n, m FROM stud_marks WHERE rollno = r;

    
    IF m BETWEEN 990 AND 1500 THEN
        SET sclass = "DISTINCTION";
    ELSEIF m BETWEEN 900 AND 989 THEN
        SET sclass = "FIRST CLASS";
    ELSEIF m BETWEEN 825 AND 899 THEN
        SET sclass = "HIGHER SECOND CLASS";
    ELSE
        SET sclass = "Fail";
    END IF;

    
    CALL insert_result(r, n, sclass);
    
    RETURN sclass;
END #


CREATE PROCEDURE insert_result(IN r INT, IN n VARCHAR(50), IN c VARCHAR(30))
BEGIN
    INSERT INTO result VALUES (r, n, c);
END #


DELIMITER ;



-- SELECT proc_Grade(1);  
-- SELECT proc_Grade(2);  
-- SELECT proc_Grade(3);  
-- SELECT proc_Grade(4);  
-- SELECT proc_Grade(5);  

DELIMITER //
create procedure call_all()
BEGIN
DECLARE i int default 1;
declare end int default 13;

while i<=end do
select proc_Grade(i);
set i=i+1;
end while;
END //
delimiter ;
call call_all;



SELECT * FROM result;




+--------+-------------------+-------+
| rollno | name              | marks |
+--------+-------------------+-------+
|      1 | Misbah Bagwan     |  1150 |
|      2 | Iqbal Noormhommad |  1500 |
|      3 | Mariyam           |   910 |
|      4 | Shainaaz          |  1400 |
|      5 | Sabiha            |   995 |
|      6 | Sajeeda           |   870 |
|      7 | Aashna            |   925 |
|      8 | Awaiz             |   850 |
|      9 | Saira             |   835 |
|     10 | Faisal            |  1200 |
|     11 | Amina             |  1250 |
|     12 | Saleema           |   850 |
|     13 | Abdul Rehman      |  1345 |
+--------+-------------------+-------+
+---------------+
| proc_Grade(i) |
+---------------+
| DISTINCTION   |
+---------------+
+---------------+
| proc_Grade(i) |
+---------------+
| DISTINCTION   |
+---------------+
+---------------+
| proc_Grade(i) |
+---------------+
| FIRST CLASS   |
+---------------+
+---------------+
| proc_Grade(i) |
+---------------+
| DISTINCTION   |
+---------------+
+---------------+
| proc_Grade(i) |
+---------------+
| DISTINCTION   |
+---------------+
+---------------------+
| proc_Grade(i)       |
+---------------------+
| HIGHER SECOND CLASS |
+---------------------+
+---------------+
| proc_Grade(i) |
+---------------+
| FIRST CLASS   |
+---------------+
+---------------------+
| proc_Grade(i)       |
+---------------------+
| HIGHER SECOND CLASS |
+---------------------+
+---------------------+
| proc_Grade(i)       |
+---------------------+
| HIGHER SECOND CLASS |
+---------------------+
+---------------+
| proc_Grade(i) |
+---------------+
| DISTINCTION   |
+---------------+
+---------------+
| proc_Grade(i) |
+---------------+
| DISTINCTION   |
+---------------+
+---------------------+
| proc_Grade(i)       |
+---------------------+
| HIGHER SECOND CLASS |
+---------------------+
+---------------+
| proc_Grade(i) |
+---------------+
| DISTINCTION   |
+---------------+
+--------+-------------------+---------------------+
| rollno | studname          | class               |
+--------+-------------------+---------------------+
|      1 | Misbah Bagwan     | DISTINCTION         |
|      2 | Iqbal Noormhommad | DISTINCTION         |
|      3 | Mariyam           | FIRST CLASS         |
|      4 | Shainaaz          | DISTINCTION         |
|      5 | Sabiha            | DISTINCTION         |
|      6 | Sajeeda           | HIGHER SECOND CLASS |
|      7 | Aashna            | FIRST CLASS         |
|      8 | Awaiz             | HIGHER SECOND CLASS |
|      9 | Saira             | HIGHER SECOND CLASS |
|     10 | Faisal            | DISTINCTION         |
|     11 | Amina             | DISTINCTION         |
|     12 | Saleema           | HIGHER SECOND CLASS |
|     13 | Abdul Rehman      | DISTINCTION         |
+--------+-------------------+---------------------+

