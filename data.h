#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

struct patient{
    char name[50];
    int age;
    char gender;
    int ID;
    struct patient *next;
};

struct patient* linear_search(struct patient *head, int ID);
struct patient* insert_beginning(struct patient** head, char* name, int age, char gender, int ID);
struct patient* insert_middle(struct patient* head, int ID_prev, char* name, int age, char gender, int ID);
struct patient* insert_end(struct patient* head, char* name, int age, char gender, int ID);

void edit_data(struct patient* p, char* name, int age, char gender);

#endif // DATA_H_INCLUDED
