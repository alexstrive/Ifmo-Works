create procedure Customers @cursor CURSOR VARYING OUTPUT
as
  SET @cursor = CURSOR FORWARD_ONLY DYNAMIC FOR SELECT FullName, Login, Password FROM Customer  OPEN @cursor 
go

