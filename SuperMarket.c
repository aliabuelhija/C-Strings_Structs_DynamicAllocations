#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SuperMarket.h"
#include "Genreal.h"
#include "address.h"
#include "Product.h"
#include "ShoppingCart.h"
#include "ShoppingItem.h"
void initSuperMarket(SuperMarket* s) {
	s->name = getStrExactName("Enter SuperMarket Name\n ");
	int index;
	do {
		index = initAddress(&s->address);
	}
	while (index!=1);
	s->customersArr = NULL;
	s->customersNum = 0;
	s->ProductsArr = NULL;
	s->productNum = 0;

}
void printSuperMarket(const SuperMarket* s) {
	printf("%s\n", s->name);
	printAddress(&s->address);
	for (int i = 0; i < s->customersNum; i++) {
		printCustomer(&s->customersArr[i]);
	}
	printf("there are %d customers\n", s->customersNum);
	for (int i = 0; i < s->productNum; i++) {
		printProduct(s->ProductsArr[i]);
	}
	printf("there are %d products\n", s->productNum);

	}
void freeCustomerArr(Customer* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		freeCustomer(&arr[i]);
	}
}
void freeProductArr(Product** arr, int size) {
	for (int i = 0; i < size; i++)
	{
		free(&arr[i]);

	}
}
void freeSuperMarket(SuperMarket* s) {
	free(s->name);
	freeAddress(&s->address);
	free(&s->address);
	freeCustomerArr(s->customersArr,s->customersNum);
	free(s->customersArr);
	freeProductArr(s->ProductsArr, s->productNum);
	free(s->ProductsArr);
}
int addProductToMarket(SuperMarket* s) {
	Product* p = (Product*)malloc(sizeof(Product));
	if (!p)
		return 0;
	printf("Enter product barcode should be exactly 7 length \n only uppercase case\n letter and 3 to 5 digits\n  ");
	scanf("%s", &p->barcode);
	for (int i = 0; i < s->productNum; i++)
	{
		if (strcmp(s->ProductsArr[i]->barcode, p->barcode) == 0) {
			int amount;
			printf("enter the amount that you want to add\n");
			scanf("%d", &amount);
			s->ProductsArr[i]->amount = s->ProductsArr[i]->amount + amount;
			return 1;
		}
	}
	if (initProduct(p) == 0)
		return 0;
	s->ProductsArr = (Product**)realloc(s->ProductsArr, (s->productNum + 1) * sizeof(Product*));
	if (!s->ProductsArr)
		return 0;
	s->ProductsArr[s->productNum] = p;
	s->productNum++;
	return 1;
}
int addCustomerToSuperMarket(SuperMarket* s)
{
	Customer c;
	initCustomer(&c);
	s->customersArr = (Customer*)realloc(s->customersArr,(s->customersNum+1)*sizeof(Customer));
	if (!s->customersArr)
		return 0;
	s->customersArr[s->customersNum] = c;
	s->customersNum++;
	return 1;
}
void printProductByType(const SuperMarket* s) {
	int option = -1;
	printf("\n\n");
	while (option<0 || option> eNofTypes) {
		printf("Please enter one of following types\n");
		printf("0 for Shelf\n 1 for Frozen\n 2 for Fridge\n 3 for FruitVegtable\n ");
		scanf("%d", &option);
	}
	for (int i = 0; i < s->productNum; i++)
	{
		if (option == s->ProductsArr[i]->type)
			printProduct(s->ProductsArr[i]);
	}
}
void buyProduct(SuperMarket* s) {
	if (s->customersNum==0||s->productNum==0)
	{
		printf("there is no customer or products in the super market\n");
		return ;
	}
	printCustomersArr(s->customersArr,s->customersNum);
	char* name = getStrExactName("who is shopping? enter customer name\n");
	if (checkCustomerName(name, s) == 0) {
		printf("error can't find this customer\n");
		return ;
	}
	char barcode[BARCODE_LENGTH];
	ShoppingCart cart;
	char choise;
	int index;
	Product* p = NULL;
	initShoppingCart(&cart);
	do {
		printf("Do you want to make a shopping? y/Y anything else will exit\n");
		scanf("%c", &choise);
		if (choise != 'y' && choise != 'Y') {
			break;
		}
		getchar();
		printProductArr(s->ProductsArr, s->productNum);
			printf("enter product barcode Code should be of 7 length exactly\n UPPERCASE letter and digits\n Must have 3 to 5 digits\n");
			myGets(barcode, BARCODE_LENGTH);
			 p = findProduct(barcode, s);
			if (p != NULL) {
				 index = checkIfItemAlreadyAdded(findProduct(barcode, s)->name, &cart);
				if (index != -1) {
					fixAmount(p, cart.ShoppingIteamArr[index]);
				}
				else	{
					addShoppingItem(&cart, p);
					fixAmount(p, cart.ShoppingIteamArr[cart.count - 1]);
				}
				getchar();
			}
	}while (choise == 'y' || choise == 'Y');
	printShoppingCart(&cart);
	printf("the price %s : %f", name,sumPrice(&cart));
	freeShoppingCart(&cart);
}
int checkCustomerName( char* name,const SuperMarket* s) {
	for (int i = 0; i < s->customersNum; i++)
	{
		if (strcmp(s->customersArr[i].name, name) == 0)
			return 1;
	}
	free(name);
	return 0;
}
Product* findProduct(const char* barcode,const SuperMarket* s) {
	for (int i = 0; i < s->productNum; i++)
	{
		if (strcmp(s->ProductsArr[i]->barcode, barcode) == 0) {
			return s->ProductsArr[i];
		}
	}
	printf("no product with barcode you enterted\n");
	return NULL;
}
int checkIfItemAlreadyAdded(const char* name,const  ShoppingCart* c) {

	for (int i = 0; i < c->count; i++) {
		if (strcmp(c->ShoppingIteamArr[i]->name, name) == 0) {
			return i;
		}
	}
	return -1;
}
void printCustomersArr(const Customer* customersArr, const int size) {
	printf("there are %d listed customers\n", size);
	for (int i = 0; i < size; i++) {
		printCustomer(&customersArr[i]);
	}
}
void printProductArr(const Product** productArr, const int size) {
	printf("there are %d products\n", size);
	for (int i = 0; i < size; i++) {
		printProduct(productArr[i]);
	}
}
void fixAmount(Product* p, ShoppingItem* c) {
	if (p->amount > 0) {
		printf("enter the ammount\n");
		int amount;
		scanf("%d", &amount);
		if (p->amount >= amount) {
			c->amount += amount;
			p->amount -= amount;
			printf("added to cart!\n");
			return;
		}
		printf("amount you want is bigger than amount in supermarket\n");
		return;
	}
	printf("no amount in supermarket\n");
}