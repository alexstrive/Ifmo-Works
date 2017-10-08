SELECT NationalIDNumber
FROM HumanResources.Employee
WHERE (VacationHours + SickLeaveHours) > 100