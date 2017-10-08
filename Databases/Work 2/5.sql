SELECT
  Name,
  Color
FROM Production.Product
WHERE MakeFlag = 1 AND Color IS NOT NULL
ORDER BY Color