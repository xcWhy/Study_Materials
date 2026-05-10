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


//2 zad
int count_treatment(treatment* treatments, int treatments_count, char patient_name[], char diagnosis[])
{
    int found_patient_diagnosis = 0;

    for (int i = 0; i < treatments_count; i++)
    {
        if (strcmp(treatments[i].patient_name, patient_name) == 0 && strcmp(treatments[i].diagnosis, diagnosis) == 0)
        {
            found_patient_diagnosis++;
        }
    }

    return found_patient_diagnosis;
}

//3 zad
treatment* add_new_treatment(treatment** treatments, int* treatments_count)
{
    treatment new_treatment;

    printf("id na epikriza: ");
    scanf("%d", &new_treatment.id);

    getchar(); // gets the next character from stdin, in our case would be \n , it returns the value of the chaaracter it has gotten
    
    printf("date: ");
    fgets(new_treatment.date, sizeof(new_treatment.date), stdin);

    printf("patien name: ");
    fgets(new_treatment.patient_name, sizeof(new_treatment.patient_name), stdin);

    printf("diagnosis: ");
    fgets(new_treatment.diagnosis, sizeof(new_treatment.diagnosis), stdin);
    

    treatment* temp = realloc(*treatments, ((*treatments_count)+1) * sizeof(treatment)); // *treatments !! - i must reallocate the actual dynamic array
                                                                                // not its actual address, but the address its pointing at
                                                                                // i need to reallocate it into the new var temp
    if (!temp)
    {
        printf("Error allocating memory!");
        return NULL;
    }

    *treatments_count += 1; // we put treatments_count AFTER the allocation, if it messes up, the treatment counts is incremented anyways

    *treatments = temp; // adresyt na pametta s dannite se premestil, prehvyrlqme pyrviq ukazatel, kym pyrviq element - treatments da sochi kym nego
                        // temp e adresyt na pyrviq element (otkydeto zapochva zadelenata pamet za elementite)
                        // treatements* e poleto s value - i v sluchaq e adres, adres koito trqbva da sochi otkyde zapochva pametta s dannite
                        
    (*treatments)[(*treatments_count)-1] = new_treatment;
    
    return *treatments; // vryshtame pokazatel kym pyrviq element na masiva s danni, (*treatments)
                        // not treatments - that just returns the address of the pointer - where the pointer is staying in the memory
                        // we need to return where its pointing to - the start of the array with struct elements
                        

}