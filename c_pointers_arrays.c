#include <stdio.h>

void plus(int *arr)
{
    // (*arr)++;
    *arr += 1;
}

void minus(int *arr)
{
    (*arr)--; // (*arr) - tova e stoinostta, -- - namalqvame s 1 stoinostta v pametta
}


int main()
{
    int arr[5] = {1, 4, 6, 7, 8};

    printf("Elements of arr: \n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d = %p\n", arr[i], &arr[i]); // arr[i] == *(arr+i) and &arr[i] == arr+i
    }

    printf("Array address: %p\n", arr); // the address of the array is the same as the address of its first element
                                    // thats because the address of array always points to the first element of the array

    printf("Array address (address of second element): %p\n", arr+1); // this way we can access the memory of the second element

    *arr = 11; // we can change the elements of an array using pointers
    *(arr+4) = 88;


    printf("\n--- Testing ---\n");

    printf("How many elements do you want: ");
    int num;
    scanf("%d", &num);

    int new_arr[num];

    // printf("Inputing elements: ");
    
    for (int i = 0; i < num; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &new_arr[i]);
    }

    printf("\nlets play a game then!\n");

    char symbol;
    int index = 0;

    while (1)
    {
        if (index == num)
        {
            index = 0;
        }

        printf("Here is your arr: ");
        for (int i = 0; i < num; i++)
        {
            printf("%d ", new_arr[i]);
        }

        printf("\nWhats your choice(+ / -): ");
        scanf(" %c", &symbol);

        if (symbol == '+') plus(new_arr+index);
        else if (symbol == '-') 
        {
            minus(new_arr+index);
            if (new_arr[index] == 0)
            {
                printf("Game over!");
                break;
            }
        }
        else continue;

        index++;
    }




    return 0;
}