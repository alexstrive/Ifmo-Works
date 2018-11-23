create table Stores
(
  code int identity
    primary key,
  title varchar(100)
)
grant all on Stores to AbolrousHazem

create table Products
(
  title varchar(255) not null,
  vendor int not null,
  quantity int not null,
  cost float not null
)
grant all on Products to AbolrousHazem