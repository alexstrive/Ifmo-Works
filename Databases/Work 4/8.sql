SELECT
  UnitMeasureCode as Code,
  COUNT(*) as Count
FROM Production.BillOfMaterials
GROUP BY UnitMeasureCode
HAVING UnitMeasureCode IN ('EA', 'OZ')