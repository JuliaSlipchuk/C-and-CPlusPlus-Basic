#include <stdio.h>

typedef struct Person
{
    char* firstName;
    char* lastName;
} Person;

void print(Person person)
{
    printf("%s %s \n", person.firstName, person.lastName);
}

int main()
{

    Person person1 = {"Mary", "Smith"};
    print(person1);
    Person person2 = {"James", "Johnson"};
    print(person2);
    Person person3 = {"Patricia", "Williams"};
    print(person3);
    Person person4 = {"John", "Brown"};
    print(person4);

    return 0;
}
