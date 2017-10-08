SELECT
  Title,
  FirstName,
  LastName,
  MiddleName,
  Phone
FROM Person.Contact
WHERE Phone LIKE '%016%'