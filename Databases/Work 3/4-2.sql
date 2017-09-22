select COUNT(EmailAddress)
	from HumanResources.Employee
		inner join Person.Contact
		on Contact.ContactID = Employee.ContactID
	where EmailAddress is not null