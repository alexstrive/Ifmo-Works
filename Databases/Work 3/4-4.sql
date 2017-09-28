/* not completed! */

select FirstName, LastName, Employee.Title
from Person.Contact
	inner join Purchasing.VendorContact
	on VendorContact.ContactID = Contact.ContactID
	inner join HumanResources.Employee
	on Employee.ContactID = VendorContact.ContactID