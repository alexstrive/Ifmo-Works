SELECT VendorID
FROM Purchasing.Vendor
WHERE VendorID NOT IN (
  SELECT VendorID
  FROM Purchasing.ProductVendor
)