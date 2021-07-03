#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 128


struct list{ 	
	char *word;
	int count;
	struct list *next;		
	} *first = NULL,*end=NULL;


int check(char *string)
{
	struct list *p;
	for(p= first ;p != NULL; p = p->next)
	{
		if(!strcmp(p->word, string))
		{
			p->count++;
			return 1;
		}
	}
}


void output (struct list *p, FILE *result){

	struct list *cur = first;

	while(cur != NULL){

		fprintf(result, "%s : %d\n", cur->word, cur->count);
		cur = cur->next;

	}
}

void obr(char *str) 
{
struct list *p;
for (p = first; p != NULL;p = p->next);
	if (end == NULL)
		end= (struct list *) malloc(sizeof(struct list));
	p = (struct list *) malloc(sizeof(struct list));
	if (check(str)!=1)
	{
	p->word= (char*) malloc(sizeof(char)*(strlen(str)+1));
	strcpy(p->word,str);
	p->count=1;
	p->next = NULL;
	end->next = p;
	end= p;
	if (first == NULL)
		first = p;
	}
}

int main(int argc, char *argv[]){
	FILE  *result;
	struct list *current;
	char buf[SIZE];
	char *string;
	if (!(result = fopen(argv[1], "w"))){
		printf("ERROR\n");
		exit (0);
	}
	while (scanf("%s", buf) != EOF){
		if (!(string = (char*) malloc (strlen (buf) * sizeof(char))))
			exit (1); 
		strcpy (string, buf);
		obr(string);
	}

        output(current, result);
	fclose(result);
	return 0;
}

