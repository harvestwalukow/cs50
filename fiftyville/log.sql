-- Get more information on the case
SELECT description
FROM crime_scene_reports
WHERE month = 7
  AND day = 28
  AND street = 'Humphrey Street';

-- From last query we get an information about an interview
SELECT transcript
FROM interviews
WHERE month = 7
  AND day = 28;

-- | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |

SELECT *
FROM bakery_security_logs
WHERE year = 2023
  AND month = 7
  AND day = 28;

-- Tryna find the earliest flight out of Fiftyville
SELECT *
FROM flights
WHERE origin_airport_id = 8
  AND year = 2023
  AND month = 7
  AND day = 28;

-- Below is the query to find our guy with all the information we had
SELECT name
FROM people
WHERE phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE year = 2023
      AND month = 7
      AND day = 28
      AND duration < 60
)
AND license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2023
      AND month = 7
      AND day = 28
      AND hour = 10
      AND minute > 5
      AND minute < 25
)
AND passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id = 36
)
AND id IN (
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2023
          AND month = 7
          AND day = 28
          AND atm_location = 'Leggett Street'
          AND transaction_type = 'withdraw'
    )
);

-- Find thief’s accomplice
SELECT name
FROM people
WHERE phone_number IN (
    SELECT receiver
    FROM phone_calls
    WHERE year = 2023
    AND month = 7
    AND day = 28
    AND duration < 60
    AND caller = (
        SELECT phone_number
        FROM people
        WHERE name = 'Bruce'
    )
);
