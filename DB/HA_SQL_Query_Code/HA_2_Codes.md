### Country Data

#### 5.1
select
	cd.country_name
	, length(cd.country_name) as Anz_Buchstaben
    , case when length(cd.country_name) > 10 then 'Landname hat mehr als 10 Buchstaben'
	     when length(cd.country_name) between 6 and 10 then  'Landname hat zw. 6 und 10 Buchstaben'
	     else 'Landname hat <= 5 Buchstaben' 
	  end as Buchstaben_Beschreibung
FROM
	country_data cd
ORDER BY 
	cd.country_name

### Northwind
#### 5.1

SELECT
    to_char(o.orderdate, 'yyyy.mm') AS MONTH,
    round(avg(o.shippeddate - o.orderdate), 2) AS avg_lag,
    min(o.shippeddate - o.orderdate) AS min_lag,
    max(o.shippeddate - o.orderdate) AS max_lag
FROM
    orders o
Where
    orderdate >= to_date ('1997.01','yyyy.mm')
    and orderdate < to_date ('1998.01','yyyy.mm')
GROUP BY
    to_char(o.orderdate, 'yyyy.mm')
ORDER BY
    MONTH

#### 5.2

select
    p.supplierid as supplierid
    , count(p.productid) as anzahl_produkte
    , sum(p.unitsinstock) as unitsinstock
    , round(avg(unitprice), 2) as unitprice
from
    products p
group by
    p.supplierid
order by
    p.supplierid asc

#### 5.3

SELECT
    o.customerid,
    count(o.orderid) AS anzahl_orders
FROM
    orders o
WHERE
    shippeddate > to_date('01.01.1998', 'dd.mm.yyyy')
GROUP BY
    o.customerid
order by
    count(o.orderid) desc
    , o.customerid asc

#### 5.4

SELECT
    to_char(o.orderdate, 'mm.yyyy') AS monat,
    count(o.orderid) AS anzahl_orders,
    COUNT(DISTINCT o.customerid) AS anzahl_kunden,
    sum(o.freight) AS fracht_gewicht
FROM
    orders o
GROUP BY
    to_char(o.orderdate, 'mm.yyyy')
ORDER BY
    to_char(o.orderdate, 'mm.yyyy') ASC

#### 5.5
SELECT
    to_char(o.orderdate, 'mm.yyyy') AS monat,
    o.shipcountry,
    count(o.orderid) AS anzahl_orders,
    COUNT(DISTINCT o.customerid) AS anzahl_kunden,
    sum(o.freight) AS fracht_gewicht
FROM
    orders o
GROUP BY
    to_char(o.orderdate, 'mm.yyyy'),
    o.shipcountry
ORDER BY
    to_char(o.orderdate, 'mm.yyyy') ASC,
    o.shipcountry ASC

#### 5.6

SELECT
    CONCAT(o.shipcountry, ' - ', o.shipcity),
    count(o.orderid) AS anzahl_orders,
    COUNT(DISTINCT o.orderdate) AS anzahl_orderdates,
    count(DISTINCT o.employeeid) AS anzahl_mitarbeiter
FROM
    orders o
GROUP BY
    CONCAT(o.shipcountry, ' - ', o.shipcity)
ORDER BY
    count(o.orderid) DESC
    , CONCAT(o.shipcountry, ' - ', o.shipcity)

#### 5.7
SELECT
    c.country,
    COUNT(DISTINCT c.customerid) AS count,
    SUM(
        CASE
            WHEN c.contactname LIKE 'A%' THEN 1
            ELSE 0
        END
    ) AS anzahl_kunden_mit_a
FROM
    customers c
GROUP BY
    c.country
ORDER BY
    COUNT(DISTINCT c.customerid) DESC,
    c.country ASC

#### 5.8

select
    case
        when p.unitprice < 10 then 'Preis < 10'
        when p.unitprice < 25 then 'Preis < 25'
        when p.unitprice < 50 then 'Preis < 50'
        when p.unitprice >= 50 then 'Preis >= 50'
      end
    , count(p.productid) as anzahl_Produkte
    , round(avg(p.unitprice), 2) as unitprice
    , count(distinct p.supplierid) as anzahl_supplier
from
    products p
group by
    case
        when p.unitprice < 10 then 'Preis < 10'
        when p.unitprice < 25 then 'Preis < 25'
        when p.unitprice < 50 then 'Preis < 50'
        when p.unitprice >= 50 then 'Preis >= 50'
      end
order by
    1 