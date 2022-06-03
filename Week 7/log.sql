-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "Humphrey Street";
-- EL HECHO FUE A LAS 10:15 am, 3 testigos, cada una de sus entrevistas menciona la panaderia

SELECT transcript FROM interviews WHERE month = 7 AND day = 28;

-- 1ra entrevista: En algún momento dentro de los diez minutos del robo, vi al ladrón subirse a un automóvil en el ESTACIONAMIENTO DE LA PANADERIA y alejarse. Si tiene imágenes de seguridad del
-- estacionamiento de la panadería, es posible que desee buscar autos que hayan salido del estacionamiento en ese período de tiempo.

SELECT name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = "exit";
--SUSPECTS: Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey

-- 2ra entrevista: No sé el nombre del ladrón, pero era alguien a quien reconocí. Esta mañana, antes de llegar a la panadería de Emma, ​​estaba caminando por el CAJERO AUTOMATICO en la calle Leggett
-- y vi al ladrón que estaba retirando algo de dinero.

SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
-- SUSPECTS: Bruce, Diana, Brooke, Kenny, Iman, Luca, Taylor, Benista

-- COMMON SUSPECTS: Bruce, Iman, Diana, luca

-- 3ra entrevista: Cuando el ladrón salía de la panadería, LLAMO a alguien que les habló durante menos de un minuto. En la llamada, escuché al ladrón decir que planeaban tomar EL PRIMER VUELO
--                 de Fiftyville mañana. El ladrón luego le preguntó a la persona del otro lado.
SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id =
(SELECT id FROM airports WHERE city = "Fiftyville") ORDER BY hour, minute LIMIT 1);
-- SUSPECTS: Doris, Sofia, Bruce, Edward, Kelsey, Taylor, Kenny, Luca

-- COMMON SUSPECTS: Bruce, luca

SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
-- SUSPECTS: Sofia, Kelsey, Bruce, Taylor, Diana, Carina, Kenny, Benista

-- COMMON SUSPECTS: BRUCE!

SELECT city FROM airports
WHERE id = (SELECT destination_airport_id FROM flights
WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id =
(SELECT id FROM airports WHERE city = "Fiftyville")
ORDER BY hour, minute LIMIT 1);
-- DESTINATION = NEW YORK CITY

SELECT phone_number FROM people WHERE name = "Bruce";
-- PHONE NUMBER = (367) 555-5533

SELECT name FROM people WHERE phone_number =
(SELECT receiver FROM phone_calls WHERE year = 2021 AND month = 7 and day = 28 AND duration < 60 AND caller = "(367) 555-5533");
-- ACCOMPLICE = ROBIN 
