#include <stdio.h>
#include <string.h> // to be able to use and access the string functions

// learning about 4 string functions - strlen(), strcpy(), strcat(), strcmp()

int main()
{
    char language[] = "WOWW Stringss";
    printf("%s\n", language);

    int str_len;
    str_len = strlen(language); // we can get the int lenght of a string without the \0 ending symbol

    printf("The lenght of %s is equal to: %d\n", language, str_len);
    printf("The count is also: %zu by using directly the return value of the functions strlen!", strlen(language)); // %u


    char food[] = "Hot Dogss";
    char best_food[strlen(food)]; // so the two strings have equal sizes

    strcpy(best_food, food); // used to copy one string to another - destination string, source string

    printf("\n\nThe best food is: %s", best_food);


    char text1[] = "Hey, ";
    char text2[] = "How are you?";

    strcat(text1, text2); //concatenation - combining two strings together - destination string, string to be added - add text2 to text1

    printf("\n%s", text1);


    char text3[] = "abcd";
    char text4[] = "efgh";

    int result = strcmp(text3, text4); // strcmp is a function which compares two strings

    printf("\nThe result of comparison is: %d\n", result); // the functions return 0 IF the strings ARE identical
                                                        // and returns random number or -1 IF the string ARE NOT identical 



    char text[] = "Meow Cat Meow";

    char *ptr = strchr(text, 'C'); // pri pyrvata srehta s tozi character v stringa i vryshta pointer sys ostanalata chast ot stringa ot char
                                    // ptr sochi kym mqstoto na sreshtnatiq char

    if (ptr != NULL)
    {
        printf("%s\n", ptr); // kogato go printirame - to printira ot char do kraq na stringa
    }

    int index = ptr - text; // ako iskame indexa, koga e sreshtnat za pyrvi pyt chara
    printf("Sreshtata na C se namira na index: %d", index); 

    

    char textt[] = "I love cats";

    char *ptr2 = strstr(textt, "love"); // strstr(s1, s2); - връща указател към първото срещане на s2 в s1.

    if (ptr != NULL) // i dvete funkcii vryshtat NULL ako ne e namereno syvpadenie (strchr, strstr)
    {
        printf("\n%s\n", ptr2);
    }


    char texttt[] = "Programming";

    char *p1 = strchr(texttt, 'g');
    char *p2 = strstr(texttt, "gram");

    printf("%s\n", p1);
    printf("%s\n", p2);


    printf("\n--- Taskk ---\n");

    char first_name[20];
    char last_name[20];

    printf("Input your first name: ");
    fgets(first_name, sizeof(first_name), stdin);

    printf("Input your last name: ");
    fgets(last_name, sizeof(last_name), stdin);

    if (strcmp(first_name, last_name) == 0)
    {
        printf("Both of your names are identical? lol\nThere are no larger strings");
    }

    else
    {
        if (strlen(first_name) > strlen(last_name))
        {
            printf("Your first name is longer than your last name: %s > %s", first_name, last_name);
        }
        else
        {
            printf("Your last name is longer than your first name: %s < %s", first_name, last_name);
        }
    }

    return 0;

}