SELECT FirstName, MiddleName, LastName
FROM Person.Contact
WHERE 1 < ANY (
  SELECT count(VendorID)
  FROM Purchasing.VendorContact
  WHERE Contact.ContactID = VendorContact.ContactID
)