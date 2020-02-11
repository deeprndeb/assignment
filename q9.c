#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct item_det{
	int id;
	char name[20];
	int price;
	int qt;
}item;

void add_item();
void find_item();
void display_all();
void edit_item();
void delete_item();

int id=0;

int main()
{
	int j,ch=1;
	item i={0},*s;
	FILE *fp;
	fp = fopen("management.db","r");
	if(fp == NULL)
	{
		printf("\n Error Opening File.");
		return 0;
	}

	while(fread(&i,sizeof(i),1,fp));
	fclose(fp);

	id = i.id;
	while(ch !=0)
	{
		printf("\n0. Exit \n1. Add Item \n2. Find Item \n3. Display All \n4. Edit Item \n5. Delete Item");
		printf("\n Enter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: add_item();
				   break;
			case 2:  find_item();
					break;
			case 3: display_all();
					break;
			case 4: edit_item();
					break;
			case 5: delete_item();
					break;

		}

	}
	return 0;
}

void add_item()
{
	printf("\n Add Item..");
	item s,i;
	char ch;
	s.id = ++id;
	scanf("%c",&ch);
	printf("\n Enter Name: ");
	scanf("%[^\n]",s.name);
	printf("\n Enter Price: ");
    scanf("%d",&s.price);
    printf("\n Enter Quantity: ");
    scanf("%d",&s.qt);

	FILE *fp = fopen("management.db","a");
	//while(fread(&i,sizeof(i),1,fp));
	if(fwrite(&s,sizeof(item),1,fp))
	{
		printf("Item Added Successfully..");
	}
	else
	{
		printf("Failed To add Item");
	}
	fclose(fp);

}
void find_item()
{
	printf("\n Find Item By Name");
	item i;
	int flag=0;
	char ch,name[20];
	FILE *fp = fopen("management.db","r");

	scanf("%c",&ch);
	printf("\n Enter name to find Item:");
	scanf("%[^\n]",name);

	while(fread(&i,sizeof(i),1,fp))
	{
		if(!strcmp(name,i.name))
		{
			flag = 1;
			break;
		}
	}

	if(flag == 1)
	{
		printf("\n Item Found By Name..");
		printf("\nId :%d  Name: %s   Price: %d   Quantity: %d",i.id,i.name,i.price,i.qt);
	}
	else
	{
		printf("\n No Item Found By This Name: ");
	}

	fclose(fp);
}
void display_all()
{
	item i;
	FILE *fp = fopen("management.db","r");
	printf("\nDisplay All");
	while(fread(&i,sizeof(i),1,fp))
	{
		printf("\nId :%d  Name: %s   Price: %d   Quantity: %d",i.id,i.name,i.price,i.qt);
	}
      fclose(fp);
}
void edit_item()
{
    printf("\n Edit item");
      item i;
      int flag=0,j=1;
      char ch,name[20];
      FILE *fp = fopen("management.db","r+");
 
      scanf("%c",&ch);
      printf("\n Enter name to find Item:");
      scanf("%[^\n]",name);
 
      while(fread(&i,sizeof(i),1,fp))
     {
         if(!strcmp(name,i.name))
         {
             flag = 1;
             break;
         }
     }

     if(flag == 1)
     {
		 while(j !=0)
		 {
			 printf("\n Enter Choice To Edit Item");
			 printf("\n 0. Exit \n 1. Name \n 2. Price \n 3. Quantity");
			 scanf("%d",&j);
			 switch(j)
			 {
				 case 1: scanf("%c",&ch);
                         printf("\n Enter name :");
                         scanf("%[^\n]",i.name);
						 break;

				 case 2: printf("Enter Price:");
						 scanf("%d",&i.price);
						 break;

				 case 3: printf("Enter Price:");
                         scanf("%d",&i.price);
                         break;
			 }
		 
		 }

		 printf("\nId :%d  Name: %s   Price: %d   Quantity: %d",i.id,i.name,i.price,i.qt);

		 fseek(fp,-sizeof(i),SEEK_CUR);
		 fwrite(&i,sizeof(item),1,fp);
     }
     else
     {
         printf("\n No Item Found By This Name: ");
     }

     fclose(fp);

}
void delete_item()
{
	printf("\nDelete item");

	item i;
       int flag=0,j=1;
       char ch,name[20];
       FILE *fp = fopen("management.db","r+");
	   FILE *t = fopen("temp.db","a");

       scanf("%c",&ch);
       printf("\n Enter name to find Item:");
       scanf("%[^\n]",name);

       while(fread(&i,sizeof(i),1,fp))
      {
          if(strcmp(name,i.name))
          {
              fwrite(&i,sizeof(item),1,t);
          }
      }

	   fclose(fp);
	   fclose(t);
	   remove("management.db");
	   rename("temp.db","management.db");
}
