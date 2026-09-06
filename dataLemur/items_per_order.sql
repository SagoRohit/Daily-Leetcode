select 
  round(
    sum(item_count::decimal * order_occurrences)
    /sum(order_occurrences)
    ,1) as mean
from items_per_order