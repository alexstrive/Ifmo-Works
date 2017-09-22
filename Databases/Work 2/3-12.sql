select Title, Count(*)
	from Person.Contact
	group by Title
		having Title is not null
	order by 2 desc