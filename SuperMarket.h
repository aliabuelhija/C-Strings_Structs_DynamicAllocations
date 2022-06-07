#ifndef __MARKET__
#define __MARKET__
#include "Address.h"
#include "Customer.h"
#include "Product.h"
#include "ShoppingCart.h"
typedef struct
{
	char* name;
	Address address;
	Customer* customersArr;
	int customersNum;
	Product** ProductsArr;
	int productNum;
}SuperMarket;
void initSuperMarket(SuperMarket* s);
void printSuperMarket(const SuperMarket* s);
void freeSuperMarket(SuperMarket* s);
void freeCustomerArr(Customer* arr,int size);
void freeProductArr(Product** arr, int size);
int addProductToMarket(SuperMarket* s);
int addCustomerToSuperMarket(SuperMarket* s);
void printProductByType(const SuperMarket* s);
void buyProduct(SuperMarket* s);
Product* findProduct(const char* barcode, const SuperMarket* s);
int checkCustomerName( char* name,const SuperMarket* s);
int checkIfItemAlreadyAdded(const char* name,const ShoppingCart* c) ;
void printCustomersArr(const Customer* customersArr, const int size);
void printProductArr(const Product** productArr, const int size);
void fixAmount(Product* p, ShoppingItem* c);

#endif