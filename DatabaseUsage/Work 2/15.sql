SELECT
  Style,
  Avg(ListPrice)
FROM Production.Product
GROUP BY Style
HAVING Style <> 'U'