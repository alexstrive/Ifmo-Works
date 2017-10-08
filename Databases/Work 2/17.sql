SELECT
  SpecialOfferID,
  Min(UnitPrice)
FROM Sales.SalesOrderDetail
GROUP BY SpecialOfferID
HAVING SpecialOfferID NOT IN (1, 8)
ORDER BY 1