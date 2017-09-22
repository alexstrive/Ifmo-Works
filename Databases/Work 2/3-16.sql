select CreditRating, ActiveFlag, Count(*)
	from Purchasing.Vendor
	group by ActiveFlag, CreditRating
	order by CreditRating