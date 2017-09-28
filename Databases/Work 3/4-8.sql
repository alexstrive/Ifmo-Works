select Product.Name
from Sales.SalesOrderHeader
	inner join Sales.SalesOrderDetail
	on SalesOrderDetail.SalesOrderID = SalesOrderHeader.SalesOrderID
	inner join Production.Product
	on Product.ProductID = SalesOrderDetail.ProductID
where OrderDate = '01.02.2004'