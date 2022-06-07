#ifndef __CUSTOMER__
#define __CUSTOMER__
typedef struct
{
	char* name;

}Customer;

void initCustomer(Customer* c);
void printCustomer(const Customer* c);
void freeCustomer(Customer* c);
#endif