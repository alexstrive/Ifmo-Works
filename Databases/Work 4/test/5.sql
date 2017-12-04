SELECT
  FirstVendor.Name,
  SecondVendor.Name,
  Address.City
FROM (Purchasing.VendorAddress AS FirstVendorADdress
  JOIN Person.Address AS Address
    ON FirstVendorADdress.AddressID = Address.AddressID
  JOIN Purchasing.Vendor AS FirstVendor
    ON FirstVendorADdress.VendorID = FirstVendor.VendorID)
  JOIN (Purchasing.VendorAddress AS SecondVendorAddress

    JOIN Person.Address AS SecondAddress
      ON SecondVendorAddress.AddressID = SecondAddress.AddressID
    JOIN Purchasing.Vendor AS SecondVendor
      ON SecondVendorAddress.VendorID = SecondVendor.VendorID)

    ON Address.City = SecondAddress.City AND FirstVendorADdress.VendorID < SecondVendorAddress.VendorID;