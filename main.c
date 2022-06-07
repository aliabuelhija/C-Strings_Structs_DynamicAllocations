#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "SuperMarket.h"
typedef enum
{
	eShowSuperMarket, eAddProduct, eAddCustomer, eCustomerShopping,
	ePrintProductByType, eNofOptions
} eMenuOptions;

const char* str[eNofOptions] = { "Show SuperMarket", "Add Product",
								"Add Customer", "Customer Shopping,",
								"Print Product By Type"};

#define EXIT			-1
int menu();

int main()
{
	SuperMarket super;
	initSuperMarket(&super);
	int option;
	int stop = 0;

	do
	{
		option = menu();
		switch (option)
		{
		case eShowSuperMarket:
			printSuperMarket(&super);
			break;


		case eAddProduct:
			if (!addProductToMarket(&super))
				printf("Error adding product\n");
			break;

		case eAddCustomer:
		if(!addCustomerToSuperMarket(&super))
			printf("Error adding customer\n");

			break;

		case eCustomerShopping:
			buyProduct(&super);
			break;

		case ePrintProductByType:
			printProductByType(&super);
			break;

		case EXIT:
			printf("Bye bye\n");
			stop = 1;
			break;

		default:
			printf("Wrong option\n");
			break;
		}
	} while (!stop);

	freeSuperMarket(&super);
	return 1;
}

int menu()
{
	int option;
	printf("\n\n");
	printf("Please choose one of the following options\n");
	for (int i = 0; i < eNofOptions; i++)
		printf("%d - %s\n", i, str[i]);
	printf("%d - Quit\n", EXIT);
	scanf("%d", &option);
	//clean buffer
	char tav;
	scanf("%c", &tav);
	return option;
}