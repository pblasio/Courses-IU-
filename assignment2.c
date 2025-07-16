/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//programmer: Phenzi b
// program: salary.c 
// course: csci-291



#include <stdio.h>
#include <string.h>
int main()
{
    char code; // Change: Removed array declaration
    int m_salary, o_hours, p_sold, w_hours, w_salary, h_salary, a_income, t_income;
    char vacation[2], married[2]; // Change: Added array size for vacation and married

    printf("Input employee type:\n");
    scanf(" %c", &code); // Change: Added space before %c to consume any leading whitespaces

    printf("Input marital status:\n");
    scanf(" %c", married); // Change: Added space before %c

    int value1;
    int value2;

    value1 = strcmp(married, "y");
    value2 = strcmp(vacation, "y"); // Change: Added initialization for value2

    switch (code) {
        case 'A':
        case 'S': // Combine cases with the same code
            printf("Input monthly salary:\n");
            scanf("%d", &m_salary);
            printf("Input overtime working hours:\n");
            scanf("%d", &o_hours);
            a_income = m_salary * 12;
            t_income = a_income + (0.25 * a_income);

            if (value1 == 0) {
                if (a_income > 32000) {
                    t_income = 0.75 * a_income;
                } else {
                    t_income = 0.9 * a_income;
                }
            } else {
                if (a_income > 64000) {
                    t_income = 0.75 * a_income;
                } else {
                    t_income = 0.9 * a_income;
                }
            }
            break;

        case 'E':
            printf("Input monthly salary:\n");
            scanf("%d", &m_salary);
            printf("Input overtime working hours:\n");
            scanf("%d", &o_hours);
            printf("Taking a vacation this year?:\n");
            scanf(" %c", vacation); // Change: Added space before %c
            printf("Products sold this year:\n");
            scanf("%d", &p_sold);

            a_income = (m_salary * 12) + (600 * p_sold);

            if (value2 == 0) {
                a_income = a_income - (0.5 * a_income);
            }

            t_income = a_income + (0.25 * a_income);

            if (value1 == 0) {
                if (a_income > 32000) {
                    t_income = 0.75 * a_income;
                } else {
                    t_income = 0.9 * a_income;
                }
            } else {
                if (a_income > 64000) {
                    t_income = 0.75 * a_income;
                } else {
                    t_income = 0.9 * a_income;
                }
            }
            break;

        case 'P':
            printf("Input weekly salary:\n");
            scanf("%d", &w_salary);
            printf("Input overtime working hours:\n");
            scanf("%d", &o_hours);
            printf("Products sold this year:\n");
            scanf("%d", &p_sold);

            a_income = (w_salary * 4) + (600 * p_sold);

            t_income = a_income + (0.25 * a_income);

            if (value1 == 0) {
                if (a_income > 32000) {
                    t_income = 0.75 * a_income;
                } else {
                    t_income = 0.9 * a_income;
                }
            } else {
                if (a_income > 64000) {
                    t_income = 0.75 * a_income;
                } else {
                    t_income = 0.9 * a_income;
                }
            }
            break;

        case 'H':
            printf("Input hourly salary:\n");
            scanf("%d", &h_salary);
            printf("Input weekly working hours:\n");
            scanf("%d", &w_hours);

            a_income = (h_salary * 10 * 4);

            if (value1 == 0) {
                if (a_income > 32000) {
                    t_income = 0.75 * a_income;
                } else {
                    t_income = 0.9 * a_income;
                }
            } else {
                if (a_income > 64000) {
                    t_income = 0.75 * a_income;
                } else {
                    t_income = 0.9 * a_income;
                }
            }
            break;

        default:
            printf("Error in input\n");
            return 1; // Change: Added return statement to end the program in case of an error
    }

    printf("This employee's annual income is $ %d before tax and $ %d after tax\n", a_income, t_income); // Change: %d instead of %ls
    return 0; // Change: Added return statement at the end of the program
}
