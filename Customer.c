#include <stdio.h>
#include <stdlib.h>
#include "Genreal.h"
#include "Customer.h"
void initCustomer(Customer* c) {
	c->name = getStrExactName("Enter Customer name");
	if (!c->name)
		return;
}
void printCustomer(const Customer* c) {
	printf("Name: %s\n", c->name);
}
void freeCustomer(Customer* c) {
	free(c->name);
}