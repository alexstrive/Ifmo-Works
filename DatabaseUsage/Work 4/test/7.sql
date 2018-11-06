SELECT
  BossContact.FirstName,
  BossContact.LastName,
  BossContact.MiddleName,
  'boss for',
  EmployeeContact.FirstName,
  EmployeeContact.LastName,
  EmployeeContact.MiddleName

FROM HumanResources.Employee AS Boss

  JOIN HumanResources.Employee AS Employee
    ON Boss.EmployeeID = Employee.ManagerID

  JOIN Person.Contact AS BossContact
    ON Boss.ContactID = BossContact.ContactID

  JOIN Person.Contact AS EmployeeContact
    ON Employee.ContactID = EmployeeContact.ContactID

WHERE
  Boss.Gender = 'M' AND Employee.Gender = 'F'