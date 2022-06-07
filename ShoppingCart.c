#include <stdio.h>
#include <stdlib.h>
#include "ShoppingCart.h"
#include "ShoppingItem.h"
#include "Genreal.h"
void initShoppingCart(ShoppingCart* c) {
	c->ShoppingIteamArr = NULL;
	c->count = 0;
}
void printShoppingCart(const ShoppingCart* c) {
	printf("There is %d items in shopping cart\n the items are:\n", c->count);
	for (int i = 0; i < c->count; i++) {
		printShoppingItem(c->ShoppingIteamArr[i]);
	}
}
void freeShoppingIteamsArr(ShoppingItem** c,int size) {
	for (int i = 0; i < size; i++) {
		freeShoppingItem(c[i]);
	}
}
void freeShoppingCart(ShoppingCart* c) {
	freeShoppingIteamsArr(c->ShoppingIteamArr, c->count);
	free(c->ShoppingIteamArr);
}
float sumPrice(const ShoppingCart* c) {
	float sum = 0;
	for (int i = 0; i < c->count; i++) {
		sum += (c->ShoppingIteamArr[i]->price * c->ShoppingIteamArr[i]->amount);
	}
	return sum;
}
int addShoppingItem(ShoppingCart* c,Product* p) {
	c->ShoppingIteamArr = (ShoppingItem**)realloc(c->ShoppingIteamArr, (c->count + 1) * sizeof(ShoppingItem*));
	if (!c->ShoppingIteamArr)
		return 0;
	c->ShoppingIteamArr[c->count] = (ShoppingItem*)calloc(1, sizeof(ShoppingItem));
	if (!c->ShoppingIteamArr)
		return 0;
	initShoppingItem(c->ShoppingIteamArr[c->count], p);
	c->count++;
	return 1;

}
