// Programmer: Phenzi B
// Program: salary.c 
// Course: csci-291

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define ADMINISTRATOR 'A'
#define STAFF 'S'
#define HOURLY 'H'
#define ADJUNCT 'J'
#define REGULAR_FACULTY 'R'
#define TEACHING_ASSISTANT 'T'

// Function prototypes
void printInstructions();
void processInput(char type, double param1, double param2);
void printReport();
double calculateMonthlySalary(char type, double param1, double param2);
double calculateMonthlyPay(char type, double param1, double param2);

// Variables to store totals and counts
double totalAdminSalary = 0, totalAdminPay = 0, countAdmin = 0;
double totalStaffSalary = 0, totalStaffPay = 0, countStaff = 0;
double totalHourlySalary = 0, totalHourlyPay = 0, countHourly = 0;
double totalAdjunctSalary = 0, totalAdjunctPay = 0, countAdjunct = 0;
double totalFacultySalary = 0, totalFacultyPay = 0, countFaculty = 0;
double totalTASalary = 0, totalTAPay = 0, countTA = 0;

int main() {
    char command;
    printInstructions();
    while (1) {
        printf("Enter payroll data: ");
        scanf(" %c", &command);

        if (command == '?' || command == 'q' || 'Q') {
            break;
        }

        char type;
        double param1, param2;
        switch (command) {
            case 'A':
                scanf("%lf", &param1);
                processInput(ADMINISTRATOR, param1, 0);
                break;
            case 'S':
                scanf("%lf %lf", &param1, &param2);
                processInput(STAFF, param1, param2);
                break;
            case 'H':
                scanf("%lf %lf", &param1, &param2);
                processInput(HOURLY, param1, param2);
                break;
            case 'J':
                scanf("%lf", &param1);
                processInput(ADJUNCT, 0, param1);
                break;
            case 'R':
                scanf("%lf %lf", &param1, &param2);
                processInput(REGULAR_FACULTY, param1, param2);
                break;
            case 'T':
                scanf("%lf %lf", &param1, &param2);
                processInput(TEACHING_ASSISTANT, param1, param2);
                break;
            default:
                printf("Invalid command. Type '?' for instructions.\n");
        }
    }

    printReport();
    return 0;
}

void printInstructions() {
    printf("Enter payroll data in the format:\n");
    printf("A salary\n");
    printf("S salary overtime_hours\n");
    printf("H hourly_rate hours_worked\n");
    printf("J credit_hours\n");
    printf("R salary overload_credits\n");
    printf("T courses total_hours\n");
    printf("Type '?' for instructions.\n");
    printf("Type 'q' or 'Q' to quit and print the report.\n");
}

void processInput(char type, double param1, double param2) {
    double monthlySalary = calculateMonthlySalary(type, param1, param2);
    double monthlyPay = calculateMonthlyPay(type, param1, param2);

    switch (type) {
        case ADMINISTRATOR:
            totalAdminSalary += monthlySalary;
            totalAdminPay += monthlyPay;
            countAdmin++;
            break;
        case STAFF:
            totalStaffSalary += monthlySalary;
            totalStaffPay += monthlyPay;
            countStaff++;
            break;
        case HOURLY:
            totalHourlySalary += monthlySalary;
            totalHourlyPay += monthlyPay;
            countHourly++;
            break;
        case ADJUNCT:
            totalAdjunctSalary += monthlySalary;
            totalAdjunctPay += monthlyPay;
            countAdjunct++;
            break;
        case REGULAR_FACULTY:
            totalFacultySalary += monthlySalary;
            totalFacultyPay += monthlyPay;
            countFaculty++;
            break;
        case TEACHING_ASSISTANT:
            totalTASalary += monthlySalary;
            totalTAPay += monthlyPay;
            countTA++;
            break;
    }
}

double calculateMonthlySalary(char type, double param1, double param2) {
    switch (type) {
        case ADMINISTRATOR:
        case STAFF:
            return param1 / 12;
        case HOURLY:
            return 20 * param1 * 4;  // 20 normal hours per week over 4 weeks
        case ADJUNCT:
            return (param2 / 3) * 8500 / 5;  // $8500 for every 3 credit hours over 5 months
        case REGULAR_FACULTY:
            return param1 / 10;
        case TEACHING_ASSISTANT:
            return 500 * param1;  // $500 per course per month
        default:
            return 0;
    }
}

double calculateMonthlyPay(char type, double param1, double param2) {
    double basePay = calculateMonthlySalary(type, param1, param2);
    switch (type) {
        case ADMINISTRATOR:
            return basePay;
        case STAFF:
            if (param2 > 10) {
                printf("Warning: Overtime hours capped at 10. Excess ignored.\n");
                param2 = 10;
            }
            return basePay + (param2 * (param1 / (12 * 160)) * 1.5);
        case HOURLY:
            if (param2 > 100) {
                printf("Warning: Total hours worked capped at 100. Excess ignored.\n");
                param2 = 100;
            }
            double normalHours = param2 <= 80 ? param2 : 80;
            double overtimeHours = param2 > 80 ? param2 - 80 : 0;
            return (20 * param1 * 4) + (overtimeHours * param1 * 1.25);
        case ADJUNCT:
            if (param2 > 9) {
                printf("Warning: Credit hours capped at 9. Excess ignored.\n");
                param2 = 9;
            }
            return (param2 / 3) * 8500 / 5;  // $8500 for every 3 credit hours over 5 months
        case REGULAR_FACULTY:
            return basePay + ((param2 / 3) * 8500 / 5);
        case TEACHING_ASSISTANT:
            if (param2 > 50) {
                printf("Warning: Total hours worked capped at 50. Excess ignored.\n");
                param2 = 50;
            }
            double taNormalHours = param2 <= 40 ? param2 : 40;
            double taOvertimeHours = param2 > 40 ? param2 - 40 : 0;
            double payPerCourse = (param1 * 2500) / 5;
            double totalPayForWork = (param2 / (4 * 10)) * (param1 * 2500);
            return payPerCourse + (taOvertimeHours * (2500 / (4 * 10)));
        default:
            return 0;
    }
}

void printReport() {
    printf("Employee Type       Avg Monthly Salary       Avg Monthly Pay\n");
    printf("Administrator       %.2f                      %.2f\n", totalAdminSalary / (countAdmin ? countAdmin : 1), totalAdminPay / (countAdmin ? countAdmin : 1));
    printf("Staff               %.2f                      %.2f\n", totalStaffSalary / (countStaff ? countStaff : 1), totalStaffPay / (countStaff ? countStaff : 1));
    printf("Hourly              %.2f                      %.2f\n", totalHourlySalary / (countHourly ? countHourly : 1), totalHourlyPay / (countHourly ? countHourly : 1));
    printf("Adjunct             %.2f                      %.2f\n", totalAdjunctSalary / (countAdjunct ? countAdjunct : 1), totalAdjunctPay / (countAdjunct ? countAdjunct : 1));
    printf("Regular Faculty     %.2f                      %.2f\n", totalFacultySalary / (countFaculty ? countFaculty : 1), totalFacultyPay / (countFaculty ? countFaculty : 1));
    printf("Teaching Assistant  %.2f                      %.2f\n", totalTASalary / (countTA ? countTA : 1), totalTAPay / (countTA ? countTA : 1));
}
