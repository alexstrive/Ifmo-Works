select Product.Name
from Sales.SalesOrderHeader
	
	/* get info about product */
	inner join Sales.SalesOrderDetail
	on SalesOrderHeader.SalesOrderID = SalesOrderDetail.SalesOrderID
	
	/* get name of product */
	inner join Production.Product
	on SalesOrderDetail.ProductID = Product.ProductID

where OrderDate = '01.02.2004'