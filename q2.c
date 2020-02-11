#include<stdio.h>
#include<stdlib.h>

void copy_str();
void concat_str();
int comp_str();
void rev_str();

int main()
{
	int ch = 1,res;
	while(ch !=0)
	{
	//	printf("\n Enter Choice \n");
		printf("------------------MENU------------------\n");
	        printf(" PRESS 0. Exit \n PRESS 1. String Copy\n PRESS 2. String Concat \n PRESS 3. String Compare \n PRESS 4. String Reverse \n");
		printf("--------------------------------------------\n");
		printf("\n Choice is: ");
	//	printf("\n----------------------------------------\n");
		scanf("%d",&ch);
		printf("\n ----------------------------------------\n");
		switch(ch)
		{
			case 1:copy_str();
				        break;
			case 2: concat_str();
					break;
			case 3: res = comp_str();
					break;
			case 4: rev_str();
					break;
		}
	}

	return 0;
}


void copy_str()
{
	char str1[50],str2[50],s;
	int i;
	scanf("%c",&s);
	printf("\n Enter First String :");
	scanf("%[^\n]",str1);
	scanf("%c",&s);
	printf("\n Enter Second String :");
	scanf("%[^\n]",str2);
	for(i=0;i<50;i++)
	{
		str1[i] = str2[i];
	}

	printf("\n String After Copy : %s\n",str1);
}

void concat_str()
{
	char str1[50],str2[50],s;
	int i=0,j=0;
	scanf("%c",&s);
	printf("\n Enter First String :");
	scanf("%[^\n]",str1);
	scanf("%c",&s);
	printf("\n Enter Second String :");
	scanf("%[^\n]",str2);
	while(str1[i] != '\0')
	{
		i++;
	}

	while(str2[j] != '\0')
	{
		str1[i]=str2[j];
		i++;
		j++;
	}
	str1[i] = '\0';
	printf("\n String After Concat : %s",str1);

}
int comp_str()
{
	char str1[50],str2[50],s;
	int i=0;
	scanf("%c",&s);
	printf("\n Enter First String :");
	scanf("%[^\n]",str1);
	scanf("%c",&s);
	printf("\n Enter Second String :");
	scanf("%[^\n]",str2);

	while(str1[i]==str2[i])
	{
		if(str1[i]=='\0' || str2[i]=='\0')
			break;
		i++;
	}

	if(str1[i] == '\0' && str2[i] == '\0')
	{
		printf("\n Strings are Equal");
		return 1;
	}
	else
	{
		printf("\n Stringa are not Equal.");
		return 0;
	}
}
void rev_str()
{
	char str1[50],str2[50],s;
	int i=0,j=0,k;
	scanf("%c",&s);
	printf("\n Enter First String :");
	scanf("%[^\n]",str1);

	while(str1[i]!='\0')
	{
		i++;
	}
	i--;
	k=i;
	while(j<=k)
	{
		str2[j] = str1[i];
		j++;
		i--;
	}
	str2[j] = '\0';
	printf("\n String After Reverse : %s",str2);
}
