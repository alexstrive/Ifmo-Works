SELECT
  'Customer' AS Type,
  CustomerID
FROM Sales.CustomerAddress AS CustomerAddress

  JOIN Person.Address AS Address
    ON CustomerAddress.AddressID = Address.AddressID

WHERE Address.City = 'New York'

UNION

SELECT
  'Vendor' AS Type,
  VendorID
FROM Purchasing.VendorAddress AS VendorAddress
  JOIN Person.Address AS Address
    ON VendorAddress.AddressID = Address.AddressID
WHERE Address.City = 'New York'