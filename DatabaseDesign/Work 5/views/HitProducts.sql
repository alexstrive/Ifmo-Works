CREATE VIEW HitProducts
  AS
    select P.ProductID, count(*) as Purchases
    from OrderProduct
           left join Product P on OrderProduct.ProductID = P.ProductID
    group by P.ProductID
go

