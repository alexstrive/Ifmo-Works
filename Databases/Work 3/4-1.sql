select FirstName, LastName, Employee.Title, Phone
from HumanResources.Employee

	/* get phones */
	inner join Person.Contact
	on Employee.ContactID = Contact.ContactID

/* search for peoples with phones */
where Phone is not null