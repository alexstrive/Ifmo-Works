SELECT
  '36-37' AS Range,
  BillOfMaterialsID
FROM Production.BillOfMaterials
WHERE PerAssemblyQty IN (36, 37)
UNION
SELECT
  '38-40' AS Range,
  BillOfMaterialsID
FROM Production.BillOfMaterials
WHERE PerAssemblyQty BETWEEN 38 AND 40