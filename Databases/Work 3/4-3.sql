select FirstName, LastName, EmailAddress
/* get vendor agent of company*/
from Purchasing.VendorContact

	/* get name of agent */
	inner join Person.Contact
	on VendorContact.ContactID = Contact.ContactID

	/* get name of company */
	inner join Purchasing.Vendor
	on VendorContact.VendorID = Vendor.VendorID

/* order by company name*/
order by Name