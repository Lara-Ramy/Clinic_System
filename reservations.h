/*
 * reservations.h
 *
 *  Created on: Jul 26, 2023
 *      Author: larar
 */

#ifndef RESERVATIONS_H_
#define RESERVATIONS_H_

#include "data.h"

enum times{
	t_0200, t_0230, t_0300, t_0400, t_0430
};


struct reservations{
	int ID;
	enum times time;
};

void print_reservations(void);

void print_available_reservations(void);

void print_patient_reservation(int ID);

void add_reservations(int time_slot, int ID, struct patient *head);

void cancel_reservations(int ID);


#endif /* RESERVATIONS_H_ */
