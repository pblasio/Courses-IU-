//programer: pbaby
// program: double functions into a main function! so cool, and if statements:max function to locate the biggest value between two numbers
#include <stdio.h>\
#include <stdlib.h>

double cube (double num){
       double result = num * num * num;
       return result;
}

int main(){
    printf("Anwser: %f ", cube(35.5));
    return 0;
}
}


// new program 

int max(int num1, int num2,int num3){
    int result;
    if(num1 >= num2 && num1 >= num3){
            result = num1;
    }
    else if(num2 >= num1 && num2 >= num3){
         result = num2;
    }
    else{
         result = num3;
    }
            
    // && logical operator for and in an if  statement 
    // or operator "||" for the if statements
    // print true and false for outputs
    // negattion operator in front of a if statement like "if(!(3 > 2){" then the printed statemnt will read false
    
    return result;
}

int main(){
    printf("%d", max(1,2,3));
    return 0;
}
    

