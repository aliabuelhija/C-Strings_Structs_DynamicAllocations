#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Address.h"
#include "Genreal.h"

int initAddress(Address* h) {
	char temp[MAX_STR_LEN];
	char* address;
	char* word;
	address = getStrExactName("enter address data\n Format: street!housenumber!city\n street city can have a space\n");
	if (checkTheInput(address) == 0)
		return 0;
	address= fixString(address);
	strcpy(temp, address);
	word = strtok(temp, DELI);
	if (countWords(word) == 1) {
	word=	OneWord(word);
		h->street = _strdup(word);
	}
	else {
		word = MoreThanOneWord(word);
		h->street = _strdup(word);
	}
		word = strtok(NULL, DELI);
		if (checkStreet(word) == 1)
			h->houseNumber = atoi(word);
			else {
				return 0;
			}
			word = strtok(NULL, DELI);
			word = fixString(word);
			if (countWords(word) == 1) {
				OneWord(word);
				h->city = _strdup(word);
			}
			else {
				word = MoreThanOneWord(word);
				h->city =_strdup( word);
		}
	return 1;
}
void printAddress(const Address* h) {
	printf("the city: %s the house number: %d the street: %s\n",h->city, h->houseNumber , h->street);
	
}
void	freeAddress(Address* h)
{
	free(h->city);
	free(h->street);
}
int countWords(const char* str) {
	int numOfWords = 0;
	while (*str)
	{
		while (*str && isspace(*str))
			str++;
		if (*str)
			numOfWords++;
		while (*str && !isspace(*str))
			str++;
	}
	return numOfWords;
}
char* OneWord(char* str) {
	int lastIndex = strlen(str) - 1;
	if (str[0] == ' ' && str[lastIndex]==' ')
		return 0;
      str[0]=toupper(str[0]);
	str[lastIndex]=toupper(str[lastIndex]);
	return str;
}
char* MoreThanOneWord(char* str) {
	int len = strlen(str);
	str[0]=toupper(str[0]);
	
	for (int  i = 1; i < len; i++) {
		if (str[i] == ' ') {
			str[i] = '#';
			str[i + 1] = toupper(str[i + 1]);
		}
	}
	return str;
}
int checkStreet(const char* str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (!(isdigit(str[i])))
			return 0;
	}
	return 1;
}
int checkTheInput(const char* str){
	int len = strlen(str);
	int count = 0;
	for (int i = 1; i < len; i++) {
		if (str[i] == '!') {
			count++;
		}
	}
	if (count == 2)
		return 1;
	return 0;
}
char*	fixString(char* str)
{
	while (isspace(*str)) {

		str++;
	}
	str = deleteSpaces(str);
		return str;
}
char*	deleteSpaces(const char* str) {
	int i, j;
	char * newString;

	newString = (char *)malloc(MAX_STR_LEN);

	i = 0;
	j = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			newString[j] = ' ';
			j++;

			while (str[i] == ' ')
				i++;
		}
		newString[j] = str[i];
		i++;
		j++;
	}
	newString[j] = '\0';
	return newString;
}