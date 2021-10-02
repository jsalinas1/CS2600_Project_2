# Project 2 Travel Expenses
## Team members
| NAME            | Task            |
| --------------- | --------------- |
| Jezreel Salinas  |  main.c, validinput check, display total, meals, debugging duty|
| Kien Nguyen      |  RoundTrip, CarRentals, PrivateCar |
| Laurence Garcia  |  Setting Time of Arrival and Departure, and Day of trips |
| Andy             |  Hotel, parking, Taxi  |

## Functions needed for this project
- displayTotal() : outputs all total values to terminal
- setTotalDays() : asks and sets total day
- setArrDepTime() :  asks and sets arrival/departure time
- getRoundTripAirFare() : adds round trip fare to total
- getCarRentals() : add car rental fees to total
- getPrivateCar() : add private car fees to total, also adds the allowable amount
- getParkingFees() : add parking fees to total, also adds the allowable amount
- getTaxiFees() : add taxi fee to total, also adds the allowable amount
- getConferencedSemiFees() : add conference fees to total
- getHotelFees() : add hotel fees to total, also adds the allowable amount
- getMealFees() : ask for meal type prices on arrival and departure, also adds the allowable amount

## Helper Function
- clearBuffer() : Clears buffer
- roundNearestCent() : Rounds the totals in the nearest cents
- TimeConvert() : converts a 24 hour time into 12 hour time
- inputValid_days() : Checks and validates the input for days. Returns the correct value
- inputValid_departarrive() : Checks and validates the input for departure and arrival time. Returns the correct value
- inputValid_char() : Checks and validates input for Yes and No question. Returns either 'Y' or 'y' or 'N' or 'n'
- inputValid_amounts() : Checks and validates input for entering the amount for each totals. Returns the correct amount
- set_reim_saved() : Sets the total allowable, reimbursement and saved. This help reduce the repetition of the same statement in each if statements.
