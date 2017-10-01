select FirstName, LastName, ContactType.Name
from Purchasing.VendorContact

	/* get job title of agent */
	inner join Person.ContactType
	on VendorContact.ContactTypeID = ContactType.ContactTypeID

	/* get first name and last name of agent */
	inner join Person.Contact
	on VendorContact.ContactID = Contact.ContactID

	/* get products of vendor */
	left join Purchasing.ProductVendor
	on VendorContact.VendorID = ProductVendor.VendorID

	/* get name of product */
	inner join Production.Product
	on ProductVendor.ProductID = Product.ProductID

/* search for only mountain bicycles */
where Product.ProductLine = 'M'

/* order by alphabetical */
order by 1, 2 desc