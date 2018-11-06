SELECT
  Title,
  Count(*)
FROM Person.Contact
GROUP BY Title
HAVING Title IN ('Mrs.', 'Ms', 'Ms.')