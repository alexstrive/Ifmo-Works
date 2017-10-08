SELECT
  Product.Name,
  sum(OrderQty)
FROM Sales.SalesOrderDetail as SalesOrderDetail

  /* get name of product */
  INNER JOIN Production.Product as Product
    ON SalesOrderDetail.ProductID = Product.ProductID

GROUP BY Product.Name