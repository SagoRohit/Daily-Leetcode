with base as (select account_id,
(
  case 
  when transaction_type = 'Deposit' then amount*1
  else amount*(-1)
  end 
) as temp_amount
from transactions)

select account_id, 
sum(temp_amount) as final_balance
from base 
group by account_id


-- select * from TRANSACTIONs