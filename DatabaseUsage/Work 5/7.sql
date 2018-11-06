SELECT City
FROM Purchasing.Vendor
  JOIN Purchasing.VendorAddress
    ON Vendor.VendorID = VendorAddress.VendorID
  JOIN Person.Address
    ON VendorAddress.AddressID = Address.AddressID
GROUP BY City, CreditRating
HAVING CreditRating = 5