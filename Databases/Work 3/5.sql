SELECT
  FirstName,
  LastName,
  ContactType.Name
FROM Purchasing.VendorContact as VendorContact

  /* get job title of agent */
  INNER JOIN Person.ContactType as ContactType
    ON VendorContact.ContactTypeID = ContactType.ContactTypeID

  /* get first name and last name of agent */
  INNER JOIN Person.Contact as Contact
    ON VendorContact.ContactID = Contact.ContactID

  /* get products of vendor */
  LEFT JOIN Purchasing.ProductVendor as ProductVendor
    ON VendorContact.VendorID = ProductVendor.VendorID

  /* get name of product */
  INNER JOIN Production.Product as Product
    ON ProductVendor.ProductID = Product.ProductID

/* show only mountain bicycles */
WHERE Product.ProductLine = 'M'

/* order alphabetical */
ORDER BY 1, 2 DESC