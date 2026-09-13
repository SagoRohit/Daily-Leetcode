with base as 
(select ticker, open as highest_open, to_char(date, 'Mon-YYYY') as highest_mth
from stock_prices s
where open = 
(select max(open) from stock_prices s2
where s.ticker = s2.ticker)),

code as 
(select ticker, open as lowest_open, to_char(date, 'Mon-YYYY') as lowest_mth
from stock_prices s
where open = 
(select min(open) from stock_prices s2
where s.ticker = s2.ticker))

select b.ticker, highest_mth, highest_open, lowest_mth, lowest_open
from base b join code c on 
b.ticker = c.ticker
order by b.ticker asc 