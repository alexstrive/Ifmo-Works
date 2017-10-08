SELECT COUNT(*)
FROM HumanResources.Employee AS Employee

  /* get emails */
  INNER JOIN Person.Contact AS Contact
    ON Employee.ContactID = Contact.ContactID

/* search for peoples with emails */
WHERE EmailAddress IS NOT NULL