select ProductLine, AVG(DaysToManufacture)
	from Production.Product
	group by ProductLine
		having ProductLine is not null