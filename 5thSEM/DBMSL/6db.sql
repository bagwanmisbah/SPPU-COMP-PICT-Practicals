-- Assignment no. 6

create table new_emp( emp_id INT, emp_name VARCHAR(20), emp_dept VARCHAR(10), emp_salary INT, primary key( emp_id ) );
create table old_emp( emp_id INT, emp_name VARCHAR(20), emp_dept VARCHAR(10), emp_salary INT, primary key( emp_id ) );

insert into old_emp values
( 1 , 'p1' , 'Sales' , 10000 ) ,
( 2 , 'p2' , 'Dev' , 20000 ) ,
( 3 , 'p3' , 'Testing' , 50000 ) ,
( 4 , 'p4' , 'Sales' , 10000 ) ,
( 5 , 'p5' , 'Marketing' , 50000 ) ,
( 6 , 'p6' , 'Sales' , 9000 ) ,
( 7 , 'p7' , 'Accounts' , 10000 ) ,
( 8 , 'p8' , 'Sales' , 7000 ) ; 

insert into new_emp values ( 3 , 'p3' , 'Testing' , 50000 ) ,( 8 , 'p8' , 'Sales' , 7000 ) ; 

select * from old_emp;
select * from new_emp;

delimiter $$
create procedure copy_emp_data(in min_salary int, in max_salary int)
begin
	declare curr_emp_id INT;
	declare exit_loop BOOLEAN default 0;
	declare c CURSOR for select old_emp.emp_id from old_emp where old_emp.emp_salary between min_salary and max_salary; 
	declare continue handler for not found set exit_loop = 1;

	open c;
	while not exit_loop do
        -- Fetch the next employee ID into curr_emp_id
        fetch c into curr_emp_id;

        -- Check if the employee ID already exists in new_emp
        if not exit_loop and not exists (
            select new_emp.emp_id from new_emp where new_emp.emp_id = curr_emp_id
        ) then
            -- Insert the employee data into new_emp if it does not exist
            insert into new_emp (select * from old_emp where old_emp.emp_id = curr_emp_id );
        end if;
    end while;

    -- Close the cursor
    close c;

end
$$
delimiter ;

call copy_emp_data(10000, 20000);
select * from new_emp;



create table new_cust(
	cust_id INT,
	name VARCHAR(20),
	amt INT,
	primary key( cust_id )
);

create table old_cust(
	cust_id INT,
	name VARCHAR(20),
	amt INT,
	primary key( cust_id )
);

insert into old_cust values
( 1 , 'c1' , 10000 ) ,
( 2 , 'c2' ,  20000 ) ,
( 3 , 'c3' ,  5000 ) ,
( 4 , 'c4' ,  10000 ) ,
( 5 , 'c5' ,  50000 ) ,
( 6 , 'c6' ,  9000 ) ,
( 7 , 'c7' ,  10000 ) ,
( 8 , 'c8' ,  7000 ) ; 


insert into new_cust values ( 3 , 'c3' ,  5000 ) ,( 8 , 'c8' ,  7000 ) ; 


select * from old_cust;
select * from new_cust;

delimiter $$
create procedure copy_cust_data(in min_amt int, in max_amt int)
begin
	declare curr_cust_id INT;
	declare exit_loop BOOLEAN default 0;
	declare c CURSOR for select old_cust.cust_id from old_cust where old_cust.amt between min_amt and max_amt; 
	declare continue handler for not found set exit_loop = 1;

	open c;
	while not exit_loop do
        -- Fetch employee ID into curr_emp_id
        fetch c into curr_cust_id;

        
        if not exit_loop and not exists (
            select new_cust.cust_id from new_cust where new_cust.cust_id = curr_cust_id
        ) then
            
            insert into new_cust (select * from old_cust where old_cust.cust_id = curr_cust_id );
        end if;
    end while;

    close c;

end
$$
delimiter ;

call copy_cust_data(10000, 20000);
select * from new_cust;
