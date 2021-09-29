#include <stdio.h>
#include "TravelCalc.h"


int main(){
    /// Declaration assignments

    int total_days;

    double depart_time, arrival_time,
        total_expenses = 0, total_allowable_expenses = 0,
        total_reimbursement = 0, total_amount_saved = 0;

    displayTotal(total_days, depart_time, arrival_time, total_expenses,
                 total_allowable_expenses, total_reimbursement, total_amount_saved);
    return 0;
}