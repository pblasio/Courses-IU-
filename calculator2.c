//programmer: p
// Program: better calculator 

#include <stdio.h>
#include <stdlib.h>

int main(){
    double num1;
    double num2;
    char op;
    
    printf("enter a number:");
    scanf("%lf", &num1);
    printf("enter operator add sub div or multi ");
    scanf " %c", &op);
    // when you have to scan f for a character value you have to put a space before the % sign becuz if not the program will throw u a bug 
    printf("enter another number:");
    scanf("%lf", &num2);
    
    if(op == '+'){
          printf("%f", num1 + num2);
    }
    else if(op == '-'){
          printf("%f",num1 - num2);
          
    }
    else if(op == '/'){
         printf("%f",num1/num2);
    }
    else if(op == '*');{
         printf("%f", num1*num2);
    }
    else{
         printf("not a mathematical operator please attempt to enter +,-,/,or* as the operator value for the function to pass");

    }
    return 0;
}
