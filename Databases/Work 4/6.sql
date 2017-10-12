SELECT '1-3' as Range, COUNT(*) as Count
FROM Sales.SalesOrderDetail
WHERE OrderQty IN (1, 3)
UNION
SELECT '4-6' as Range, COUNT(*) as Count
FROM Sales.SalesOrderDetail
WHERE OrderQty IN (4, 6)