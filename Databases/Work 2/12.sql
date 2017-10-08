SELECT
  Title,
  Count(*)
FROM Person.Contact
GROUP BY Title
HAVING Title IS NOT NULL
ORDER BY 2 DESC