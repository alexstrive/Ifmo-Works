SELECT
  CustomerID,
  BillAddress.AddressLine1 AS BillAddress,
  ShipAddress.AddressLine1 AS ShipAddress
FROM Sales.SalesOrderHeader AS SalesOrderHeader

  JOIN Person.Address AS BillAddress
    ON SalesOrderHeader.BillToAddressID = BillAddress.AddressID

  JOIN Person.Address AS ShipAddress
    ON SalesOrderHeader.ShipToAddressID = ShipAddress.AddressID

WHERE BillAddress.AddressLine1 <> ShipAddress.AddressLine1