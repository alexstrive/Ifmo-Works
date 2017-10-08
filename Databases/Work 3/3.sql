SELECT
  FirstName,
  LastName,
  EmailAddress
/* get vendor agent of company*/
FROM Purchasing.VendorContact AS VendorContact

  /* get name of agent */
  INNER JOIN Person.Contact AS Contact
    ON VendorContact.ContactID = Contact.ContactID

  /* get name of company */
  INNER JOIN Purchasing.Vendor AS Vendor
    ON VendorContact.VendorID = Vendor.VendorID

/* order by company name*/
ORDER BY Name