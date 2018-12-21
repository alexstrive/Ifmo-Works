CREATE trigger WarningAccountDeletion
  on Customer
  after DELETE as
  begin
    DECLARE @CustomerID int
    DECLARE @FullName varchar(40)
    DECLARE @Login varchar(26)
    DECLARE @Password varchar(26)

    select @CustomerID = deleted.CustomerID,
           @FullName = deleted.FullName,
           @Login = deleted.Login,
           @Password = deleted.Password
    from deleted

    delete from Customer
    where CustomerID = @CustomerID

    print FORMATMESSAGE('Successful Account deletion: %i %s %s %s', @CustomerID, @FullName, @Login, @Password)
  end
go

