#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ShoppingItem.h"
#include "Product.h"
#include "Genreal.h"
void initShoppingItem(ShoppingItem* s,Product* p) {
s->name=getDynStr(p->name);
	s->price = p->price;
	
}
void printShoppingItem(const ShoppingItem* s) {
	printf("Product name: %s amount : %d price : %f \n", s->name,s->amount,s->price);
}
void freeShoppingItem(ShoppingItem* s) {
	free(s->name);
}
