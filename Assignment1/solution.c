/*
*To run code:
*Type: gcc solution.c -o solution
*Type: ./solution
*/

#include <stdio.h> 
#include <string.h>

//TASK 1:
void compare_values(int x, int y)
{
    if(x>y){
        printf("X is largest! it's value is: %d\n", x);
    }
    if(y>x){
        printf("Y is largest! It's value is: %d\n", y);
    }

    if(x==y){
        printf("The values are equal!\n");
    }
    
}

//TASK 2:
void myTriangles(int number_of_lines)
{
    for(int i=1; i<=number_of_lines; i++){
        for(int j=0; j<i; j++){
            printf("*");
        }
        printf("\n");
    }
}

//TASK 3:
int myPrimeFactor(int number, int PrimeFactor)
{
    int result = number % PrimeFactor;

    if(result != 0){
        printf("%d is not a prime factor of %d\n", PrimeFactor, number);
        return 1;
    }
    if(result == 0){
        printf("%d is a prime factor of %d\n", PrimeFactor, number);
        return 0;
    }
}

//TASK 4:
void myNumbers(int startnumber, int endnumber)
{
    for(int i=startnumber; i<=endnumber; i++){
        if(i % 2 == 0){
                printf("%d is even and ", i);

                if(i%5 != 0){
                    printf("5 is not a prime factor\n");
                }
                else{
                    printf("5 is a prime factor!\n");
                }
            }
        if(i % 2 != 0){
            printf("%d is odd and ", i);

            if(i%5 != 0){
                printf("5 is not a prime factor\n");
            }
            else{
                printf("5 is a prime factor!\n");
            }
        }
    }
}

//TASK 5:
int myLog2(unsigned int number)
{
    int counter = 0;

    while(number>>1 > 0){
        counter++;
        number = number>>1;
    }
    printf("%d\n",counter);
}

//TASK 6:
void reverseString(char string[])
{
    printf("Original string: %s\n", string);
    int length = strlen(string);
    char *start = string;
    char *end = start + length -1;  //Minus 1 is to remove "NULL"


    //while loop
    while(end > start)
        {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
    printf("String after beeing reversed: %s\n", string);
}


int main()
{
    //compare_values(10, 5);
    //myTriangles(5);
    //myPrimeFactor(10, 9);
    //myNumbers(1,10);
    // myLog2(32);

    char string[] = "Magnus er kul";
    reverseString(string);
}

