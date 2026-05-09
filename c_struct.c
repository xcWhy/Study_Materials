#include <stdio.h>
#include <string.h>

struct Person{
    double salary;
    int age;
};

struct Animal{
    char name[20];
    int age;
};

struct Company{
    char name[20];
    int employees;
} company1, company2; // we already initilize the struct vars => we will need to use strcpy to set the names of the structs

typedef struct Drink{
    float price;
    char name[20];
} drink; // so we dont use struct Drink => we use only drink

typedef struct Complex{
    double real;
    double imaginary;
} complex;


int main()
{
    struct Person person1; // struct Person -> is the var type, where person1 -> is the name of the var
    struct Person person2;

    person1.age = 25;
    person1.salary = 4321.78;

    printf("Age of person1: %d\n", person1.age);
    printf("Salary of person1: %.2f\n", person1.salary);    

    person2.age = 31;
    person2.salary = 7894.2;

    printf("Age of person2 %d\n", person2.age);
    printf("Salary of person2: %.2f\n", person2.salary);  
    
    
    struct Animal animal1 = {.age = 2, .name = "Charlie"};
    struct Animal animal2 = {.age = 1, .name = "Meow"};

    company1.employees = 1000;
    strcpy(company1.name, "Meow Company");

    printf("\nCompany1 name: %s", company1.name);

    company2.employees = 20;
    strcpy(company2.name, "Wow Company");


    drink drink1 = {.name = "Monster", .price = 1.65};
    drink drink2 = {.name = "Cappy", .price = 1};


    complex c1 = {.real = 21.87, .imaginary = 30};
    complex c2 = {.real = 13.34, .imaginary = 112.23};

    complex sum = {.real = c1.real + c2.real, .imaginary = c1.imaginary + c2.imaginary};

    printf("\nResult is %.2f + %.2fi", sum.real, sum.imaginary);


    return 0;
}