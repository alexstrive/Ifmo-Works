SELECT EmployeeID
FROM HumanResources.Employee
WHERE BirthDate > ANY (
  SELECT BirthDate
  FROM HumanResources.Employee
  WHERE ContactID IN (
    SELECT ContactID
    FROM Person.Contact
    WHERE Phone IS NULL AND EmailAddress IS NULL
  )
)