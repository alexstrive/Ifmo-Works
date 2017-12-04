SELECT
  CreditRating,
  count(*) AS Count
FROM Purchasing.Vendor
WHERE VendorID IN (
  SELECT VendorID
  FROM Purchasing.VendorAddress
    JOIN Person.Address
      ON VendorAddress.AddressID = Address.AddressID
  WHERE Address.City = 'New York'
)
GROUP BY CreditRating