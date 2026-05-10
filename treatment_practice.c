//1 zad

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Treatment{

    int id;
    char date[11];
    char patient_name[31];
    char diagnosis[51];

} treatment;

int main()
{
    FILE* fpb;

    fpb = fopen("history.bin", "rb");
    if (!fpb)
    {
        printf("Error opening file history.bin!");
        return 1;
    }

    if (fseek(fpb, 0, SEEK_END) != 0) // if it returns 0 - it was successful, fseek just sets the pointer to the put offset, returns 0
    {
        printf("Error with fseek on file history.bin!");
        fclose(fpb); // dont forget to close the file
        return 1;
    }

    int file_size = ftell(fpb); // ftell returns the byte size which the pointer is pointing at the moment
    if (file_size < 0)
    {
        printf("Error with ftell on file history.bin!");
        fclose(fpb); // dont forget to close the file
        return 1;
    }

    int n = file_size / sizeof(treatment);

    treatment* history = (treatment*) malloc (n * sizeof(treatment));
    if (!history)
    {
        printf("Error with allocating memory for history!");
        fclose(fpb);
        return 1; // dont forget the return!
    }

    // now that we have the allocated memory, lets put data in it!

    // ! because we've gone with fseek at the end of the file, we need to return the cursor at the start
    // so the fread command can read the binary file from the beggining and put in the allocated memory as blocks of bytes :)

    rewind(fpb);

    int fread_count = fread(history, sizeof(treatment), n, fpb);
    if (fread_count != n)
    {
        printf("Error putting data into allocated memory!");
        fclose(fpb);
        free(history);
        return 1;
    }

    // calling the functions

    fclose(fpb);
    free(history);
    return 0;
}