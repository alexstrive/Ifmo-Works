/*
	No results 
	All orders in send state (5)
*/

select FirstName, LastName, Phone
from Person.Contact

	/* get first name, last name and phone of customer */
	inner join Sales.SalesOrderHeader
	on Contact.ContactID = SalesOrderHeader.ContactID

/* search for order which in progress */
where Status = 1