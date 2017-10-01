select Product.Name, Vendor.Name
from Production.Product

	/* get vendor of product */
	left join Purchasing.ProductVendor
	on Product.ProductID = ProductVendor.ProductID

	/* get name of vendor */
	left join Purchasing.Vendor
	on ProductVendor.VendorID = Vendor.VendorID

/* search for tourist product*/
where ProductLine = 'T'