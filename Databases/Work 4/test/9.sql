SELECT
  FirstVendor.VendorID,
  FirstVendor.AddressID,
  SecondVendor.AddressID
FROM Purchasing.VendorAddress AS FirstVendor
  JOIN Purchasing.VendorAddress AS SecondVendor
    ON FirstVendor.VendorID = SecondVendor.VendorID AND FirstVendor.AddressID <> SecondVendor.AddressID;