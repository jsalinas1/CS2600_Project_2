#include <stdio.h>

/**********************************************************
displayTotal()
Pre: @param: d_t, a_t, t_exp, t_a_exp, t_reim, t_amo
Post: Displays the total expenses, allowable expenses,
reimbursement, and the amount saved. No returns
*/

void displayTotal(t_days,d_t, a_t, t_exp, t_a_exp, t_reim, t_amo){
    printf("We made it");
}
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