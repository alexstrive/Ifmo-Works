SELECT ProductID
FROM Production.Product
WHERE Size > ANY (
  SELECT Size
  FROM Production.Product
    JOIN Purchasing.ProductVendor
      ON Product.ProductID = ProductVendor.ProductID
  WHERE ProductVendor.VendorID = 90
)