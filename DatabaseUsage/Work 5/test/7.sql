SELECT ProductID
FROM Production.Product
WHERE Style NOT IN (
  SELECT Style
  FROM Production.Product
  WHERE ProductSubcategoryID = 1
)