CREATE trigger CheckLoginAvailability
  on Customer
  instead of INSERT as
  begin
    DECLARE @Login varchar(255)
    select @Login = Login from inserted

    if dbo.IsLoginTaken(@Login) = 1
      throw 50500, 'Login already taken!', 1;

    insert * from inserted
  end
go
