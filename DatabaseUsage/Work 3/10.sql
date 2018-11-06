/*
	No results 
	All orders in send state (5)
*/

SELECT
  FirstName,
  LastName,
  Phone
FROM Person.Contact as Contact

  /* get first name, last name and phone of customer */
  INNER JOIN Sales.SalesOrderHeader as SalesOrderHeader
    ON Contact.ContactID = SalesOrderHeader.ContactID

/* search for order which in progress */
WHERE Status = 1