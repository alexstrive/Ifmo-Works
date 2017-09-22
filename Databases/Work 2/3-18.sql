select Title, Count(*)
	from Person.Contact
	group by Title
		having Title in ('Mrs.', 'Ms', 'Ms.')