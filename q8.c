#include<stdio.h>  
#include<string.h>
#include<stdlib.h>


typedef struct moviedata{
	int id;
	char name[50];
	char genre[100];
	struct moviedata *next;
}mdata;

mdata *head=NULL,*temp=NULL;
mdata *data;

void add_node(mdata *m);
void display_list(mdata *m);
void srch_name(mdata *m);
void srch_genre(mdata *m);

int  main()  
{  
	FILE *fp;  
	char ch,*token;
	int i=0,j=1;
	char string[100]="",*str[4];
	fp = fopen("movies.csv","r");  
	//ch = fgetc (fp);  
	while( (ch =fgetc(fp)) != EOF )  
	{
		//printf("%c",ch);
		string[i]=ch;
		i++;
		if(ch=='\n')
		{
			string[i-1] = '\0';
			i=0;
			// printf("\nString : %s",string);

			data = (mdata *)malloc(sizeof(mdata));
			token = strtok(string,",");
			//printf("token 1:%s",token);
			data->id = atoi(token);
			token = strtok(NULL,",");
			// printf("token 2:%s",token);
			strcpy(data->name,token);
			token = strtok(NULL,",");
			//printf("token 2:%s",token);
			strcpy(data->genre,token);
			data->next = NULL;
			//printf("\n STRUCT : %d  %s  %s",data->id,data->name,data->genre);
			add_node(data);
		}
	}
	fclose(fp);

	while(j != 0)
	{
		printf("\n----------------------MENU-------------------------\n");
		printf("\n PRESS 0. Exit\n PRESS 1. Display\n PRESS 2. Find By Name \n PRESS 3. Find By Genre  ");
		printf("\n----------------------------------------------------------\n");
		printf("Choice is: ");
		scanf("%d",&j);
		switch(j)
		{
			case 1: display_list(head);
					break;
			case 2: srch_name(head);
					break;
			case 3: srch_genre(head);
					break;
		}
	}
	return 0;
}  

void add_node(mdata *m)
{
	if(head == NULL)
	{
		head = m;
	}
	else
	{
		temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		} 
		temp->next = m;
	}

}

void display_list(mdata *m)
{
	printf("\n   LIST \n");
	temp = m;
	while(temp->next !=NULL)
	{
		printf("\n %d  %s  %s",temp->id,temp->name,temp->genre);
		temp=temp->next;
	}
	printf("\n %d  %s  %s",temp->id,temp->name,temp->genre);
}


void srch_name(mdata *m)
{
	char name[50],ch,*token,test[50];
	int i = 0;
	printf("\nEnter Movie name to search:");
	scanf("%c",&ch);
	scanf("%s",name);
	//scanf("%[^\n]",name);

	temp = m;
	while(temp != NULL)
	{
		strcpy(test,temp->name);
		token = strtok(test,"(");
		if(!strcmp(name,token))
		{
			printf("\n Movie Found..");
			printf("\n %d  %s  %s",temp->id,temp->name,temp->genre);
			i=1;
			break;
		}
		temp = temp->next;
	}

	if(i==0)
	{
		printf("\n Movie NOT Found...");
	}
}

void srch_genre(mdata *m)
{
	char ch,name[20],*token,test[50];
	printf("\n Enter Movie genre to search:");
	scanf("%c",&ch);
	scanf("%s",name);

	temp = m;
	while(temp != NULL)
	{
		strcpy(test, temp->genre);
		token=strtok(test,"|");
		while(token != NULL){
			if(!strcmp(name,token))
			{
				printf("\n %d  %s  %s",temp->id,temp->name,temp->genre);
				break;
			}
			token=strtok(NULL,"|");
		}
		temp = temp->next;
	}
}
