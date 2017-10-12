SELECT
  FirstSalesPerson.SalesPersonID as FirstPersonID,
  SecondSalesPerson.SalesPersonID as SecondPersonID
FROM Sales.SalesPerson AS FirstSalesPerson

  JOIN Sales.SalesPerson AS SecondSalesPerson
    ON FirstSalesPerson.CommissionPct = SecondSalesPerson.CommissionPct

WHERE FirstSalesPerson.SalesPersonID <> SecondSalesPerson.SalesPersonID