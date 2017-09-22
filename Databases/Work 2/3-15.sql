select Style, Avg(ListPrice)
	from Production.Product
	group by Style
		having Style <> 'U'