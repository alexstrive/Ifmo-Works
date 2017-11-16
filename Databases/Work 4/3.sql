SELECT
  FirstSalesPerson.SalesPersonID  AS FirstPersonID,
  SecondSalesPerson.SalesPersonID AS SecondPersonID
FROM Sales.SalesPerson AS FirstSalesPerson

  JOIN Sales.SalesPerson AS SecondSalesPerson
    ON FirstSalesPerson.CommissionPct = SecondSalesPerson.CommissionPct

WHERE FirstSalesPerson.SalesPersonID <> SecondSalesPerson.SalesPersonID