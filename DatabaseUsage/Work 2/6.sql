SELECT
  ProductLine,
  AVG(DaysToManufacture)
FROM Production.Product
GROUP BY ProductLine
HAVING ProductLine IS NOT NULL