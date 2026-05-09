// MY LIST

//1 zad

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Course{

    char name[51];
    char start_date[11]; // in C [10] ONLY goes up to 9 symbols + \0, thats why we need it to [11] so it can GO UP TO 10 symbols + \0
    int lectures;
    float price;

} course;


int main()
{
    // dannite se syhranqvat v binaren fail courses.bin

    FILE* fpb; // file pointer for binary file

    fpb = fopen("courses.bin", "rb"); // we start at the beggining of the file
    if (!fpb)
    {
        printf("Error opening file courses.bin!");
        return 1;
    }

    fseek(fpb, 0, SEEK_END);
    if (fseek != 0) // if its successful it returns a 0
    {
        printf("Error with fseek on courses.bin!");
        fclose(fpb);
        return 1;
    }

    int file_size = ftell(fpb); // it returns the byte the pointer is pointing at which is equal to the size of the file
    if (ftell < 0)
    {
        printf("Error with ftell on courses.bin!");
        fclose(fpb);
        return 1;
    }

    int n = file_size / sizeof(course); // we get the count of all elements in the binary file 

    rewind(fpb); // we set the pointer at the start of the file for just in case im not sure if its necessary

    course* courses = (course*) malloc (n * sizeof(course)); // we create a dynamic array with the size of the binary file
    if (!courses)
    {
        printf("Error with allocating memory!");
        fclose(fpb);
        return 1;
    }

    int fread_elements = fread(courses, sizeof(course), n, fpb); // we put the blocks of memory into the array with fread
                                                            // which returns an integer of how many elements it has successfully read
    if (fread_elements != n) // if they dont match throw an error
    {
        printf("Error with fread on courses.bin!");
        fclose(fpb);
        free(courses);
        return 1;
    }


    // ... vikane na funkcii


    free(courses);
    fclose(fpb);
    return 0;
}


