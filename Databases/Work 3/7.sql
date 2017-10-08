SELECT
  ProductLine,
  avg(Product.ListPrice)

/* show bought product */
FROM Production.Product
WHERE MakeFlag = 0

GROUP BY ProductLine
HAVING ProductLine IS NOT NULL