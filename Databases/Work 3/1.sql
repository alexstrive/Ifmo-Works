SELECT
  FirstName,
  LastName,
  Employee.Title,
  Phone
FROM HumanResources.Employee as Employee

  /* get phones */
  INNER JOIN Person.Contact as Contact
    ON Employee.ContactID = Contact.ContactID

/* show only peoples with phones */
WHERE Phone IS NOT NULL