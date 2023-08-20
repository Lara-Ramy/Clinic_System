/*
 * reservations.c
 *
 *  Created on: Jul 26, 2023
 *      Author: larar
 */

#include "reservations.h"
#include "data.h"

struct reservations time_slots[5]
							   = {{0,t_0200},{0,t_0230}, {0,t_0300}, {0,t_0400}, {0,t_0430}};


char times_str[5][20] = {"02:00 pm", "02:30 pm", "03:00 pm", "04:00 pm", "04:30 pm"};


void print_reservations(void){
	printf("02:00 pm\t");
	printf("%d\n",time_slots[0].ID);

	printf("02:30 pm\t");
	printf("%d\n",time_slots[1].ID);

	printf("03:00 pm\t");
	printf("%d\n",time_slots[2].ID);

	printf("04:00 pm\t");
	printf("%d\n",time_slots[3].ID);

	printf("04:30 pm\t");
	printf("%d\n",time_slots[4].ID);


}

void print_available_reservations(void){
	for(int i = 0; i < 5; i++){
		if(time_slots[i].ID == 0){
			printf("%d. %s\n", i + 1, times_str[i]);
		}
	}
}

void print_patient_reservation(int ID){
	for(int i = 0; i < 5; i++){
		if(time_slots[i].ID == ID){
			printf("time reservation: %s\n", times_str[i]);
			return;
		}
	}
	printf("time reservation: none");
}

void add_reservations(int time_slot, int ID, struct patient *head){
	 if(time_slots[time_slot - 1].ID == 0){
		 if(linear_search(head, ID) != 0){
			 time_slots[time_slot - 1].ID = ID;
		 }
		 else{
			 printf("ID is incorrect.\n");
		 }
	 }
	 else{
		 printf("The time is already reserved");
	 }
}


void cancel_reservations(int ID){
	for(int i = 0; i < 5; i++){
		if(time_slots[i].ID == ID){
			time_slots[i].ID = 0;
			return;
		}
	}
	printf("The ID does not Exist \n");
}
