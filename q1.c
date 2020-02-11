//C provides two functions strtok() and strtok_r() for splitting a string by some delimiter. Splitting a string is a very common task. For example, we have a comma separated list of items from a file and we want individual items in an array.

#include <stdio.h> 
#include <string.h> 
  
int main() 
{ 
    char str[] = "Welcome,to,Sunbeam,CDAC,Diploma,Course"; 
  
    // Returns first token 
    char* token = strtok(str, ","); 
  
    // Keep printing tokens while one of the 
    // delimiters present in str[]. 
    while (token != NULL) { 
        printf("%s\n", token); 
        token = strtok(NULL, ","); 
    } 
  
    return 0; 
} 




/*
#include<stdio.h>
#include <string.h>

int main() {
	char string[50];
	char * token;
	scanf("%s",string);
	token = strtok(string, ",");
	while(token != NULL)
	{
		printf("%s ",token);
		token = strtok(NULL, ",");
	}
	return 0;
}*/
