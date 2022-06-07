#ifndef __PRODUCT__
#define __PRODUCT__

#define NAME_LENGTH 20
#define BARCODE_LENGTH 8
typedef enum { eShelf, eFrozen, eFridge, eFruitVegtable, eNofTypes} eProductType;
const char* type[eNofTypes];

typedef struct
{
	char name[NAME_LENGTH];
	char barcode[BARCODE_LENGTH];
	eProductType type;
	float price;
	int amount;
}Product;
int initProduct(Product* p);
eProductType getProductType();
void printProduct(const Product* p);
int checkBarcodeLength(const char* barcode);
int checkDigitsInBarcode(const char* barcode);
int checkBarcodeUppercase(const char* barcode);
#endif