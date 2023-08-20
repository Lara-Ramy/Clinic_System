#include <stdio.h>
#include<stdlib.h>

#include "data.h"



 struct patient* linear_search(struct patient *head, int ID){
    struct patient *temp = head;
    while(temp!=NULL){
        if (temp->ID == ID){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
 }

struct patient* insert_beginning(struct patient** head, char* name, int age, char gender, int ID){

    if (linear_search(*head, ID) == NULL){
        struct patient* p = (struct patient*)malloc(sizeof(struct patient));

        p-> age = age;
        p->gender = gender;
        p->ID = ID;

        int i = 0;

        for (i = 0; name[i] != '\0'; i++){
            p->name[i] = name[i];
        }
        p->name[i] = '\0';

        p->next = *head;

        *head = p;
        return *head;

        }
    else{
    	printf("The ID is already in the list. \n");
    	return *head;
    }

 }

struct patient* insert_middle(struct patient* head, int ID_prev, char* name, int age, char gender, int ID){
    if (linear_search(head, ID) == NULL){
            struct patient* p_prev = linear_search(head, ID_prev);
        if (p_prev != NULL){
            struct patient* p = (struct patient*)malloc(sizeof( struct patient));

            p-> age = age;
            p->gender = gender;
            p->ID = ID;

            int i = 0;

            for (i = 0; name[i] != '\0'; i++){
                p->name[i] = name[i];
            }
            p->name[i] = '\0';

            p->next = p_prev ->next;

            p_prev->next = p;

            return p;

        }
    }
}

struct patient* insert_end(struct patient* head, char* name, int age, char gender, int ID){
	if (linear_search(head, ID)){
		struct patient* p = (struct patient*)malloc(sizeof(struct patient));

		p-> age = age;
		p->gender = gender;
		p->ID = ID;
		p->next = NULL;

		struct patient* last = head;

		if(head == NULL){
			head = p;
			return p;
		}

		while (last->next != NULL){
			last = last->next;
		}

		last->next = p;

		return p;


	}
}

void edit_data(struct patient* p, char* name, int age, char gender){
	p->age = age;
	p->gender = gender;
	int i = 0;
	for (i = 0; name[i] != '\0'; i++){
		p->name[i] = name[i];
	}
	p->name[i] = '\0';
}
