SELECT
  CreditRating,
  Count(*)
FROM Purchasing.Vendor
GROUP BY CreditRating