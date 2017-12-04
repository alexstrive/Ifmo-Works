SELECT VendorID
FROM Purchasing.ProductVendor
WHERE ProductID IN (
  SELECT ProductID
  FROM Production.Product
  WHERE ProductLine = 'M'
)
ORDER BY VendorID