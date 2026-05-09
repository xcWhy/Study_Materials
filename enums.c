#include <stdio.h>

enum Size
{
    Small,
    Medium = 31,
    Large = 35,
    ExtraLarge = 39
};

int main()
{
    enum Size shoeSize, shoeSize2;

    shoeSize = Small;
    shoeSize2 = Large;

    printf("%d", shoeSize); // prints the index of the element
    printf("%d", shoeSize2); // prints the value next to the element


    return 0;
}