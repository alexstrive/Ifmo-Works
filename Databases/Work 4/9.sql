-- No results
-- Shows duplicates
-- TODO: clarify this

SELECT
  FirstVendor.VendorID  AS FirstVendorID,
  SecondVendor.VendorID AS SecondVendorID
FROM Purchasing.VendorAddress AS FirstVendor

  JOIN Purchasing.VendorAddress AS SecondVendor
    ON FirstVendor.VendorID <> SecondVendor.VendorID AND FirstVendor.AddressID = SecondVendor.AddressID