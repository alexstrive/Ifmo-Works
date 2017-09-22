select Name, DaysToManufacture
	from Production.Product
	where MakeFlag = 1
	order by DaysToManufacture, Name