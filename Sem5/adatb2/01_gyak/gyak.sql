select * from user_objects;
select * from all_objects;
select * from dba_objects;

select count(*) from all_objects;
select count(*) from dba_objects;

create table x (a number);

select max(data_object_id) from all_objects;

SELECT COUNT(DISTINCT object_type) FROM all_objects;

-- If the name is between quotes anything can be the name
create table "a b" (x int);

-- Dual has a single row
select 1+1 from dual;

select * from dba_objects where object_name='DUAL';