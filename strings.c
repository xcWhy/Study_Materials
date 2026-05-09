#include <stdio.h>

int main()
{
    char str[] = "Meow"; // both strings are equal, \0 is added auto
    char str2[] = {'M', 'e', 'o', 'w', '\0'}; // \0 it helps the compiler to identify the end of the string

    printf("%s\n", str2);

    char str3[20];

    printf("Enter the meow: ");

    scanf("%s", &str3); // gets the user input until it encounters white space (space)
    printf("%s\n", str3);

    char c;
    scanf("%c", &c); // after scanf - in the buffre is left \n which is then recorded by the fgets

    char str4[20];

    printf("Enter full name meow: ");
    fgets(str4, sizeof(str4), stdin); // str4 - the name of the variable we will be putting our input in
                                        // sizeof(str4) - the size of our space in the array variable to put the characters in
                                        // stdin - standard input - we are taking input from the keyboard
                                        // fgets - gets the \n input from the keyboard 
    
    printf("%s\n", str4);

    char str5[20];

    printf("Enter full name meow 2: ");
    fgets(str5, sizeof(str5), stdin);
    printf("%s\n", str5);
    
    printf("the first character in str5 is: %c\n", str5[0]);

    printf("Which character are we changing in %s: ", str5);
    int c_num;
    scanf("%d", &c_num);

    scanf("%c", &c); // get the enter inputed from the keyboard

    printf("We are changing the %d character in %s - what would it be: ", c_num, str5);
    char new_char;
    scanf("%c", &new_char);

    str5[c_num-1] = new_char;

    printf("The new str5 looks like this: %s", str5);
    
    
    return 0;
}