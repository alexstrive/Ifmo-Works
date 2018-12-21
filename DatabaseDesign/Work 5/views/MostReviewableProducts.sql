CREATE VIEW MostReviewableProducts
  AS
    select P.ProductID, P.Title, count(*) as Count
    from Comment
           left join Product P on Comment.ProductID = P.ProductID
    group by P.ProductID, P.Title
go

