#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define NUM 2048

struct fill { char *p_str;
		     struct fil *p_next;
		   } *start=NULL;
		   
void error(c)
{
	switch(c)
	{
		case 1: printf("Not enough space in buffer\n"); break; 
		case 2: printf ("Memory allocation error\n"); break;
	}
	exit(1);
}

void entry(struct fill *start, FILE *res)
{
	while (start!=NULL)
	{	
		fputs(start->p_str,output);
		fputc('\n', res);
		free(start);
		start=start->p_next;	
	}
}

int main(int argc, char *argv[])
{
	FILE *res;
	struct fill *pod_struct;
	char *pod_slovo, *p;
	char c, buf[NUM];
	int i=0, sup=0;
	if ((res = fopen(argv[1], "w")) == NULL) 
			perror(argv[1]);
	while((c=getchar())!=EOF)
	{
		if (isalpha(c))
		{
			if (i>NUM) error(1);
			buf[i]=c;
			i++;
			sup=1;
		}
		if (c==' ' || c=='\t' || c=='\n')
		{	
			if (sup==0) continue;
			sup=0;
			buf[i]='\0';
			if ((pod_slovo=(char *)malloc(i*sizeof(char))) == NULL) error(2);
			strcpy(pod_slovo, buf);
			if ((pod_struct=(struct fill*)malloc(sizeof(struct fill)))==NULL) error(2);
			pod_struct->p_next = start;
			start = pod_struct;
			pod_struct->p_str = pod_slovo;
			i=0;
		}	
	}	
	entry(start, res);	
	fclose(res);
}
