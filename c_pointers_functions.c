#include <stdio.h>

void findValue(int *num)
{
    *num = 39;
}

void findSquare(int *num)
{
    *num = *num * *num;
}

int* plus(int *num)
{
    *num += 1;
    return num; // returns the address pointed by num
}

int *addNumber(int *num1, int *num2, int *sum) // sum is an int* type of a variable, so returning it requires the function to be of the same type
{
    *sum = *num1 + *num2;
    return sum; // we return the address
}

int main()
{
    int num = 25;

    findValue(&num);

    printf("The value of the number is: %d\n", num);

    int num2 = 55;
    findSquare(&num2);

    printf("The square of num2 is: %d\n", num2);

    int *num_address = plus(&num); // we have a created a pointer to store the returned result of the function 


    int number1 = 32;
    int number2 = 18;
    int sum;

    int *psum = addNumber(&number1, &number2, &sum);

    printf("Sum is: %d", *psum);

    // int* num; - int* is a different type of variable, such as float*, double*, char* and so on
    // if we make a function int meow() -> we can still return an integer number by returning -> return *pnum; but NOT an address -> return pnum;

    return 0;
}