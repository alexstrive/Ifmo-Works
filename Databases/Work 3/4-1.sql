select FirstName, LastName, Employee.Title, Phone
	from Person.Contact
		inner join HumanResources.Employee
		on Contact.ContactID = Employee.ContactID