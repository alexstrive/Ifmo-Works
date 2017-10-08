SELECT
  Name,
  DaysToManufacture
FROM Production.Product
WHERE MakeFlag = 1
ORDER BY DaysToManufacture, Name