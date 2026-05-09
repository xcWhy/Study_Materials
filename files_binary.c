#include <stdio.h>

int main()
{

    // text files - Read, Write, Append, Read+, Write+, Append+
    //write - syzdava i trie failyt pri otvarqne
    //append - syzdava i dobavq kym faila

    // binary files - ReadB, WriteB, AppendB, ReadB+, WriteB+, AppendB+


    // fgetpos
    // fseek - if successful, the function returns 0
    // fsetpos
    // ftell
    // rewind

    // fread_elements = fread(void* ptr, size, count, FILE* stream); void* ptr - is the dynamic array will be using to store the elements


    // iskame da namerim goleminata na file -> s fseek namirame kraq na faila i tam ni se postavq kursora
    // sled tova s ftell - poluchavame kym koi byte sochi kursora - a tova shte e posledniqt byte vyv faila!
    // tozi posleden byte vyv faila ni e realno goleminata na faila v byte-ove
    // za da namerim kolko promenilvi ot tip strukturata Medicine imame vyv faila 
    // count = razmera na faila / sizeof(medicine) obekta -> taka znaem kolko objecta ot medicine imame v binarniq fail
    // toi ne e chetim -> zatova trqbva da go proverim i prebroim po tozi nachin


    // fscanf() - reads formatted data from the stream
    // fprintf(FILE* stream, "text %s", vars for the text) - za printirane vyv fail



    return 0;
}