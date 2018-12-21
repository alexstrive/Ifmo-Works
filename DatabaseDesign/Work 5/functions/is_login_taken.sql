CREATE FUNCTION dbo.IsLoginTaken(@Login VARCHAR(26))
  RETURNS
    bit AS
  BEGIN
    DECLARE @IsTaken bit

    if exists(select Login from Customer where Login = @Login)
      set @IsTaken = 1
    else set @IsTaken = 0;

    return @IsTaken
  END
go

