SELECT '36-37' as Range, BillOfMaterialsID
FROM Production.BillOfMaterials
WHERE PerAssemblyQty in (36, 37)
UNION
SELECT '38-40' as Range, BillOfMaterialsID
FROM Production.BillOfMaterials
WHERE PerAssemblyQty in (38, 40)