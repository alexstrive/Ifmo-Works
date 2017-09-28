select COUNT(*)
from Person.Contact
	inner join HumanResources.Employee
	on Employee.ContactID = Contact.ContactID
where EmailAddress is not null