#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "reservations.h"

int main(void)
{

	fflush(stdout);
	printf("\n\n\t\t\t Clinic Management System \n\n\n");
	int mode, pass, choice;

	char name[50], gender;
	int age, ID, time;

	struct patient* head = NULL;
	struct patient** head_ptr = &head;
	struct patient* p;

	while(1){
		printf("1. Admin Mode \n");
		printf("2. User Mode \n");
		printf("3. Exit \n\n\n");
		fflush(stdout);
		scanf("%d", &mode);

		switch(mode){
		case 1:
			int i = 0;
			do{
				printf("Please Enter Your Password \n");
				fflush(stdout);
				scanf("%d", &pass);
				i++;
			}while(i < 3 && pass != 1234);
			if (pass != 1234){
				exit(0);
			}
			printf("1. Add new patient \n");
			printf("2. Edit patient record \n");
			printf("3. Reserve a slot with the doctor \n");
			printf("4. Cancel reservation \n");
			printf("5. Exit \n\n\n");

			fflush(stdout);
			scanf("%d", &choice);

			if(choice == 1){

				printf("Name: ");
				fflush(stdout);
				scanf("%s",name);
				printf("\n");

				printf("Age: ");
				fflush(stdout);
				scanf("%d",&age);
				printf("\n");

				printf("ID: ");
				fflush(stdout);
				scanf("%d",&ID);
				printf("\n");

				printf("Gender: ");
				fflush(stdout);
				scanf(" %c", &gender);
				printf("\n");


				p = insert_beginning(head_ptr, name, age, gender, ID);

				printf("%s\n", p->name);

			}
			else if(choice == 2){
				printf("ID: ");
				fflush(stdout);
				scanf("%d",&ID);
				printf("\n");
				p = linear_search(head, ID);
				if(p == NULL){
					printf("Incorrect ID \n");
				}
				else{
					printf("Name: ");
					fflush(stdout);
					scanf("%s",name);
					printf("\n");

					printf("Age: ");
					fflush(stdout);
					scanf("%d",&age);
					printf("\n");

					printf("Gender: ");
					fflush(stdout);
					scanf(" %c", &gender);
					printf("\n");

					edit_data(p, name, age, gender);

					printf("%s\n", p->name);
				}
			}
			else if(choice == 3){
				print_available_reservations();
				printf("ID: ");
				fflush(stdout);
				scanf("%d",&ID);
				printf("\n");

				printf("Time: ");
				fflush(stdout);
				scanf("%d",&time);
				printf("\n");

				add_reservations(time, ID, head);

			}
			else if(choice == 4){
				printf("ID: ");
				fflush(stdout);
				scanf("%d",&ID);
				printf("\n");

				cancel_reservations(ID);
			}
			else if(choice == 5){
				exit(0);
			}

			break;
		case 2:
			printf("1. View patient record \n");
			printf("2. View today's reservations \n");
			printf("3. Exit \n\n\n");

			fflush(stdout);
			scanf("%d", &choice);

			if(choice == 1){
				printf("ID: ");
				fflush(stdout);
				scanf("%d",&ID);
				printf("\n");

				p = linear_search(head, ID);

				printf("Name: %s", p->name);
				printf("Age: %d", p->age);
				printf("Gender: %d", p->gender);
				printf("Name: %s", p->name);

				print_patient_reservation(ID);
			}
			else if(choice == 2){
				print_reservations();
			}

			break;
		case 3:
			exit(0);
		}

	}
//	struct patient* head = NULL;
//	struct patient** head_ptr = &head;
//  struct patient* p = insert_beginning(head_ptr, "lara", 23, 'f', 11234);
//  printf("%p\n", p->next);
//  printf("%p\n", head);

    return 0;
}
