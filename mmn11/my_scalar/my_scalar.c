#include <stdio.h>
#include "data.h"


int dotProduct(int v[], int u[], int length);
void helloUser();
int getLength();


int main(){
    int i,size,dotProductValue;
    int vector1[maxLength],vector2[maxLength];
    helloUser();
    size = getLength();
    printf("Insert the \"first vector\" components.\nAfter each \"component\" of the vector1 press the \"Enter\" key\n");
    for(i = 0; i < size;  i++)
        scanf("%d", &vector1[i]);
    printf("Insert the \"second vector\" components.\nAfter each \"component\" of the vector press the \"Enter\" key\n");
    for(i = 0; i < size;  i++)
        scanf("%d", &vector2[i]);
    dotProductValue=dotProduct(vector1,vector2,size );
    printf("\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
    printf("The dot product of the 2 vectors you entered is: %d",dotProductValue);
    printf("\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
    return dotProductValue;
}



void helloUser()
{
    printf("User instructions:\n==================\n"
           "Hello,\n"
    "this is a program that performs a scalar product of 2 vectors whose components are integer\n"
    "and which have the same length, the length will not be greater than %d.\n"
    "The program returns integer.\n==============================\n",maxLength);
}

int getLength()
{
    int size;
    printf("Enter the length of the vectors you want to multiply.\n"
           "The input numbers in this program should be at base 10.\n"
           "When you have finished entering the number, press the Enter key.\n");
    scanf("%d", &size);
    return size;
}

int dotProduct(int v[], int u[], int length)
{
    int i,result = 0;
    for (i = 0; i < length; i++)
        result += v[i]*u[i];
    return result;
}


