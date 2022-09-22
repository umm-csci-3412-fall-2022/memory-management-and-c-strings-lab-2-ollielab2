#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

char *disemvowel(char *str) {
	int i = 0;
	int j = 0;
	char*result = (char*) calloc (strlen(str)+1, sizeof(char));
	for(i=0;str[i];i++){
		char temp[1]={str[i]};
		if(strpbrk(temp,"aeiouAEIOU")){
		}else{
			result[j++] = str[i];
		}
	}
	result[j] = '\0';
	return (char*) result;
}
