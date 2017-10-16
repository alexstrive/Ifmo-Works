-- Shows duplicates
-- TODO: clarify this

SELECT
  FirstCustomer.CustomerID  AS FirstCustomerID,
  SecondCustomer.CustomerID AS SecondCustomerID
FROM Sales.CustomerAddress AS FirstCustomer

  JOIN Sales.CustomerAddress AS SecondCustomer
    ON FirstCustomer.CustomerID <> SecondCustomer.CustomerID

  JOIN Person.Address AS FirstAddress
    ON FirstCustomer.AddressID = FirstAddress.AddressID

  JOIN Person.Address AS SecondAddress
    ON SecondAddress.AddressID = SecondCustomer.AddressID

WHERE FirstAddress.City = SecondAddress.City