select FirstName, LastName, Name
from Purchasing.VendorContact

	/* �������� ��������� ����������� */
	inner join Person.ContactType
	on VendorContact.ContactTypeID = ContactType.ContactTypeID

	/* �������� ����� � ������� ����������� */
	inner join Person.Contact
	on VendorContact.ContactID = Contact.ContactID