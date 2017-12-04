-- Optimize sub-query

SELECT *
FROM HumanResources.Employee as CurrentEmployee
WHERE SickLeaveHours < (
  SELECT avg(SickLeaveHours)
  FROM HumanResources.Employee
  WHERE CurrentEmployee.Title = Title
)