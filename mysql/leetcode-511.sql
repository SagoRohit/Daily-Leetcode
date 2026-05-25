select player_id, min(event_date) as first_login
from activity
GROUP BY player_id

-- here we group the activity of each player.
-- then we tried to find the min date to find the first login