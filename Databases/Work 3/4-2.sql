select COUNT(*)
from HumanResources.Employee
	
	/* get emails */
	inner join Person.Contact
	on Employee.ContactID = Contact.ContactID

/* search for peoples with emails */
where EmailAddress is not null