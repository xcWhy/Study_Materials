#include <stdio.h>

int main()
{
    // 3 steps - open the file, perform file operation, close the file
    // fgets() -> the destination where the string will go, the size, the way of reading the string -stdin? -from memory/file?

    FILE* f_pointer;
    FILE* f_pointer2;

    f_pointer = fopen("file2.txt", "r"); // r - read, w - write, fopen - will return NULL if the file doesnt exist

    char content[1000];
    char content2[1000];

    if (f_pointer == NULL)
    {
        printf("File didnt open!");
    }
    else
    {
        printf("File opened successfully!\n");
        fgets(content, 1000, f_pointer); // we get and store the text in a var, fget - can read only one sentence at a time
        printf("\n%s", content);

        printf("\n");

        fclose(f_pointer);
        f_pointer = fopen("file2.txt", "r"); // if i want to get to the front of the file again I can close and reopen the file in read mode

        while (fgets(content2, 1000, f_pointer))  // when we open the file the read function makes the pointer go through the file and when we stop 
                                                // it stays there pointing where it stopped, and continueing from there
        {
            printf("%s", content2);
        }

        // printf("what do u point at: %c", *f_pointer);   
    }

    f_pointer2 = fopen("wow.txt", "w"); // w - write, it creates a file if it doesnt find it; when we open it deletes the file after every opening
    
    
    fclose(f_pointer); // to close the file after we have done using it
    
    fputs("yeyyy\n", f_pointer2);
    fputs("u wrote in me!", f_pointer2);

    fclose(f_pointer2);

    return 0;
}