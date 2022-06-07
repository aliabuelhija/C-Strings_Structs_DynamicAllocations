#ifndef __ADR__
#define __ADR__
#define DELI "!"
#define DELIMIT ' ' 
typedef struct
{
	int houseNumber;
	char* street;
	char* city;
}Address;

int initAddress(Address* h);
void printAddress(const Address* h);
void	freeAddress(Address* h);
int countWords(const char* str);
char* OneWord(char* str);
char* MoreThanOneWord(char* str);
int checkStreet(const char* str);
int checkTheInput(const char* str);
char*	deleteSpaces(const char* str);
char*	fixString(char* str);
#endif