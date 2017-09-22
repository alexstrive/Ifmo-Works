select Name, OrderQty
	from Production.Product
		inner join Sales.SalesOrderDetail
		on Product.ProductID = SalesOrderDetail.ProductID
	order by 2