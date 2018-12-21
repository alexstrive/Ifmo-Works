CREATE procedure CreateOrder
    @CustomerID int,
    @ProductIDs  varchar(1000),
    @Address    varchar(100),
    @Phone      varchar(10),
    @Comment    text
as begin
  -- Добавляем информацию в соответствующую таблицу
  insert into [Order] values (@Address, @Phone, @Comment, @CustomerID)

  -- Связываем только что созданный заказ с указанными в нём товарами
  insert into OrderProduct
  select OrderID, SplitString.Name as ProductID
  from SplitString(@ProductIDs)
         inner join [Order] on OrderID = @@IDENTITY
end
go

