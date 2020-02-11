#include<stdio.h>

void add_num();
void delete_num();
void find_max();
void find_min();
void display_all();
int sum();

int arr[10]={0};
int main()
{
	int i,ch = 1,res;
	while(ch != 0)
	{
		printf("\n--------------------------MENU-----------------------\n");
		printf("\n\nPRESS 0.Exit\nPRESS 1.Add\nPRESS 2.Delete\nPRESS 3.Find Maximun\nPRESS 4.Find Minimum\nPRESS 5.Sum\nPRESS 6.Display\n ");
		printf("\n------------------------------------------------\n");
		printf("Choice is: ");
		scanf("%d",&ch);
		printf("---------------------------------------------\n");
		switch(ch)
		{
			case 1: add_num();
					break;
			case 2: delete_num();
					break;
			case 3: find_max();
					break;
			case 4: find_min();
					break;
			case 5: res = sum();
					printf("\n Sum of Array Elements: %d",res);
					break;
			case 6: display_all();
					break;
		}
	}

	return 0;
}

void add_num()
{
	int i,j,k;
	printf("\n Available Indices are: ");
	for(i=0;i<10;i++)
	{
		if(arr[i] == 0)
		{
			printf("%d ",i);
		}
	}

	printf("\nEnter Your Choice To enter Number: ");
	scanf("%d",&k);
	printf("\nEnter number: ");
	scanf("%d",&arr[k]);
}
void delete_num()
{
	 int i,j,k;
      printf("\n Available Indices are: ");
      for(i=0;i<10;i++)
      {
          if(arr[i] != 0)
          {
              printf("\n Index : %d  Number: %d ",i,arr[i]);
         }
      }
 
      printf("\nEnter Your Choice To delete Index: ");
      scanf("%d",&k);
      arr[k] = 0;

}
void find_max()
{
	int i,j,max=0;
	max=arr[0];
	j=0;
	for(i=0;i<10;i++)
	{
		if(max<arr[i])
		{
			max = arr[i];
			j=i;
		}
	}

	printf("\n Maximum Number is :%d \t index: %d",max,j);
}
void find_min()
{
	 int i,j,min=arr[0];
      j=0;
      for(i=0;i<10;i++)
      {
          if(min>arr[i])
          {
              min = arr[i];
              j=i;
          }
      }
  
      printf("\n Minimum Number is :%d \t index: %d",min,j);
}
int sum()
{
	int i,sum = 0;
	for(i=0;i<10;i++)
	{
		sum += arr[i];
	}
	return sum;
}

void display_all()
{
	int i;
	for(i = 0;i<10;i++)
	{
		printf("\n Index : %d  Number: %d ",i,arr[i]);
	}
}
