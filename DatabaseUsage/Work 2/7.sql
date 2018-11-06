SELECT AVG(ListPrice)
FROM Production.Product
GROUP BY MakeFlag
HAVING MakeFlag <> 1