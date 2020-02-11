#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0

typedef int bool;
typedef enum MENU{EXIT,ADD_FIRST,ADD_LAST,TRAVERSE_FORWARD,TRAVERSE_BACKWARD,FIND_BY_ID,FIND_BY_NAME,DELETE_ACCOUNT}Menu;
Menu menu_list();

typedef struct AccountHolderDetails
{
	char name[30];
	char address[40];
	char contact_details[30];

}AccountHolder;
typedef struct AccountDetails
{
	char acc_id[5];
	char acc_type[8];
	float acc_balance;
	AccountHolder acc_holder;

}Account;

typedef struct NODE
{
	Account data;
	struct NODE *next;
	struct NODE *prev;
}Node;

typedef struct AccountList
{
	Node *head;
	Node *tail;
}List;

void accept_account_details(Account *account);
void add_element_at_first(List *list,Account account);
void add_element_at_last(List *list,Account account);
void forward_traverse(List *list);
void backward_traverse(List *list);
Account* find_accholder_by_id(List *list,char acc_id[]);
Account* find_accholder_by_name(List *list,char acc_name[]);
void init_list(List *list);
Node* create_node();
bool is_empty(List *list);
void delete_first(List *list);
int main(void)
{
	List SavingAccList,CurrentAccList;
	init_list(&SavingAccList);
	//init_list(&CurrentAccList);
	Menu choice;
	Account account,*acc;
	int ch;
	char id[5],name[10];
	while((choice=menu_list())!=EXIT)
	{
		switch(choice)
		{
			case ADD_FIRST:
				accept_account_details(&account);
				if(strcmp(account.acc_type,"saving")==0)
					add_element_at_first(&SavingAccList,account);
			/*	else if(strcmp(account.acc_type,"current")==0)
					add_element_at_first(&CurrentAccList,account);*/
				break;

			case ADD_LAST:
				accept_account_details(&account);
				add_element_at_first(&SavingAccList,account);
				break;

			case TRAVERSE_FORWARD:

				printf("\nEnter which list u want to traverse	:	");
				printf("\n 0. EXIT");
				printf("\n 1. SAVING ACCOUNTS LIST");
			//	printf("\n 2. CURRENT ACCOUNTS LIST");
				printf("\nEnter your choice	:	");
				scanf("%d",&ch);
				switch(ch)
				{
					case 0:
						break;
					case 1:
						forward_traverse(&SavingAccList);
						break;
			/*		case 2:
						forward_traverse(&CurrentAccList);
						break;*/
					default:
						printf("\n Invalid choice");
						break;
				}

				break;

			case TRAVERSE_BACKWARD:
				printf("\nEnter which list u want to traverse	:	");
				printf("\n 0. EXIT");
				printf("\n 1. SAVING ACCOUNTS LIST");
			//	printf("\n 2. CURRENT ACCOUNTS LIST");
				printf("\nEnter your choice	:	");
				scanf("%d",&ch);
				switch(ch)
				{
					case 0:
						break;
					case 1:
						backward_traverse(&SavingAccList);
						break;
					/*case 2:
						backward_traverse(&CurrentAccList);
						break;*/
					default:
						printf("\n Invalid choice");
						break;
				}
				break;

			case FIND_BY_ID:
				printf("\n Enter the account id	whose details you want to find	:	");
				scanf("%s",id);
				acc=find_accholder_by_id(&SavingAccList,id);
				printf("\n %5s %50s %10.2f %10s %10s %10s",acc->acc_id,acc->acc_type,
						acc->acc_balance,acc->acc_holder.name,acc->acc_holder.address,acc->acc_holder.contact_details);
				break;

			case FIND_BY_NAME:
				printf("\n Enter the account name whose details you want to find	:	");
				scanf("%s",name);
				acc=find_accholder_by_name(&SavingAccList,name);
				printf("\n %5s %50s %10.2f %10s %10s %10s",acc->acc_id,acc->acc_type,
						acc->acc_balance,acc->acc_holder.name,acc->acc_holder.address,acc->acc_holder.contact_details);
				break;
			case DELETE_ACCOUNT:
				break;

			default:delete_first(&SavingAccList);
				printf("\n Invalid choice");
				break;
		}
	}
	return EXIT_SUCCESS;
}

Menu menu_list()
{
	Menu choice;
	printf("\n--------------------MENU------------------------------");
	printf("\nPRESS 0. EXIT");
	printf("\nPRESS 1. ADD ACCOUNT AT FIRST");
	printf("\nPRESS 2. ADD ACCOUNT AT LAST");
	printf("\nPRESS 3. TRAVERSE LIST IN FORWARD MANNER");
	printf("\nPRESS 4. TRAVERSE LIST IN BACKWARD MANNER");
	printf("\nPRESS 5. FIND ACCOUNT BY ACCOUNT HOLDER ID");
	printf("\nPRESS 6. FIND ACCOUNT BY ACCOUNT HOLDER NAME");
	printf("\nPRESS 7. DELETE ACCOUNT");
	printf("\n--------------------------------------------------------\n");
	printf("\nEnter your choice : ");
	scanf("%d",&choice);
	return choice;
}

