select FirstName, LastName, Name
from Purchasing.VendorContact

	/* получаем должности поставщиков */
	inner join Person.ContactType
	on VendorContact.ContactTypeID = ContactType.ContactTypeID

	/* получаем имена и фамилии поставщиков */
	inner join Person.Contact
	on VendorContact.ContactID = Contact.ContactID