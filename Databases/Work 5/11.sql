SELECT CustomerID
FROM Sales.SalesOrderHeader AS OuterInfo
GROUP BY CustomerID
HAVING avg(SubTotal) > ALL (
  SELECT SubTotal
  FROM Sales.SalesOrderHeader AS InnerInfo
  WHERE OrderDate = '07.27.2004' AND InnerInfo.CustomerID = OuterInfo.CustomerID
)