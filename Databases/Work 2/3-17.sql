select SpecialOfferID, Min(UnitPrice)
	from Sales.SalesOrderDetail
	group by SpecialOfferID
		having SpecialOfferID not in (1, 8)
	order by 1