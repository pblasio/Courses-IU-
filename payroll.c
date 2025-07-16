
/*phenzi blasio*/
/*assignment 3 payroll*/

#include <stdio.h>
#include <math.h> // Include the math library for rounding functions

#define EMPLOYEES 5

// Function prototypes
double calculate_total_sales(double sales[]);
double calculate_monthly_profit(double sales[]);
double calculate_commission(double sales);
double calculate_bonus(double sales, int tenure, double total_profit);
double calculate_net_profit(double profit, double total_bonus);
void calculate_withholdings(double gross_pay, double *fed_w, double *state_w, double *fica);
double calculate_net_pay(double gross_pay, double fed_w, double state_w, double fica);
void print_report(double sales[], int tenure[], double total_sales, double profit, int month, int year);
const char* get_month_name(int month);
double round_double(double value);

int main() {
    double sales[EMPLOYEES] = {0};
    int tenure[EMPLOYEES] = {0};
    int month, year;

    printf("Enter the numeric month and year of the report: ");
    scanf("%d %d", &month, &year);

    for (int i = 0; i < EMPLOYEES; i++) {
        printf("Enter sales and tenure for employee %d: ", i + 1);
        scanf("%lf %d", &sales[i], &tenure[i]);
        if (sales[i] == 0 && tenure[i] == 0) break; // early exit if fewer than 5 employees
    }

    double total_sales = calculate_total_sales(sales);
    double profit = calculate_monthly_profit(sales);
    
    print_report(sales, tenure, total_sales, profit, month, year);

    return 0;
}

const char* get_month_name(int month) {
    const char* months[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", 
                            "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
    if (month < 1 || month > 12) return "INVALID MONTH";
    return months[month - 1];
}

double round_double(double value) {
    return round(value * 100) / 100; // Round to 2 decimal places
}

void print_report(double sales[], int tenure[], double total_sales, double profit, int month, int year) {
    printf("\nMONTHLY STATEMENT (%s %d)\n", get_month_name(month), year);
    printf("                                                    Bloomington Skating Company\n");
    printf("                                                                Bloomington, IN\n");
    printf("                                                          Phone: (812)-855-0000\n");
    printf("MONTHLY SALES: $%.2f\n", total_sales);
    printf("MONTHLY PROFIT: $%.2f\n", profit);
    printf("===============================================================================\n");
    printf("Name       Commission   Bonus       Fed W.       ST W.       FICA      Net Pay\n");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < EMPLOYEES; i++) {
        if (sales[i] == 0) break;
        double commission = round_double(calculate_commission(sales[i]));
        double bonus = round_double(calculate_bonus(sales[i], tenure[i], profit));
        double gross_pay = commission + bonus;
        double fed_w, state_w, fica;
        calculate_withholdings(gross_pay, &fed_w, &state_w, &fica);
        double net_pay = round_double(calculate_net_pay(gross_pay, fed_w, state_w, fica));
        
        printf("Empl %c:    %.2f       %.2f      %.2f       %.2f       %.2f     %.2f\n", 'A' + i, commission, bonus, fed_w, state_w, fica, net_pay);
    }

    double total_commission = 0, total_bonus = 0, total_fed_w = 0, total_state_w = 0, total_fica = 0, total_net_pay = 0;
    for (int i = 0; i < EMPLOYEES; i++) {
        if (sales[i] == 0) break;
        total_commission += round_double(calculate_commission(sales[i]));
        total_bonus += round_double(calculate_bonus(sales[i], tenure[i], profit));
        double gross_pay = calculate_commission(sales[i]) + calculate_bonus(sales[i], tenure[i], profit);
        double fed_w, state_w, fica;
        calculate_withholdings(gross_pay, &fed_w, &state_w, &fica);
        total_fed_w += fed_w;
        total_state_w += state_w;
        total_fica += fica;
        total_net_pay += round_double(calculate_net_pay(gross_pay, fed_w, state_w, fica));
    }

    printf("-------------------------------------------------------------------------------\n");
    printf("Total      %.2f      %.2f     %.2f      %.2f      %.2f    %.2f\n",
           total_commission, total_bonus, total_fed_w, total_state_w, total_fica, total_net_pay);
    printf("-------------------------------------------------------------------------------\n");
    double net_profit = calculate_net_profit(profit, total_bonus);
    printf("Net Profit (Profit - Bonus): %.2f \n", net_profit);
    printf("John Doe, Branch Manager\n");
}

double calculate_total_sales(double sales[]) {
    double total_sales = 0;
    for (int i = 0; i < EMPLOYEES; i++) {
        total_sales += sales[i];
    }
    return total_sales;
}

double calculate_monthly_profit(double sales[]) {
    return calculate_total_sales(sales) * 0.45;
}

double calculate_commission(double sales) {
    return sales * 0.125;
}

double calculate_bonus(double sales, int tenure, double total_profit) {
    double profit_share = total_profit * 0.10;
    double tenure_bonus = (tenure / 10) * 0.05 * total_profit;
    return profit_share + tenure_bonus;
}

double calculate_net_profit(double profit, double total_bonus) {
    return profit - total_bonus;
}

void calculate_withholdings(double gross_pay, double *fed_w, double *state_w, double *fica) {
    *fed_w = round_double(gross_pay * 0.15);
    *state_w = round_double(gross_pay * 0.05);
    *fica = round_double(gross_pay * 0.075);
}

double calculate_net_pay(double gross_pay, double fed_w, double state_w, double fica) {
    return gross_pay - (fed_w + state_w + fica);
}
