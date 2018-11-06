SELECT
  SalesPerson.Bonus * 1.15 AS BonusValue,
  '15%'                    AS Factor
FROM Sales.SalesPerson AS SalesPerson
WHERE SalesPerson.SalesYTD / SalesPerson.SalesQuota < 9.9 AND SalesPerson.SalesYTD / SalesPerson.SalesQuota > 5

UNION

SELECT
  SalesMan.Bonus * 1.2 AS BonusValue,
  '20%'                AS Factor
FROM Sales.SalesPerson AS SalesMan
WHERE SalesMan.SalesYTD / SalesMan.SalesQuota < 15 AND SalesMan.SalesYTD / SalesMan.SalesQuota > 10

ORDER BY Factor