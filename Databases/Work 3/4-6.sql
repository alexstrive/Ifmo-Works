select Product.Name, Vendor.Name
from Production.Product
	left join Purchasing.ProductVendor
	on ProductVendor.ProductID = Product.ProductID
	left join Purchasing.Vendor
	on ProductVendor.VendorID = Vendor.VendorID
where ProductLine = 'T'