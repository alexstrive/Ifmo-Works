select CreditRating, Count(Name)
	from Purchasing.Vendor
	group by CreditRating