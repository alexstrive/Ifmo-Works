SELECT DISTINCT VendorID
FROM Purchasing.ProductVendor
WHERE ProductID IN (
  SELECT ProductID
  FROM Production.Product
  WHERE Style IN ('W', 'M')
)