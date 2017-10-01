select ProductLine, avg(Product.ListPrice)

/* search for bought product */
from Production.Product
	where MakeFlag = 0

group by ProductLine
	having ProductLine is not null