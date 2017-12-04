SELECT '.com' as Domain, count(*)
FROM Person.Contact as Address
WHERE Address.EmailAddress LIKE '%.com'

UNION

SELECT '.net' as Domain, count(*)
FROM Person.Contact as Address
WHERE Address.EmailAddress LIKE '%.net'

UNION

SELECT '.org' as Domain, count(*)
FROM Person.Contact as Address
WHERE Address.EmailAddress LIKE '%.org'