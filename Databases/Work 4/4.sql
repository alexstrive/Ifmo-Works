SELECT
  'Component' AS Type,
  ComponentID AS ID
FROM Production.BillOfMaterials
WHERE BillOfMaterialsID = 400
UNION
SELECT
  'Product' AS Type,
  ProductAssemblyID
FROM Production.BillOfMaterials
WHERE BillOfMaterialsID = 400