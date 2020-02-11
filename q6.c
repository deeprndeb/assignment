#include<stdio.h>

# define MAX 6

typedef struct subject{
	char s[10];
	int mark;
}sub;

typedef struct student{
	int roll;
	char name[20];
	int std;
	sub sb[6];
}st;


st arr[MAX];
int front = -1;
int rear = -1;

void add_st();
void delete_st();
void display_all();

int main()
{
	int ch=1;
	while(ch !=0)
	{
		printf("\n-----------------------------MENU------------------------------\n");
		printf("\n PRESS 0.Exit \n PRESS 1.Add Student \n PRESS 2.Delete Student \n PRESS 3.Display All");
		printf("\n------------------------------------------------------------------\n");
		printf(" Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
				add_st();
				break;
			case 2 :
				delete_st();
				break;
			case 3:
				display_all();
				break;
		}
	}

	return 0;
}


void add_st()
{
	char ch;
	int j;
	st i;
	if((front == 0 && rear == MAX-1) || (front == rear+1))
	{
		printf("Queue Overflow n");
	}
	else{
	if(front == -1)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		if(rear == MAX-1)
			rear = 0;
		else
			rear = rear+1;
	}
	printf("\n Enter Roll No: ");
	scanf("%d",&i.roll);
	scanf("%c",&ch);
	printf("\n Enter Student Name: ");
	scanf("%s",i.name);
	printf("\n Enter standard: ");
    	scanf("%d",&i.std);
	for(j=0;j<6;j++)
	{
	scanf("%c",&ch);
      	printf("\n Enter Subject Name: ");
      	scanf("%s",i.sb[j].s);
      	printf("\n Enter Marks: ");
      	scanf("%d",&i.sb[j].mark);

	 }
	
	    arr[rear] = i;
	}
}

void delete_st()
{
	int i;
	if(front == -1)
	{
		printf("Queue Underflown");
		return ;
	}
	printf("\nElement deleted from queue is: ");
	 printf("\nRoll No: %d  Name: %s  Std: %d Marks: \n ",arr[front].roll,arr[front].name,arr[front].std);
              for(i=0;i<6;i++)
              {   
                 printf("\n Subject: %s   Marks: %d",arr[front].sb[i].s,arr[front].sb[i].mark);
             }
	if(front == rear)
	{
		front = -1;
		rear=-1;
	}
	else
	{
		if(front == MAX-1)
			front = 0;
		else
			front = front+1;
	}
}
void display_all()
{
	int i,front1 = front,rear1 = rear;
	if(front == -1)
	{
		printf("Queue is emptyn");
		return;
	}
	printf("Queue elements :n");
	if( front1 <= rear1 )
	{	printf("\n Students Info: ");
		while(front1 <= rear1)
		{
			printf("\nRoll No: %d  Name: %s  Std: %d Marks: \n ",arr[front1].roll,arr[front1].name,arr[front1].std);
			for(i=0;i<6;i++)
			{
				printf("\n Subject: %s   Marks : %d",arr[front1].sb[i].s,arr[front1].sb[i].mark);
			}
			front1++;
		}
	}
	else
	{
		printf("\n Students Info: ");
		while(front1 <= MAX-1)
		{
			 printf("\nRoll No: %d  Name: %s  Std: %d Marks: \n ",arr[front1].roll,arr[front1].name,arr[front1].std);
              for(i=0;i<6;i++)
              {
                  printf("\n Subject: %s   Marks : %d",arr[front1].sb[i].s,arr[front1].sb[i].mark);
             }
				front1++;
		}
		front1 = 0;
		while(front1 <= rear1)
		{
			printf("\nRoll No: %d  Name: %s  Std: %d Marks: \n ",arr[front1].roll,arr[front1].name,arr[front1].std);
                for(i=0;i<6;i++)
                {   
                    printf("\n Subject: %s   Marks : %d",arr[front1].sb[i].s,arr[front1].sb[i].mark);
               }  
			front1++;
		}
	}
	printf("n");
}

