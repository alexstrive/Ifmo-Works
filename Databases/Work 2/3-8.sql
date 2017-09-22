select CreditRating, Count(*)
	from Purchasing.Vendor
	group by CreditRating