SELECT
  Product.Name,
  Vendor.Name
FROM Production.Product AS Product

  /* get vendor of product */
  LEFT JOIN Purchasing.ProductVendor AS ProductVendor
    ON Product.ProductID = ProductVendor.ProductID

  /* get name of vendor */
  LEFT JOIN Purchasing.Vendor AS Vendor
    ON ProductVendor.VendorID = Vendor.VendorID

/* search for tourist product*/
WHERE ProductLine = 'T'