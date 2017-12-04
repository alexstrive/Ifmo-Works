SELECT VendorID
FROM Purchasing.ProductVendor
WHERE OnOrderQty > all (
  SELECT max(MinOrderQty)
  FROM Purchasing.ProductVendor
)