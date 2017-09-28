/* No results */

select FirstName, LastName, Phone
from Person.Contact
	inner join Sales.SalesOrderHeader
	on Contact.ContactID = SalesOrderHeader.ContactID
where Status = 1