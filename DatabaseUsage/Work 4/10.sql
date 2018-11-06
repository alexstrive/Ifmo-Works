SELECT DISTINCT Boss.EmployeeID
FROM HumanResources.Employee AS Boss

  JOIN HumanResources.Employee AS Employee
    ON Boss.EmployeeID = Employee.ManagerID

WHERE
  Boss.MaritalStatus = 'S' AND
  Employee.MaritalStatus = 'S' AND
  Boss.Gender <> Employee.Gender