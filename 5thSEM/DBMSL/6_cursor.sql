create table o_emp
(
emp_id int ,
emp_name varchar(45)
);

insert into o_emp values(1,"Misbah");
insert into o_emp values(2,"rita");
insert into o_emp values(3,"gita");
insert into o_emp values(4,"mita");
insert into o_emp values(5,"papita");
insert into o_emp values(2,"bonita");
insert into o_emp values(2,"babita");
insert into o_emp values(5,"papita");
insert into o_emp values(3,"gita");



create table n_emp
(
emp_id int primary key,
emp_name varchar(45)
); 

select * from o_emp;


delimiter //
create procedure merge_emp()
begin
	declare done int default false;
	declare name varchar(45);
	declare id int;

	declare cur cursor for select emp_id,emp_name from o_emp;

	declare continue handler for not found set done=TRUE;

	open cur;
 	while not done do
		fetch cur into id,name;
		if not exists(select * from n_emp where emp_id=id)then
		insert into n_emp values(id,name);

		end if;

	end while;

	close cur;
end;

//
delimiter ;



call merge_emp();

select * from n_emp;



Output:

+--------+----------+
| emp_id | emp_name |
+--------+----------+
|      1 | Misbah   |
|      2 | rita     |
|      3 | gita     |
|      4 | mita     |
|      5 | papita   |
|      2 | bonita   |
|      2 | babita   |
|      5 | papita   |
|      3 | gita     |
+--------+----------+
+--------+----------+
| emp_id | emp_name |
+--------+----------+
|      1 | Misbah   |
|      2 | rita     |
|      3 | gita     |
|      4 | mita     |
|      5 | papita   |
+--------+----------+













