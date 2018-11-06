SELECT
  FirstName,
  LastName,
  Name
FROM Purchasing.VendorContact AS VendorContact

  /* get job title of agent */
  JOIN Person.ContactType AS ContactType
    ON VendorContact.ContactTypeID = ContactType.ContactTypeID

  /* get first name and last name of agent */
  JOIN Person.Contact AS Contact
    ON VendorContact.ContactID = Contact.ContactID