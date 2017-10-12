SELECT 'Component' as Type, ComponentID as ID
FROM Production.BillOfMaterials
WHERE BillOfMaterialsID = 400
UNION
SELECT 'Product' as Type, ProductAssemblyID
FROM Production.BillOfMaterials
WHERE BillOfMaterialsID = 400