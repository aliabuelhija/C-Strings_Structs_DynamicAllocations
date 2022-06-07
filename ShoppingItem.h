#ifndef __ITEM__
#define __ITEM__
#include "Product.h"
typedef struct
{
	char* name;
	float price;
	int amount;

}ShoppingItem;
void initShoppingItem(ShoppingItem* s, Product* p);
void printShoppingItem(const ShoppingItem* s);
void freeShoppingItem(ShoppingItem* s);

#endif