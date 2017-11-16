SELECT
  Product.Name,
  sum(OrderQty)
FROM Sales.SalesOrderDetail AS SalesOrderDetail

  /* get name of product */
  INNER JOIN Production.Product AS Product
    ON SalesOrderDetail.ProductID = Product.ProductID

GROUP BY Product.Name