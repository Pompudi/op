#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define NUM 512

struct word { char *p_word;
		     struct word *p_next;
		   } *first=NULL;
		   
void entry(struct word *first)
{
	while (first!=NULL)
	{	
	printf("%s", first->p_word);
	putchar('\n');
	free(first);
	first=first->p_next;
	}
}

int main()
{	char buffer[NUM],*res[NUM], *pword, c;
	struct word *p2;
	char *slovo, *p;
	int i=0, flag=0;
	while((c=getchar())!=EOF)
	{
		if (isalpha(c))
		{
			if (i>NUM)
				printf("ERROR\n");break;
			buffer[i]=c;
			i++;
			flag=1;
		}
		else if (isspace(c))
		{	
			if (flag==0)
				 continue;
			flag=0;
			buffer[i]='\0';
			if ((slovo=(char *)malloc(i*sizeof(char))) == NULL) 
					printf("ERROR\n");
			strcpy(slovo, buffer);
			if ((p2=(struct word*)malloc(sizeof(struct word)))==NULL)
					printf("ERROR\n");
			p2->p_next = first;
			first = p2;
			p2->p_word = slovo;
			i=0;
		}	
	}
	entry(first);	
}
