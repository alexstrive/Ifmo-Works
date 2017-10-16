SELECT
  FirstName,
  LastName,
  MiddleName
FROM Person.Contact
WHERE EmailPromotion = 1
ORDER BY 1, 2, 3