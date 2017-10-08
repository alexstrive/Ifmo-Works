SELECT Product.Name
FROM Sales.SalesOrderHeader AS SalesOrderHeader

  /* get info about product */
  INNER JOIN Sales.SalesOrderDetail AS SalesOrderDetail
    ON SalesOrderHeader.SalesOrderID = SalesOrderDetail.SalesOrderID

  /* get name of product */
  INNER JOIN Production.Product AS Product
    ON SalesOrderDetail.ProductID = Product.ProductID

WHERE OrderDate = '01.02.2004'