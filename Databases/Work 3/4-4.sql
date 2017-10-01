select FirstName, LastName, Name
from Purchasing.VendorContact

	/* get job title of agents */
	inner join Person.ContactType
	on VendorContact.ContactTypeID = ContactType.ContactTypeID

	/* get first names and last names of agents */
	inner join Person.Contact
	on VendorContact.ContactID = Contact.ContactID