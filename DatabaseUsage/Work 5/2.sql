SELECT Name
FROM Production.Product
WHERE ProductID IN (
  SELECT ProductVendor.ProductID
  FROM Purchasing.ProductVendor
)
ORDER BY Name