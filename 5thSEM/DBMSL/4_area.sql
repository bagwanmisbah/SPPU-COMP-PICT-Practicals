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

