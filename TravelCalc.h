#ifndef HEADER_H
#define HEADER_H
#include <math.h>
#include <string.h>

/**********************************************************

/**********************************************************
*/

/// clears buffer
void clearBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

/// retruns a value rounded to the nearest cent
double roundNearestCent(double amount){
    return (round(amount*100))/100;
}

// converts 24 hr clock into 12 hr clock. Also returns if it's AM or PM time
double TimeConvert(double time, char *AMPM){
    double result = time > 11.59 ? (time > 12.59 ? (time - 12.00) : time) : (time < 1.00 ? time + 12.00 : time);
    strcpy(AMPM, time > 11.59 ? "PM" : "AM" );
    return result;
}

/*
displayTotal()
Pre: @param: d_t, a_t, t_exp, t_a_exp, t_reim, t_amo
Post: Displays the total expenses, allowable expenses,
reimbursement, and the amount saved. No returns
*/
void displayTotal(int t_days, double d_t, double a_t, 
                double t_exp, double t_a_exp, double t_reim, double t_amo, char *AMPM){
    double time_convert;
    printf("\n\n************************************************************");
    printf("\nTotal days on trip: %d\n", t_days);
    time_convert = TimeConvert(d_t, AMPM);
    printf("\nTime of departure: %.2f = %.2f %s\n", d_t, time_convert, AMPM);
    time_convert = TimeConvert(a_t, AMPM);
    printf("\nTime of arrival: %.2f = %.2f %s\n", a_t, time_convert, AMPM);
    printf("\nTotal expenses: $%.2f\n", roundNearestCent(t_exp));
    printf("\nTotal allowable expenses: $%.2f\n", roundNearestCent(t_a_exp));
    printf("\nTotal reimbursement: $%.2f\n", roundNearestCent(t_reim));
    printf("\nTotal amount saved: $%.2f\n", roundNearestCent(t_amo));
     printf("\n\n************************************************************");

}

/**
inputValid_days()
Pre: None
Post: @returns an acceptable input for days
*/
int inputValid_days(){
    int days;
    scanf("%d", &days);
    while(days <= 1){
        printf("\nInvalid days input. Try again: ");
        fflush(stdout);
        scanf("%d", &days);
    }
    clearBuffer();
    return days;
}

/**
inputValid_depart()
Pre: None
Post: @returns an acceptable input for departure time
*/
double inputValid_departarrive(){
    double time;
    scanf("%lf", &time);
    while(time < 0 || time > 23.59 || (float)(time - floor(time)) > 0.59){
        printf("\nInvalid time input. Try again: ");
        fflush(stdout);
        scanf("%lf", &time);
    }
    clearBuffer();
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
    scanf("%c", &result);
    fflush(stdout);
    while(result != 'Y' && result != 'y' && result != 'N' && result != 'n'){
        printf("\nInvalid choice input. Try again: ");
        clearBuffer();
        scanf("%c", &result);
    }
    clearBuffer();
    return result;
}

double inputValid_amounts(){
    double result;
    scanf("%lf", &result);
    while(result < 0){
        printf("\nInvalid amount input. Try again: ");
        fflush(stdout);
        scanf("%lf", &result);
    }
    clearBuffer();
    return result;
}


/*setTotalDays()
Pre: @param t_days
Post: Sets the total days of the trip
*/
void setTotalDays(int *t_days){
    printf("\nHow many days will you be traveling? ");
    *t_days = inputValid_days();
}

/**
setArrDepTime()
Pre: @param t_depart, @param t_arrive
Post: Sets the departure and arrival time
*/
void setArrDepTime(double *t_depart, double *t_arrive){
    printf("\nWhat time is the departure on the first day(00.00-11.59 -AM-, 12.00-23.59 -PM-)?(00.00 - 23.59): ");
    *t_depart = inputValid_departarrive();
    printf("\nWhat time is the arrival on the last day(00.00-11.59 -AM-, -12.00-23.59 PM-)?(00.00 - 23.59): ");
    *t_arrive = inputValid_departarrive();

}

/**
getRoundTripAirFare()
Pre: @param t_exp
Post: Adds up the expenses if there's any round-trip
*/
void getRoundTripAirFare(double *t_exp){
    printf("\nWill there be a round trip airfare? (Y/N): ");
    char check = inputValid_char();
    if (check == 'Y' || check == 'y'){;
        printf("\nEnter the price of the airfare: ");
        double price = inputValid_amounts();
        *t_exp += price;
    }
}

/**
getCarRentals()
Pre: @param t_exp
Post: Adds up the expenses if there's any round-trip
*/
void getCarRentals(double *t_exp){
printf("\nWill there be car rentals? (Y/N): ");
    char check = inputValid_char();
    if (check == 'Y' || check == 'y'){;
        printf("\nEnter the price of the rentals: ");
        double price = inputValid_amounts();
        *t_exp += price;
    }
}

/**
getPrivateCar()
Pre: @param t_exp
Post: Adds up the expenses if there's any private car used
*/
void getPrivateCar(double *t_exp){
    const float VEHICLE_EXPENSE = 0.27;
    printf("\nWill you be using a private car? (Y/N): ");
    char check = inputValid_char();
    if (check == 'Y' || check == 'y'){;
        printf("\nEnter the number of miles driven: ");
        double num_mi = inputValid_amounts();
        *t_exp += (num_mi * VEHICLE_EXPENSE);
    }
}

