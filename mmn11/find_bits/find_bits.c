#include <stdio.h>


void helloUser();
unsigned long getNumber();
unsigned long numberOfMatchingBits(unsigned long X, unsigned long Y);

int main()
{
    unsigned long X,Y;
    helloUser();
    printf("\n==============================\n");
    printf("Enter the X number you want to check\n");
    X = getNumber();
    printf("\n==============================\n");
    printf("Enter the Y number you want to check\n");
    Y = getNumber();
    numberOfMatchingBits(X, Y);
    return 0;
}

void helloUser()
{
    printf("User instructions:\n==================\n"
           "Hello,\nThis is a program that receives as input two long unsigned variables - x and y.\n"
           "The goal of the program is to find for variable x how many lit bits are in the same places as the "
           "lit bits in variable y\n"
           "The input numbers in this program should be at base 10.\n"
           "When you have finished entering the number, press the Enter key.\n");
}


unsigned long getNumber()
{
    unsigned long number;
    printf("The number should be in decimal format\nenter your number here:");
    scanf("%lu", &number);
    printf("The number U entered is:\n%29lu", number);
    return number;
}



unsigned long numberOfMatchingBits(unsigned long X, unsigned long Y) {
    unsigned long matching=0;
    while ((X > 0)&&(Y > 0))
        if ((X & 1) && (Y & 1)) {
            matching++;
            X = (X >> 1);
            Y = (Y >> 1);
        } else {
            X = (X >> 1);
            Y = (Y >> 1);
        }
    printf("\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
    printf("The number of matching lit bit in your two numbers is: \n %27lu",matching);
    printf("\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");

    return matching;

}
