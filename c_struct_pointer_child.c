#include <stdio.h>


typedef struct Classroom{
    int students;
    int year;
    char home_teacher[20];
    
} classroom;

typedef struct Student{
    char name[20];
    int age;
    classroom class; // vlagane na strukturi
} student;


void print_classroom_info(classroom* class) // some pros for using pointers i can think of is for saving memory by not allocating more
                                            // by creating new vars in the functions but using the memory we have already allocated
                                            // with POINTERS we also modify the original structs and other objects, we dont have to 
                                            // create separate returning functions -> we create a function to modify an already
                                            // existing object - NOT a copy of it
                                            // without pointers dynamic allocation will not exist in C
{
    printf("\n ----- \n");
    printf("Student count: %d\n", class->students);
    printf("Starting year: %d\n", class->year);
    printf("Home teacher: %s\n", class->home_teacher);
}


int main()
{

    classroom physics = {.students = 20, .year = 2025, .home_teacher = "Ivan Ivanov"};
    classroom science = {.students = 15, .year = 2024, .home_teacher = "Lora Apostolova"};
    classroom math = {.students = 22, .year = 2026, . home_teacher = "Filip Panaiotov"};

    classroom* ptr_physics = &physics;
    ptr_physics->students = 29; // -> does the deredefencing of the memory for us
    (*ptr_physics).year = 2015; // THEY ARE THE EXACT SAME, we have the actual struct value and we can access its members
    // if we try to *ptr_physics.students -> the compiler reads it as *(ptr_physics.students) , but ptr_physics is a pointer, not a struct object
    // so it becomes invalid

    print_classroom_info(&physics);
    print_classroom_info(&science);
    print_classroom_info(&math);

    student stud1;

    stud1.age = 18;
    strcpy(stud1.name, "Ivan Ivanov");
    stud1.class.year = 2025;

    student* ptr_stud1 = &stud1;

    ptr_stud1->class.year = 2020; // holy moly

    classroom first_year[10]; // array of structs -> first_year = {[20, 2021, "Ivan Petrov"], [16, 2024, "Stoyan Stoyanov"], ...}

    first_year[0].year = 2020;
    first_year[1].year = 2021;

    return 0;
}