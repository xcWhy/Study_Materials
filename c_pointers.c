#include <stdio.h>

void plus(int *ptr)
{
    // *ptr++; = *(ptr++) which goes 4 bytes forward in the memory
    // printf("Ptr??: %d\n", *ptr);
    *ptr += 1; // or (*ptr)++;
    // printf("Ptr2??: %d\n", *ptr);
}

void minus(int *ptr)
{
    // *ptr--; = *(ptr--); which ptr-- gets to another memory location, and the * search for a value there
    *ptr -= 1; // or (*ptr)--; - we get the value first in the brackets and the decrement it
}

int main()
{
    int age = 19;
    printf("%p\n", &age);

    // a pointer variable stores the memory of another variable, not the actual value

    int *ptr = &age; // it will be storing the address of another variable (reference)
                    // integer pointer named ptr is set to the address of age

    printf("Address: %p\n", ptr); // we print the address of the var which is pointing to
    printf("Value: %d\n", *ptr); // we access the value of the var to which the pointer is pointing to
                                // when its used alone it says - go to the address pointed to by the pointer and grab that value (dereference)  

    int y = *ptr; //integer named y is set to the thing pointed to by ptr, gives the value


    // change the value of a var using pointer var

    int new_age = 35;

    int *new_ptr = &new_age;

    *new_ptr = 40; // we change the value of the var by using the pointer accessing the memory

    printf("\nNew age is: %d", new_age);

    printf("\n--- Tests ---\n");

    int number = 5;
    int *pnumber = &number; 

    while (number != 0)
    {
        printf("Our count is: %d\nWhat are you doing(+/-): ", number);
        char symbol;
        scanf("%c", &symbol);

        char c;
        scanf("%c", &c);

        if (symbol == '+') plus(pnumber);
        else if (symbol == '-') minus(pnumber);
        else continue;

    }

    printf("Game over!\nNumber is %d!", number);

    return 0;

}