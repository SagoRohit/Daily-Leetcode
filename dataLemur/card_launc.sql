with base as (
select card_name, issue_month, issued_amount, issue_year,
row_number() over(partition by card_name
order by issue_year asc, issue_month asc) as rnk
from monthly_cards_issued)

select card_name, issued_amount
from base 
where rnk = 1
order by issued_amount desc;