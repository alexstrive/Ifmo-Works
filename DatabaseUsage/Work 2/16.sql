SELECT
  CreditRating,
  ActiveFlag,
  Count(*)
FROM Purchasing.Vendor
GROUP BY ActiveFlag, CreditRating
ORDER BY CreditRating