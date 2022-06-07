#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Product.h"
#include "Genreal.h"

const char* ProductType[eNofTypes] = { "Shelf", "Frozen", "Fridge", "FruitVegtable"};
int initProduct(Product* p) {
	if (checkBarcodeLength(p->barcode) == 0) {
		return 0;
	}
	if (checkDigitsInBarcode(p->barcode) == 0) {
		return 0;
	}
	if(checkBarcodeUppercase(p->barcode)==0) {
		return 0;
	}
	getchar();
	printf("enter product name up to 19 chars\n");
	myGets(p->name, NAME_LENGTH);
	p->type = getProductType();
	printf("Enter product price and number of items ");
	scanf("%f %d",&p->price,&p->amount);
	return 1;
}
eProductType getProductType() {
	int option=-1;
	printf("\n\n");
	while (option<0 || option> eNofTypes) {
		printf("Please enter one of following types\n");
		for (size_t i = 0; i < eNofTypes; i++)
		{
			printf("%d for %s\n", i, ProductType[i]);
		}
		scanf("%d", &option);
	}
	return (eProductType)option;
}
void printProduct(const Product* p) {
printf("Product name: %s barcode: %s Type: %s Price: %f items in stock %d \n" ,p->name, p->barcode, ProductType[p->type], p->price, p->amount);
}
int checkBarcodeLength(const char* barcode) {
	int len1 = strlen(barcode);

	if (len1 == 7) {
		return 1;
	}
	return 0;
}


int checkDigitsInBarcode(const char* barcode) {
	int counter = 0;
	int len = strlen(barcode);
	for (int i = 0; i < len; i++) {
		if (isdigit(barcode[i])) {
			counter++;
		}
	}
	if (counter >= 3 && counter <= 5) {
		return 1;
	}
	else {
		return 0;
	}
}

int checkBarcodeUppercase(const char* barcode){
	int len = strlen(barcode);
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (barcode[i] >= 'a' && barcode[i] <= 'z' )
			return 0;
		
		if ((barcode[i] >= 'A' && barcode[i] <= 'Z') || isdigit(barcode[i]))
			count++;
}
	if (len == count)
		return 1;
	else {
		return 0;
	}
}