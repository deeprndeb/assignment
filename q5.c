#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct employee{
	int id;
	char name[10];
	char address[10];
	int salary;
	int birth[3];
	int join[3];
	int age_y;
	int age_m;
	int exp;
	int prob[3];
}emp;

void calc_age(int arr[],int arr1[],emp *e);
void calc_exp(int arr[],int arr1[],emp *e);
void find_prob(int arr[],emp *e);
void display(emp e);


int main()
{
	int arr[3],arr1[3],i;
	char ch;
	emp e;
	time_t ts;
	struct tm *ct;
	ts = time(NULL);
	ct = localtime(&ts);

	printf("\n Enter Id: ");
	scanf("%d",&e.id);
	scanf("%c",&ch);
	printf("\n Enter name: ");
	scanf("%s",e.name);
	scanf("%c",&ch);
	printf("\n Enter address: ");
	scanf("%s",e.address);
	printf("\n Enter salary: ");
	scanf("%d",&e.salary);
	printf("\n Enter birth date: ");
	scanf("%d-%d-%d",&e.birth[0],&e.birth[1],&e.birth[2]);
	printf("\n Enter Join date: ");
	scanf("%d-%d-%d",&e.join[0],&e.join[1],&e.join[2]);
	printf("-------------------------------------------------------------------\n");
	for(i=0;i<3;i++)
	{
		arr[i] = e.birth[i];
	}
	for(i=0;i<3;i++)
	{
		arr1[i] = e.join[i];
	}
	calc_age(arr,arr1,&e);
	for(i=0;i<3;i++)
	{
		arr[i] = e.join[i];
	}

	arr1[0] = ct->tm_mday;
	arr1[1] = ct->tm_mon+1;
	arr1[2] = ct->tm_year+1900;
	calc_exp(arr,arr1,&e);
	find_prob(e.join,&e);
	display(e);

	return 0;
}

void calc_age(int arr[],int arr1[],emp *e)
{
	int month[] = { 31, 28, 31, 30, 31, 30, 31,  
		31, 30, 31, 30, 31 }; 

	if (arr[0] > arr1[0]) { 
		arr1[0] = arr1[0] + month[arr[0] - 1]; 
		arr1[1] = arr1[1] - 1; 
	} 

	if (arr[1] > arr1[1]) { 
		arr1[2] = arr1[2] - 1; 
		arr1[1] = arr1[1] + 12; 
	} 

	e->age_m = arr1[1] - arr[1]; 
	e->age_y = arr1[2] - arr[2];

}
void calc_exp(int arr[],int arr1[],emp *e)
{
	int month[] = {31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31};

	if (arr[0] > arr1[0]) { 
		arr1[0] = arr1[0] + month[arr[0] - 1];
		arr1[1] = arr1[1] - 1;
	}

	if (arr[1] > arr1[1]) { 
		arr1[2] = arr1[2] - 1; 
		arr1[1] = arr1[1] + 12;
	}

	e->exp = arr1[1] - arr[1] + (12 *(arr1[2] - arr[2]));

}

void find_prob(int arr[],emp *e)
{
	struct tm date={0};
	time_t timer;
	timer=time(NULL);
	date.tm_year = arr[2];
	date.tm_mon = arr[1];
	date.tm_mday = arr[0] + 90;
	timer = mktime( &date ) ;
	date = *gmtime( &timer ) ;
	e->prob[0]=date.tm_mday-1;
	e->prob[1]=date.tm_mon;
	e->prob[2]=date.tm_year;
	/*	if(e->exp >=3)
	{
		printf("\n Employee Probition Period is Over On : ");
		printf("%d/%d/%d\n",date.tm_mday-1,date.tm_mon,date.tm_year);
	}
	else{
		printf("\n Employee Probition Period will over on: ");
	printf("%d/%d/%d\n",date.tm_mday-1,date.tm_mon,date.tm_year);
	}*/
}
void display(emp e)
{
	printf("\n Id: %d",e.id);
	printf("\n Name: %s",e.name);
	printf("\n Address: %s",e.address);
	printf("\n Salary: %d",e.salary);
	printf("\n Birth Date: %d/%d/%d",e.birth[0],e.birth[1],e.birth[2]);
	printf("\n Join Date : %d/%d/%d",e.join[0],e.join[1],e.join[2]);
	printf("\n Age in Years : %d Years %d Months ",e.age_y,e.age_m);
	printf("\n Experience in month : %d ",e.exp);
	if(e.exp >=3)
     {
         printf("\n Employee Probition Period is Over On : %d/%d/%d\n",e.prob[0],e.prob[1],e.prob[2]);
	 printf("--------------------------------------------------------\n");
     }
     else{
         printf("\n Employee Probition Period will over on :%d/%d/%d\n",e.prob[0],e.prob[1],e.prob[2]);
	 printf("----------------------------------------------------------\n");
     }

}

