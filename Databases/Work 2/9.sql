SELECT
  Name,
  OrderQty
FROM Production.Product as Product
  INNER JOIN Sales.SalesOrderDetail as SalesOrderDetail
    ON Product.ProductID = SalesOrderDetail.ProductID
ORDER BY 2