/**
getParkingFees()
Pre: @param t_days, t_exp, t_a_exp, t_reim, t_amo
Post: Adds up the expenses
*/
void getParkingFees(int t_days, double *t_exp, double *t_a_exp, double *t_reim, double *t_amo){
    
    const double PARKING_RATE = 6; 
    
    printf("\nDid you have any parking expenses? (Y/N): ");
    char choice = inputValid_char();

    if (choice == 'y' || choice == 'Y')
    {
        printf("\nEnter parking expenses: ");
        double parkingFee = inputValid_amounts();

        *t_exp += parkingFee;
        *t_a_exp += PARKING_RATE * t_days;

        if (parkingFee < PARKING_RATE * t_days)
            *t_amo += (PARKING_RATE * t_days) - parkingFee;
        else
            *t_reim += parkingFee - (PARKING_RATE * t_days);
    }

    }
    



/**
getTaxiFees()
Pre: @param t_days, t_exp, t_a_exp, t_reim, t_amo
Post: Adds up the expenses
*/
void getTaxiFees(int t_days, double *t_exp, double *t_a_exp, double *t_reim, double *t_amo){

    const double TAXI_RATE = 10;

    printf("\nDid you have any taxi expenses? (Y/N): ");
    char choice = inputValid_char();

    if (choice == 'Y' || choice == 'y')
    {
        printf("\nEnter taxi expenses: ");
        double taxiFees = inputValid_amounts();

        *t_exp += taxiFees;
        *t_a_exp += TAXI_RATE * t_days;

        if (taxiFees < TAXI_RATE * t_days)
            *t_amo += (TAXI_RATE * t_days) - taxiFees;
        else
            *t_reim += taxiFees - (TAXI_RATE * t_days);

        
    }

}

/**
getConferencedSemiFees()
Pre: @param t_exp
Post: Adds up the expenses
*/
void getConferencedSemiFees(double *t_exp){
    printf("\nDid you attend to any conference or seminar registration? (Y/N): ");
    char user_choice = inputValid_char();
    if(user_choice == 'Y' || user_choice == 'y'){
        printf("\nEnter the fee: ");
        *t_exp += inputValid_amounts();
    }
}

/**
getHotelFees()
Pre: @param t_days, t_exp, t_a_exp, t_reim, t_amo
Post: Adds up the expenses
*/
void getHotelExpenses(int t_days, double *t_exp, double *t_a_exp, double *t_reim, double *t_amo){
    
    const double HOTEL_RATE = 90;

    printf("\nDid you have any hotel expenses? (Y/N): ");
    char choice = inputValid_char();


    if (choice == 'y' || choice == 'Y')
    {
        printf("\nEnter hotel expenses: ");
        double hotelExpense = inputValid_amounts();


        *t_exp += hotelExpense;
        *t_a_exp += HOTEL_RATE * t_days;

        if (hotelExpense < HOTEL_RATE * t_days)
            *t_amo += (HOTEL_RATE * t_days) - hotelExpense;
        else
            *t_reim += hotelExpense - (HOTEL_RATE * t_days);
    }

}

/**
set_reim_saved()
Pre: @param t_reim, t_saved, t_a_exp, Allowable, mealfee
Post: Adds up the reim, saved, and allowable expenses based on the allowable meal time
*/
void set_reim_saved(double *t_reim, double *t_saved, double *t_a_exp, double Allowable, double mealfee){
    *t_a_exp += Allowable;
    if(mealfee > Allowable)
        *t_reim += (mealfee - Allowable);
    else if(mealfee <= Allowable)
        *t_saved += mealfee;
}

/**
getMealFees()
Pre: @param d_time, a_time, t_exp, t_a_exp, t_reim, t_amo
Post: Adds up the expenses
*/
void getMealFees(double d_time, double a_time, double *t_exp, double *t_a_exp, double *t_reim, double *t_saved){
    const double B_Allowable = 9.00,
                 L_Allowable = 12.00,
                 D_Allowable = 16.00;
    
    double meal_fees;

    printf("\nDid you eat upon departure flight? (Y/N): ");
    char user_choice = inputValid_char();

    if(user_choice == 'Y' || user_choice == 'y'){
        printf("\nEnter the cost of your meal: ");
        meal_fees = inputValid_amounts();
        *t_exp += meal_fees;
        if(d_time < 7)
            set_reim_saved(t_reim, t_saved, t_a_exp, B_Allowable, meal_fees);
        else if(d_time >= 7 && d_time < 12)
            set_reim_saved(t_reim, t_saved, t_a_exp, L_Allowable, meal_fees);
        else if(d_time >= 12 && d_time < 18)
            set_reim_saved(t_reim, t_saved, t_a_exp, D_Allowable, meal_fees);
        else if(d_time >= 18)
            *t_reim += meal_fees;
        
        user_choice = '\n';
    }

    printf("\nDid you eat meal when upon arrival flight? (Y/N): ");
    user_choice = inputValid_char();

    if(user_choice == 'Y' || user_choice == 'y'){
        printf("\nEnter the cost of your meal: ");
        meal_fees = inputValid_amounts();
        *t_exp += meal_fees;
        if(a_time <= 8)
            *t_reim += meal_fees;
        else if(a_time > 8 && a_time <= 13)
            set_reim_saved(t_reim, t_saved, t_a_exp, B_Allowable, meal_fees);
        else if(a_time > 13 && a_time <= 19)
            set_reim_saved(t_reim, t_saved, t_a_exp, L_Allowable, meal_fees);
        else if(a_time > 19)
            set_reim_saved(t_reim, t_saved, t_a_exp, D_Allowable, meal_fees);
        
        user_choice = '\n';
    }
    
    

}

#endif
