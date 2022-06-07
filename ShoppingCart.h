#ifndef __CART__
#define __CART__
#include "ShoppingItem.h"
typedef struct
{

	ShoppingItem** ShoppingIteamArr;
	int count;


}ShoppingCart;
void initShoppingCart(ShoppingCart* c);
void printShoppingCart(const ShoppingCart* c);
void freeShoppingIteamsArr(ShoppingItem** c, int size);
void freeShoppingCart(ShoppingCart* c);
float sumPrice(const ShoppingCart* c);
int addShoppingItem(ShoppingCart* c, Product* p);
#endif