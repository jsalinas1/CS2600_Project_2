# Project 2 Travel Expenses
## Team members
| NAME            | Task            |
| --------------- | --------------- |
| Jezreel Salinas  |  main.c, validinput check, display total, meals, fix group bug |
| Kien Nguyen      |  RoundTrip, CarRentals, PrivateCar |
| Laurence Garcia  |  Setting Time of Arrival and Departure, and Day of trips |
| Andy             |  Hotel, parking, Taxi  |

## Functions needed for this project
- displayTotal()
- setTotalDays()
- setArrDepTime()
- getRoundTripAirFare()
- getCarRentals()
- getPrivateCar()
- getParkingFees()
- getTaxiFees
- getConferencedSemiFees()
- getHotelFees()
- getMealFees()

## Helper Function
- clearBuffer() : Clears buffer
- roundNearestCent() : Rounds the totals in the nearest cents
- TimeConvert() : converts a 24 hour time into 12 hour time
- inputValid_days() : Checks and validates the input for days. Returns the correct value
- inputValid_departarrive() : Checks and validates the input for departure and arrival time. Returns the correct value
- inputValid_char() : Checks and validates input for Yes and No question. Returns either 'Y' or 'y' or 'N' or 'n'
- inputValid_amounts() : Checks and validates input for entering the amount for each totals. Returns the correct amount
- set_reim_saved() : Sets the total allowable, reimbursement and saved. This help reduce the repetition of the same statement in each if statements.
