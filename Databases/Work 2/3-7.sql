select AVG(ListPrice)
	from Production.Product
	group by MakeFlag
		having MakeFlag <> 1