#include <stdio.h>
#include <stdlib.h>

int main()
{
    // malloc() - memory allocation - used to reserve a block of memory of the specified size
    // free() - to release the dynamically allocated memory 
    // realloc() - re-allocate, change the size of the allocated memory

    int n = 4;

    int* ptr;

    ptr = (int*) malloc (n * sizeof(int)); // it allocates 100 bytes of memory in the address, it stores the address of the first element
                                            // just like an array, so we can access the other blocks by going through the memory

    if (ptr == NULL)
    {
        printf("Memory cannot be allocated!");
        return 1;
    }

    printf("Input values in the memory: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr+i);
    }

    printf("Your values: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr+i));
    }

    ptr = realloc (ptr, (n+2) * sizeof(int)); // we add 2 bytes to the allocated memory AND the bytes information to it !! by using ptr
                                            // the function may move the memory block to a new location -> the content of the block is preserved
                                            // it returns a pointer to its beginning

    printf("\nInput 2 more values in the memory: \n");
    for (int i = n; i < n+2; i++)
    {
        scanf("%d", ptr+i);
    }

    printf("Your values: ");
    for (int i = 0; i < n+2; i++)
    {
        printf("%d ", *(ptr+i));
    }

    free(ptr);

    return 0;
}