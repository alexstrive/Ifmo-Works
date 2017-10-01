select Product.Name, sum(OrderQty)
from Sales.SalesOrderDetail
	
	/* get name of product */
	inner join Production.Product
	on SalesOrderDetail.ProductID = Product.ProductID

group by Product.Name