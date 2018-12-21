CREATE VIEW CustomerOrder
  AS
    SELECT FullName, Address, Phone, Comment
    from Customer
           left join [Order] O on Customer.CustomerID = O.CustomerID
go