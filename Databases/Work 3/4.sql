select FirstName, LastName, Name
from Purchasing.VendorContact as VendorContact

	/* get job title of agent */
	inner join Person.ContactType as ContactType
	on VendorContact.ContactTypeID = ContactType.ContactTypeID

	/* get first name and last name of agent */
	inner join Person.Contact as Contact
	on VendorContact.ContactID = Contact.ContactID