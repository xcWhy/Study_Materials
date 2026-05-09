#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Medicine{

    char name[30];
    char expiration[7];
    long long id;
    float price;
    int quantity;

}medicine;


// zad 2 funkciqta
medicine* filter_medicines(medicine* arr, int count, char exp_date[]) //exp_date = MM.GGGG
{
    medicine* arr_filter = (medicine*) malloc (count * sizeof(medicine));

    int arr_filter_index = 0;

    for (int i = 0; i < count; i++)
    {
        int year_diff = 0;

        if (strcmp(arr[i].expiration, exp_date) != 0)
        {
            for (int j = 3; j < 7; j++) // year check
            {
                if (arr[i].expiration[j] > exp_date[j]) // real_data > vyvedena data -> 2027 > 2025
                {
                    printf("izticha SLED datata");
                    year_diff = 1;
                    break;
                }
                else if (arr[i].expiration[j] < exp_date[j]) 
                {
                    printf("izticha PREDI datata");
                    arr_filter[arr_filter_index] = arr[i];
                    arr_filter_index++;
                    year_diff = 1;
                    break;
                }
            }
            
            if (!year_diff)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (arr[i].expiration[j] > exp_date[j]) // real_data > vyvedena data -> 05 > 02 -> 05.2027 > 02.2027
                    {
                        printf("izticha SLED datata");
                        break;
                    }
                    else if (arr[i].expiration[j] < exp_date[j]) 
                    {
                        printf("izticha PREDI datata");
                        arr_filter[arr_filter_index] = arr[i];
                        arr_filter_index++;
                        break;
                    }
                }
            }

        }

        else
        {
            printf("Datata na lekarstvo s id: %lld e ednakva s vkaranata data! Nevalidno.", arr[i].id);
        }        
        
    }

    if (arr_filter_index != 0) 
    {
        arr_filter = realloc(arr_filter, arr_filter_index * sizeof(medicine));
        return arr_filter;
    }

    else return NULL; 
}


//zad 3 funkciq




int main()
{   

    FILE* fpb;

    fpb = fopen("medicines.bin", "rb"); // otvarq faila ot nachaloto
    if (fpb == NULL)
    {
        printf("Error opening file!");
        return 1;
    }

    if (fseek(fpb, 0, SEEK_END) != 0) // (FILE* stream, long int offset - kolko byte-a da prezkochi,
                            //  origin - SEEK_SET(beggining of file), SEEK_CUR(current position of the pointer), SEEK_END(end of file)
                            // if successful the function return 0, otherwise it returns non zero value
    {
        printf("Error with fseek!");
        fclose(fpb);
        return 1;
    } // sled tazi funkciq kursora ni veche sochi v kraq na faila -> fseek - just sets the position indicator to a new position

    int file_size = ftell(fpb); // ftell - returns the current value of the position indicator of the stream
                                // for binary streams, this is the number of bytes from the beggining of the file
                                // for text files it can be used to restore the position to the same position later
    if (file_size < 0)
    {
        printf("Error with ftell!");
        fclose(fpb);
        return 1;
    }

    rewind(fpb); // da vyrnem indicatora v nachaloto na faila

    int medicine_struct_objects = file_size / sizeof(medicine);

    medicine* medicines = (medicine*) malloc (medicine_struct_objects * sizeof(medicine)); // it allocates medicine* type to the memory!
                                                                                        // we get the address of the memory where it has been allocated
    if (!medicines)
    {
        printf("Error allocating memory!");
        fclose(fpb);
        return 1;
    }

    fclose(fpb);
    free(medicines);
    return 0;
}