SELECT
  Gender,
  Sum(SickLeaveHours)
FROM HumanResources.Employee
GROUP BY Gender