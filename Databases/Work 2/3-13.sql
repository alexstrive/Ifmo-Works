select MakeFlag, Avg(SafetyStockLevel)
	from Production.Product
	group by MakeFlag