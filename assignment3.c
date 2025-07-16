/* This is the assignment 3 program about the bloomington skate company and it will find the payroll for the commisoned employees*/
/* Name: Phenzi Blasio */
/* Course: CSCI291 */


#include <stdio.h
    /* standard input output library for functions like */
    /*printf and scanf that we need to implement the program 
// the constant values of the progam are to be defined below */




#define size_s
#define sal_com .125
#define prof_perc .45
#define prof_bonus_perc .1
#define tenure_bonus .05
#define decade 10
#define fed_tax .15
#define state_tax .05
#define soc_sec .075

int main(void){

        // to pass the values for month and year //

        int month;
        int year;
        scanf("%d",&month);
        scanf("%d",&year);

        void mnthString(int month{
        switch(month){
                case 1:
                        printf("January");
                        break;
                case 2:
                        printf("Feburary");
                        break;
                case 3:
                        printf("March");
                        break;
                case 4:
                        printf("April");
                        break;
                case 5:
                        printf("May");
                        break;
                case 6:
                        printf("June");
                        break;
                case 7:
                        printf("July");
                        break;
                case 8:
                        printf("August");
                        break;
                case 9:
                        printf("September");
                        break;
                case 10:
                        printf("October");
                        break;
                case 11:
                        printf("Novemember");
                        break;
                case 12:
                        printf("Decemember");
                        break;
        }

}
        // this forward will check for the values being in the array and the validity of the value through the boolean case */
        double sales_array[size_s];
        double tenur_array[size_s];
        bool zeros_entered = false;

        // forward the for loop will  check for the arrary size value  */

        for(int i = 0; i < size_s; i++){
                scanf("%le", &sales_array[i]);
                scanf("%le", &tenur_array[i]);

                if (sales_array[i] == 0 && tenur_array[i] == 0){
                        zeros_entered = true;
                        break;
                }
                // second if statement
                if(zeros_entered){
                        sales_array[i] = 0;
                        tenur_array[i] = 0;
                }

        }


        //more of the doubled function to populate the array values
        double mnthly_sales_t( double sales_array[]){
                double sum = 0;
                // for loop to check the iterated value and cycle through again
                for(int i = 0; i < size_s; i++){
                        sum += sales_array[i];
                }
                return sum;
        }
        double mnthly_profit(double sales_array[]){
                double sum_2 = mnthly_sales_t(sales_array);
                return sum2= prof_perc;
        }

        double employeeCommission(double sales_array[], int employee){
                double commision = sales_array[employee] * sal_com;
                return commision;
        }

        double employeeBonus(double sales_array[], double tenur_array[], int employee){
                int dec_tenur = tenur_array[employee] / decade;
                  double bonus = prof_bonus_perc +(dec_tenur *tenure_bonus);
                double totalBonus  = mnthly_profit(sales_array) *bonus;
                return totalBonus;
        }

        double gross_pay(double sales_array[],double tenur_array[], int employee){
                double commisson_pay = employeeCommision(sales_array,employee);
                double bonusPay = employeeBonus(sales_array,tenur_array,employee);
                double gross_pay = commision_pay + bonusPay;
                return gross_pay;
        }
        double net_profit_calc(double sales_array[],double tenur_array[]){
                // different bonus value here, the above is like totsal bonus, but thjis is toal_bonus to be differrent for the variable intialization
                // dont get confused!!!
                double bonus_total = 0;
                double profit = mnthly_profit(sales_array);
                for (int i =0; i < size_s; i++){
                        bonus_total  += employeeBonus(sales_array,tenur_array);}
                return profit - bonus_total;

        double generic_tax(double gross_pay,double tax){
                return gross_pay * tax;

        double state_withholding(double gross_pay){
                return generic_tax(gross_pay, state);
        }

        double federal_withholding(double gross_pay){
                return generic_tax(gross_pay,federal);
        }

        double individual_pay(double gross_pay){
                double tax_sum = state_withholding(gross_pay) + federal_withholding(gross_pay) + social_withholding(gross_pay);
                return gross_pay - tax_sum;
        }

        double my_round(double arg){
                return floor(( arg + .0051)*100)/100;

        }

        double monthly_sales = my_round(mnthly_sales_t(sales_array));
        double profit = my_round(mnthly_profit(sales_array));

        double emp_a_com = my_round(employee_commision(sales_array, 0));
        double emp_b_com = my_round(employee_commision(sales_array,1));
        double emp_c_com = my_round(employee_commision(sales_array, 2));
        double emp_d_com = my_round(employee_commision(sales_array, 3));
        double emp_e_com = my_round(employee_commision(sales_array, 4));

        double emp_a_bonus = my_round(employee_bonus(sales_array, tenur_array, 0));
        double emp_b_bonus = my_round(employee_bonus(sales_array, tenur_array, 1));
        double emp_c_bonus = my_round(employee_bonus(sales_array, tenur_array, 2));
        double emp_d_bonus = my_round(employee_bonus(sales_array, tenur_array, 3));
           double emp_a_fed = my_round(federal_withholding(gross_pay(sales_array,tenur_array, 0)));
        double emp_b_fed = my_round(federal_withholding(gross_pay(sales_array, tenur_array, 1)));
        double emp_c_fed = my_round(federal_withholding(gross_pay(sales_array, tenur_array, 2)));
        double emp_d_fed = my_round(federal_withholding(gross_pay(sales_array, tenur_array, 3)));
        double emp_e_fed = my_round(federal_withholding(gross_pay(sales_array, tenur_array, 4)));

        double emp_a_state = my_round(state_withholding(gross_pay(sales_array,tenur_array, 0)));
        double emp_b_state = my_round(state_withholding(gross_pay(sales_array,tenur_array, 1)));
        double emp_c_state = my_round(state_withholding(gross_pay(sales_array,tenur_array, 2)));
        double emp_d_state = my_round(state_withholding(gross_pay(slaes_array,tenur_array, 3)));
        double emp_e_state = my_round(state_withholding(gross_pay(sales_array,tenur_array, 4)));


        double emp_a_social = my_round(social_withholding(gross_pay(sales_array,tenur_array, 0)));
        double emp_b_social = my_round(social_withholding(gross_pay(sales_array,tenur_array ,1))):
        double emp_c_social = my_round(social_withholding(gross_pay(sales_array,tenur_array, 2)));
        double emp_d_social = my_round(social_withholding(gross_pay(sales_array,tenur_array, 3)));
        double emp_e_social = my_round(social_withholding(gross_pay(sales_array,tenur_array, 4)));

        double emp_a_net = my_round(individual_pay(gross_pay(sales_array,tenur_array, 0)));
        double emp_b_net = my_round(individual_pay(gross_pay(sales_array,tenur_array, 1)));
        double emp_c_net = my_round(individual_pay(gross_pay(sales_array,tenur_array, 2)));
        double emp_d_net = my_round(individual_pay(gross_pay(sales_array,tenur_array, 3)));
        double emp_e_net = my_round(individual_pay(gross_pay(sales_array,tenur_array, 4)));

        // This is where I 


        double total_commision = my_round((employeeCommision(sales_array,0) + employeeCommision(sales_array, 1) + employeeCommision(sales_array, 2) + employeeCommision(sales_array, 3) + employeeCommision(sales_array, 4));
        double total_bonus = my_round((employeeBonus(sales_array,tenur_array,0) + employeeBonus(sales_array,tenur_array, 1) + employeeBonus(sales_array,tenur_array,2) + employeeBonus(sales_array,tenur_array,3) + employeeBonus(sales_array,tenur_array,4));

         
         
        double total_fed =  my_round(federal_withholding(gross_pay(sales_array,tenur_array, 0))) + federal_withholding(gross_pay(sales_array,tenur_array,1)) + federal_withholding(gross_pay(sales_array,tenur_array, 2)) + federal_withholding(gross_pay(sales_array,tenur_array, 3)) + federal_withholding(gross_pay(sales_array,tenur_array,4));




        double total_state = my_round(state_withholding(gross_pay(sales_array,tenur_array, 0)) + state_withholding(gross_pay(sales_array,tenur_array,1)) + state_withholding(gross_pay(sales_array,tenur_array , 2)) + state_withholding(gross_pay(sales_array,tenur_array, 3)) + state_withholding(gross_pay(sales_array,tenur_array, 4));



        double total_social = my_round(social_withholding(gross_pay(sales_array,tenur_array,0)) + social_withholding(gross_pay(sales_array,tenur_array,1)) + social_withholding(gross_pay(sales_array,tenur_array, 2)) + social_withholding(gross_pay((sales_array,tenur_array,3)) + social_withholding(gross_pay(sales_array,tenur_array,4));
        double total_netpay = my_round(individual_netpay(gross_pay(sales_array,tenur_array, 0)) + individual_pay(gross_pay(sales_array, tenur_array, 1)) + individual_pay(gross_pay(sales_array,tenur_array,2)) + individual_pay(gross_pay(sales_array,tenur_array, 3)) + individual_pay(gross_pay(sales_array,tenur_array,4));

// this is for bonus points
        double company_netprofit = myround(mnthly_profit(sales_array) - (employeeBonus(sales_array,tenur_array, 0) + employeeBonus(sales_array,tenur_array, 1) + employeeBonus(sales_array,tenur_array,2) + employeeBonus(sales_array,tenur_array,3) + employeeBonus(sales_array,tenur_array,4)));

/// here is the printed output statement
print("MONTHLY STATEMENT");
monthforstring(month);

printf(" %d)\n" , year);
printf("%79s\n", "Bloomington Skating Company");
printf("%79s\n", "Bloomington, IN");
printf("%79s\n", "Phone: (812)-855-0000");
printf("Monthly Sales: $%.2f\n", monthlySales);
printf("Monthly Profit: $%.2f\n", profit);
printf("=======================================================================================\n");
printf("%-11s", "Name");
printf("%-13s", "Commission");
printf("%-12s", "Bonus");
printf("%-13s", "Fed W.");
printf("%-12s", "ST W.");
printf("%-10s", "FICA"0);
printf("Net Pay\n");
printf("======================================================================================\n");
printf("%-11s%-13.2f%-12.2f%-13.2f%-12.2f%-10.2f%.2f\n"), "Empl A:", empacom, empabonus, empafed, empastate,empasocial, empanet);
:e
printf("%-11s%-13.2f%-12.2f%-13.2f%-12.2f%-10.2f%.2f\n"), "Empl B:" empbcom, empbbonus, empbfed, empbstate, empbsocial, empbnet)
                                                                                           
