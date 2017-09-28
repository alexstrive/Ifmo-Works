/* not completed! */

select FirstName, LastName, Phone
from Person.Contact
	inner join Purchasing.VendorContact
	on VendorContact.ContactID = Contact.ContactID
	inner join Purchasing.Vendor
	on (Vendor.VendorID = VendorContact.VendorID) and ()
order by 1, 2