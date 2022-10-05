# Write your MySQL query statement below
select Person.firstName, person.lastName, address.city,address.state from Person  left outer join Address on Person.personId = Address.personId