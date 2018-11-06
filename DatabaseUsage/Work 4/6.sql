SELECT
  '1-3'    AS Range,
  COUNT(*) AS Count
FROM Sales.SalesOrderDetail
WHERE OrderQty BETWEEN 1 AND 3
UNION
SELECT
  '4-6'    AS Range,
  COUNT(*) AS Count
FROM Sales.SalesOrderDetail
WHERE OrderQty BETWEEN 4 AND 6