declare AllCustomers cursor local forward_only static
for select FullName, Phone, Address
    from Customer
           left join [Order] O on Customer.CustomerID = O.CustomerID

DECLARE @FullName varchar(40)
 DECLARE @Phone VARCHAR(8)
DECLARE @Address VARCHAR(80)

DECLARE @Message varchar(max)

open AllCustomers;

fetch next from AllCustomers
into @FullName, @Phone, @Address

WHILE @@FETCH_STATUS = 0
  begin
    print FORMATMESSAGE('Fullname: %s; Phone: %s; Address: %s;', @FullName, @Phone, @Address)
    FETCH next from AllCustomers
    into @FullName, @Phone, @Address
  end

close AllCustomers;
deallocate AllCustomers;