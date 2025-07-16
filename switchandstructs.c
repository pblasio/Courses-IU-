// program: switch statements and structs
//programmer: phenzi 
 
int main(){
    char grade = 'A';
    switch(grade){
                  case 'A': 
                       printf("you did great bestie");
                       // break goes in line with case statement info 
                       break;
                  case 'B':
                       printf(" its aourka");
                       break;
                  case 'C':
                       printf(" slay but no");
                       break;
                  case 'D':
                       printf(" mmhmm no");;
                       break;
                  case 'F':
                       printf(" silence");
                       break;
                  default:
                          // for everything that does not correlate to the parameters of the switch like i j k or whatever else
                          printf(" not an option bestie boos");
                          break;
                  }
}
// new program structs and other data types 
// using a struct to represent a student in the program
// putt attributes of student in curly brackets for structs 

struct Student{
       char name[50];
       char major[50];
       int age;
       double gpa;
};

int main(){
    struct Student student1;
    student1.age = 22'
    // to reference a number int or double the syntax is as such, label for struct container as in student1 then a . and then the descriptor within the container value such as gpa or age or credithours 
    
    student1.gpa = 3.5;
    // to reference a char or string value c cannot access it like the numerical values, it must be a strcopy and spaced as such below 
    strcpy( student1.name, "Jim");
    strcpy( student1.major, "CyberGlobal");
    // when printing use the "%s" instead of the "%c" to run the char attributes becuz they function underneath a string array 
    printf("%s", student1.name);
    // how to print ^^ omg so coooool
    
    
}
    
    
    
    
    
    
    
    return 0;
}
