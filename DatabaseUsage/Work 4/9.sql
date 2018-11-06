-- No results
-- Shows duplicates
-- TODO: clarify this

SELECT
  FirstVendor.VendorID  AS FirstVendorID,
  SecondVendor.VendorID AS SecondVendorID
FROM Purchasing.VendorAddress AS FirstVendor

  JOIN Purchasing.VendorAddress AS SecondVendor
    ON FirstVendor.VendorID <> SecondVendor.VendorID

  JOIN Person.Address AS FirstVendorAddress
    ON FirstVendor.AddressID = FirstVendorAddress.AddressID

  JOIN Person.Address AS SecondVendorAddress
    ON SecondVendor.AddressID = SecondVendorAddress.AddressID

WHERE
  FirstVendorAddress.City = SecondVendorAddress.City AND
  FirstVendorAddress.AddressLine1 = SecondVendorAddress.AddressLine1