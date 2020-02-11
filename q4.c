#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// struct person with 3 fields 
struct Books { 
	char* name; 
	int id; 
	int price; 
	int i, j, a, n;
}; 

// setting up rules for comparison 
// to sort the students based on names 
int comparator(const void* p, const void* q) 
{ 
	return strcmp(((struct Books*)p)->name, 
			((struct Books*)q)->name); 
} 

// Driver program 
int main() 
{ 
	int i = 0, n = 10; 
	int j, a;

	struct Books arr[n]; 

	// Get the students data 
	arr[0].id = 0; 
	arr[0].name = "B"; 
	arr[0].price = 12; 

	arr[1].id = 1; 
	arr[1].name = "A"; 
	arr[1].price = 10; 

	arr[2].id = 2; 
	arr[2].name = "D"; 
	arr[2].price = 8; 

	arr[3].id = 3; 
	arr[3].name = "X"; 
	arr[3].price = 9; 

	arr[4].id = 4;
	arr[4].name = "E";
	arr[4].price = 9;


	arr[5].id = 5; 
	arr[5].name = "Y"; 
	arr[5].price = 10; 

	arr[6].id = 6;
	arr[6].name = "G";
	arr[6].price = 10;

	arr[7].id = 7;
	arr[7].name = "H";
	arr[7].price = 10;

	arr[8].id = 8;
	arr[8].name = "I";
	arr[8].price = 10;

	arr[9].id = 9;
	arr[9].name = "J";
	arr[9].price = 10;

//	arr[10].id = 10;
//	arr[10].name = "L";
//	arr[10].price = 10;

	// Print the Unsorted Structure 
	printf("Unsorted Books Records:\n"); 
	for (i = 0; i < n; i++) { 
		printf("Id = %d, Name = %s, Price = %d \n", 
				arr[i].id, arr[i].name, arr[i].price); 
	} 
	// Sort the structure 
	// based on the specified comparator 
	qsort(arr, n, sizeof(struct Books), comparator); 

	// Print the Sorted Structure 
	printf("\n\nBooks Records sorted by Name:\n"); 
	for (i = 0; i < n; i++) { 
		printf("Id = %d, Name = %s, Price = %d \n", 
				arr[i].id, arr[i].name, arr[i].price); 
	} 

	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (arr[i].price < arr[j].price)
			{
				struct Books a ;
				a = arr[i];
				arr[i]= arr[j];
				arr[j] = a;
			}
		}
	}

printf("The Books price arranged in descending order are given below\n");

	for (i = 0; i < n; i++) {
		printf("Id = %d, Name = %s, Price = %d \n",
				arr[i].id, arr[i].name, arr[i].price);
	}
		return 0; 
}
