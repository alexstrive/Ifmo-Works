SELECT
  'Vendor',
  count(*)
FROM Purchasing.VendorContact AS VendorContact

  JOIN Person.Contact AS Contact
    ON VendorContact.ContactID = Contact.ContactID

WHERE Contact.EmailPromotion = 1

UNION

SELECT
  'Employee',
  count(*)
FROM HumanResources.Employee AS EmployeeContact

  JOIN Person.Contact AS Contact
    ON EmployeeContact.ContactID = Contact.ContactID

WHERE Contact.EmailPromotion = 1

UNION

SELECT
  'Customer',
  count(*)
FROM Sales.Individual AS CustomerAddress

  JOIN Person.Contact AS Contact
    ON CustomerAddress.ContactID = Contact.ContactID

WHERE Contact.EmailPromotion = 1