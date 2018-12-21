CREATE trigger CheckLoginAvailabilityUpdate
  on Customer
  instead of UPDATE as
  begin
    DECLARE @Login varchar(255)
    DECLARE @CustomerID int
    select @Login = Login, @CustomerID = inserted.CustomerID from inserted

    select * from inserted
    select CustomerID from Customer where CustomerID = @CustomerID and Login = @Login

    if dbo.IsLoginTaken(@Login) = 1 and not (exists(select CustomerID from Customer where CustomerID = @CustomerID and Login = @Login))
      throw 50500, 'Login already taken!', 1;

    update Customer
    set Customer.FullName = inserted.FullName,
        Customer.Login    = inserted.Login,
        Customer.Password = inserted.Password
    from inserted
    where Customer.CustomerID = inserted.CustomerID
  end
go

