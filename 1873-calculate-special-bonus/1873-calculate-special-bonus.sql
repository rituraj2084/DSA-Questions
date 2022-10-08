# Write your MySQL query statement below
# select employee_id, salary as bonus from Employees 
# where (mod(employee_id, 2) != 0) and name not like 'M%'
# union
# select employee_id, 0 as bonus from Employees 
# where (mod(employee_id, 2) = 0) and name like 'M%'
# order by employee_id

select employee_id,
case when employee_id%2 !=0 and name not like 'M%' then salary
else 0
end
as bonus
from Employees
order by employee_id


# select employee_id , 
#    case when employee_id%2 <>0 and name not like 'M%' then salary 
#    else 0
#    end 
#    as bonus
#    from employees
#    order by employee_id;