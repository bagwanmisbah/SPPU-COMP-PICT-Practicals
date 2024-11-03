
CREATE TABLE emp (
    id INT NOT NULL,
    name VARCHAR(50),
    salary DECIMAL(10, 2)
);


INSERT INTO emp (id, name, salary) VALUES
(1, 'Misbah Bagwan', 45000.00),
(2, 'Iqbal Bagwan', 55000.00),
(3, 'Shainaaz Bagwan', 65000.00),
(4, 'Awaiz Bagwan', 75000.00);


DELIMITER #


CREATE PROCEDURE increase_salaries()
BEGIN
    
    DECLARE empid INT;
    DECLARE empname VARCHAR(50);
    DECLARE empsal DECIMAL(10, 2);
    DECLARE done BOOLEAN DEFAULT FALSE;

    DECLARE empcur CURSOR FOR
        SELECT id, name, salary FROM emp;


    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    OPEN empcur;

    read_loop: LOOP
        FETCH empcur INTO empid, empname, empsal;

        IF done THEN
            LEAVE read_loop;
        END IF;

        UPDATE emp
        SET salary = empsal * 1.10
        WHERE id = empid;
    END LOOP;

    CLOSE empcur;
END #

DELIMITER ;

CALL increase_salaries();


