SELECT
  MakeFlag,
  Avg(SafetyStockLevel)
FROM Production.Product
GROUP BY MakeFlag