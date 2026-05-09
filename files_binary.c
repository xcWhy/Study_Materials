#include <stdio.h>

int main()
{

    // text files - Read, Write, Append, Read+, Write+, Append+
    //write - syzdava i trie failyt pri otvarqne
    //append - syzdava i dobavq kym faila

    // binary files - ReadB, WriteB, AppendB, ReadB+, WriteB+, AppendB+


    // fgetpos
    // fseek
    // fsetpos
    // ftell
    // rewind


    // iskame da namerim goleminata na file -> s fseek namirame kraq na faila i tam ni se postavq kursora
    // sled tova s ftell - poluchavame kym koi byte sochi kursora - a tova shte e posledniqt byte vyv faila!
    // tozi posleden byte vyv faila ni e realno goleminata na faila v byte-ove
    // za da namerim kolko promenilvi ot tip strukturata Medicine imame vyv faila 
    // count = razmera na faila / sizeof(medicine) obekta -> taka znaem kolko objecta ot medicine imame v binarniq fail
    // toi ne e chetim -> zatova trqbva da go proverim i prebroim po tozi nachin



    return 0;
}