-- Keep a log of any SQL queries you execute as you solve the mystery.

--The CS50 Duck has been stolen! The town of Fiftyville has called upon you to solve the mystery of the stolen duck. Authorities believe that the thief stole the duck and then, shortly afterwards, took a flight out of town with the help of an accomplice. Your goal is to identify:

--Who the thief is,
--What city the thief escaped to, and
--Who the thief’s accomplice is who helped them escape

--All you know is that the theft took place on July 28, 2020 and that it took place on Chamberlin Street.





SELECT * FROM crime_scene_reports WHERE street LIKE "%Chamberlin Street%" AND description LIKE "%CS50 DUCK%";  --to see if the complain is registered and get information about it

SELECT * FROM interviews WHERE transcript LIKE "%courthouse%" AND day = 28 AND month = 7 AND year = 2020 ; -- to get information about interview by police

SELECT * FROM courthouse_security_logs WHERE activity = "exit" AND hour = 10 AND minute >= 15 AND minute <= 30 AND day = 28 AND month = 7 AND year = 2020 ;


SELECT * FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE day = 28 AND month = 7 AND year = 2020 AND hour = 10 AND minute >= 15 AND minute <= 30 AND activity = "exit" ;
--sus on patrick, ernest, amber, Danielle, roger, elizabeth, russell and evelyn


SELECT * FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE day = 28 AND month = 7 AND year = 2020 AND transaction_type = "withdraw" AND atm_location = "Fifer Street" ;
--sus on ernest, elizabeth, russell, danielle


SELECT * FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE day = 28 AND month = 7 AND year = 2020 AND duration < 60 ;
-- only  sus left ernest, russell


SELECT * FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id = ( SELECT id FROM flights WHERE day = 29 AND month = 7 AND year = 2020 ORDER BY hour, minute) ;
--only left is ernest






SELECT city FROM airports WHERE id = ( SELECT destination_airport_id FROM flights WHERE day = 29 AND month = 7 AND year = 2020 ORDER BY hour, minute LIMIT 1) ;
--which city the theif goes


SELECT name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE day = 28 AND month = 7 AND year = 2020 AND duration < 60 AND caller = (SELECT phone_number FROM people WHERE name = "Ernest" ) ;
--name of helper
