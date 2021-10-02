#include <stdio.h>
#include "TravelCalc.h"


int main(){
    /// Declaration assignments

    int total_days;
    char AM_PM[3];
    double depart_time, arrival_time,
        total_expenses = 0, total_allowable_expenses = 0,
        total_reimbursement = 0, total_amount_saved = 0;
    setTotalDays(&total_days);
    setArrDepTime(&depart_time, &arrival_time);
    getRoundTripAirFare(&total_expenses);
    getCarRentals(&total_expenses);
    getPrivateCar(&total_expenses);
    getParkingFees(total_days, &total_expenses, &total_allowable_expenses, &total_reimbursement, &total_amount_saved);
    getTaxiFees(total_days, &total_expenses, &total_allowable_expenses, &total_reimbursement, &total_amount_saved);
    getConferencedSemiFees(&total_expenses);
    getHotelExpenses(total_days, &total_expenses, &total_allowable_expenses, &total_reimbursement, &total_amount_saved);
    getMealFees(depart_time, arrival_time, &total_expenses, &total_allowable_expenses, &total_reimbursement, &total_amount_saved);

    displayTotal(total_days, depart_time, arrival_time, total_expenses,
                 total_allowable_expenses, total_reimbursement, total_amount_saved, AM_PM);
    return 0;
}