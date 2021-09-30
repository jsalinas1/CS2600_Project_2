#ifndef HEADER_H
#define HEADER_H
#include <math.h>

/**********************************************************
displayTotal()
Pre: @param: d_t, a_t, t_exp, t_a_exp, t_reim, t_amo
Post: Displays the total expenses, allowable expenses,
reimbursement, and the amount saved. No returns
*/

void displayTotal(int t_days, double d_t, double a_t, 
                double t_exp, double t_a_exp, double t_reim, double t_amo){
    printf("\nTotal days on trip: %d\n", t_days);
    printf("\nTotal days on trip: %d\n", t_days);
    printf("\nTotal days on trip: %d\n", t_days);
    printf("\nTotal days on trip: %d\n", t_days);
    printf("\nTotal days on trip: %d\n", t_days);
    printf("\nTotal days on trip: %d\n", t_days);
    printf("We made it");
}

/**
inputValid_days()
Pre: None
Post: @returns an acceptable input for days
*/
int inputValid_days(){
    int days;
    fflush(stdout);
    scanf("%d", &days);
    while(days < 0){
        printf("Invalid days input. Try again: ");
        fflush(stdout);
        scanf("%d", &days);
    }
    return days;
}

/**
inputValid_depart()
Pre: None
Post: @returns an acceptable input for departure time
*/
double inputValid_departarrive(){
    double time;
    fflush(stdout);
    scanf("%f", &time);
    while(time < 0 || time > 23.59 || time - floor(time) > 0.59){
        printf("Invalid days input. Try again: ");
        fflush(stdout);
        scanf("%f", &time);
    }

    return time;
}



/**
inputValid_char()
Pre: None
Post: @returns true if Yes, false otherwise
*/
char inputValid_char(){
    ///Checks if input letter is Y or N, otherwise, make an error and tell the user
    /// to re-enter. 
    char result;
    fflush(stdout);
    scanf("%c", &result);
    while(result != 'Y' && result != 'y' && result != 'N' && result != 'n'){
        printf("Invalid days input. Try again: ");
        fflush(stdout);
        scanf("%c", &result);
    }
    return result;
}

/*setTotalDays()
Pre: @param t_days
Post: Sets the total days of the trip
*/
void setTotalDays(int *t_days){
    
}

/**
setArrDepTime()
Pre: @param t_depart, @param t_arrive
Post: Sets the departure and arrival time
*/
void setArrDepTime(double *t_depart, double *t_arrive){
    /// 
}

/**
getRoundTripAirFare()
Pre: @param t_exp
Post: Adds up the expenses if there's any round-trip
*/
void getRoundTripAirFare(double *t_exp){

}

/**
getCarRentals()
Pre: @param t_exp
Post: Adds up the expenses if there's any round-trip
*/
void getCarRentals(double *t_exp){

}

/**
getPrivateCar()
Pre: @param t_exp
Post: Adds up the expenses if there's any private car used
*/
void getPrivateCar(double *t_exp){

}

/**
getParkingFees()
Pre: @param t_days, t_exp, t_a_exp, t_reim, t_amo
Post: Adds up the expenses
*/
void getParkingFees(int t_days, double *t_exp, double *t_a_exp, double *t_reim, double *t_amo){

}



/**
getTaxiFees()
Pre: @param t_days, t_exp, t_a_exp, t_reim, t_amo
Post: Adds up the expenses
*/
void getTaxiFees(int t_days, double *t_exp, double *t_a_exp, double *t_reim, double *t_amo){

}

/**
getConferencedSemiFees()
Pre: @param t_exp
Post: Adds up the expenses
*/
void getConferencedSemiFees(double *t_exp){

}

/**
getHotelFees()
Pre: @param t_days, t_exp, t_a_exp, t_reim, t_amo
Post: Adds up the expenses
*/
void getHotelExpenses(int t_days, double *t_exp, double *t_a_exp, double *t_reim, double *t_amo){

}

/**
getMealFees()
Pre: @param d_time, a_time, t_exp, t_a_exp, t_reim, t_amo
Post: Adds up the expenses
*/
void getMealFees(double d_time, double a_time, double *t_exp, double *t_a_exp, double *t_reim, double *t_amo){

}

#endif