void init_list(List *list)
{
	list->head=NULL;
	list->tail=NULL;

}

bool is_empty(List *list)
{
	if(list->head==NULL)
		return TRUE;
	return FALSE;
}
void accept_account_details(Account *account)
{
	printf("\nEnter the account id:	");
	scanf("%s",account->acc_id);
	printf("\nEnter the account type: ");
	scanf("%s",account->acc_type);
	printf("\nEnter the account balance: ");
	scanf("%f",&account->acc_balance);
	printf("\nEnter the account holder name: ");
	scanf("%s",account->acc_holder.name);
	printf("\nEnter the account holder address: ");
	scanf("%s",account->acc_holder.address);
	printf("\nEnter the account holder contact: ");
	scanf("%s",account->acc_holder.contact_details);

}
Node* create_node()
{
	Node *temp=(Node*)malloc(sizeof(Node));
	if(temp!=NULL)
	{
		temp->next=NULL;
		temp->prev=NULL;
		return temp;

	}
	printf("\n malloc() failed to allocate ");
	return '\0';
}

void add_element_at_first(List *list,Account account)
{
	Node *newNode=create_node();
	newNode->data=account;
	if(is_empty(list))
	{
		list->tail=newNode;
	}
	else
	{
		newNode->next=list->head;
		list->head->prev=newNode;
	}
	list->head=newNode;
	list->head->prev=list->tail;
	list->tail->next=list->head;

}

void add_element_at_last(List *list,Account account)
{

	Node *newNode=create_node();
	newNode->data=account;
	if(is_empty(list))
	{
		list->head=newNode;
	}
	else
	{
		list->tail->next=newNode;
		newNode->prev=list->tail;
	}
	list->tail=newNode;
	list->head->prev=list->tail;
	list->tail->next=list->head;
}

void forward_traverse(List *list)
{
	if(is_empty(list))
		printf("\n List is empty");
	else
	{
		printf("\n------------------------------------------------------------------------------------------------------------------------------------");
		printf("\nACCOUNT_ID\t\tACCOUNT TYPE\t\tBALANCE\t\tACC HOLDER NAME\t\tACC HOLDER ADDRESS\t\tACC HOLDER CONTACT");
		printf("\n--------------------------------------------------------------------------------------------------------------------------------------");
		Node *trav=list->head;
		do
		{
			printf("\n %5s %50s %10.2f %10s %10s %10s",trav->data.acc_id,trav->data.acc_type,
					trav->data.acc_balance,trav->data.acc_holder.name,trav->data.acc_holder.address,trav->data.acc_holder.contact_details);
			trav=trav->next;
		}while(trav!=list->head);

	}
}

void backward_traverse(List *list)
{
	if(is_empty(list))
		printf("\n List is empty");
	else
	{
		printf("\n------------------------------------------------------------------------------------------------------------------------------------");

		printf("\nACCOUNT_ID\t\tACCOUNT TYPE\t\tBALANCE\t\tACC HOLDER NAME\t\tACC HOLDER ADDRESS\t\tACC HOLDER CONTACT");
		printf("\n--------------------------------------------------------------------------------------------------------------------------------------");
		Node *trav=list->tail;
		do
		{
			printf("\n %5s %50s %10.2f %10s %10s %10s",trav->data.acc_id,trav->data.acc_type,
					trav->data.acc_balance,trav->data.acc_holder.name,trav->data.acc_holder.address,trav->data.acc_holder.contact_details);
			trav=trav->prev;
		}while(trav!=list->tail);

	}
}

Account* find_accholder_by_id(List *list,char acc_id[])
{
	Node * trav=list->head;
	do
	{
		if(strcmp(trav->data.acc_id,acc_id)==0)
			return &trav->data;
		trav=trav->next;

	}while(trav!=list->head);

	return NULL;
}

Account* find_accholder_by_name(List *list,char acc_name[])
{
	Node * trav=list->head;
	do
	{
		if(strcmp(trav->data.acc_holder.name,acc_name)==0)
			return &trav->data;
		trav=trav->next;

	}while(trav!=list->head);

	return NULL;
}



void delete_first(List *list)
{
	if(is_empty(list))
		printf("\n list is empty");
	else
	{
		Node *temp=list->head;
		list->head->next->prev=list->tail;
		list->tail->next=list->head->next;
		list->head=list->head->next;
		free(temp);
		temp=NULL;
	}
}
/*
void add_element_at_first(List *list,Account account)
{
        Node *newNode=create_node();
        newNode->data=account;
        if(is_empty(list))
        {
                list->tail=newNode;
        }
        else
        {
                newNode->next=list->head;
                list->head->prev=newNode;
        }
        list->head=newNode;
        list->head->prev=list->tail;
        list->tail->next=list->head;

}

void add_element_at_last(List *list,Account account)
{

        Node *newNode=create_node();
        newNode->data=account;
        if(is_empty(list))
        {
                list->head=newNode;
        }
        else
        {
                list->tail->next=newNode;
	 newNode->prev=list->tail;
        }
        list->tail=newNode;
        list->head->prev=list->tail;
        list->tail->next=list->head;
}
*/
