select FirstName, LastName, Name
from Purchasing.VendorContact

	/* get job title of agent */
	inner join Person.ContactType
	on VendorContact.ContactTypeID = ContactType.ContactTypeID

	/* get first name and last name of agent */
	inner join Person.Contact
	on VendorContact.ContactID = Contact.ContactID