#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LEN 1024
#define NUMSTR 64

int probel(char c)
{
	if (c==' ' || c=='\t') 
		return 0;
	else
		return 1;
}

void isfull(int j)
{
	if(j>LEN)
	{
		printf("ERROR\n");
		exit(1);
	}
}

void output_res(char *res[])
{
	int i=0;
	putchar('\n');
	while(res[i]!=NULL)
	{
		printf("%s", res[i]);
		i++;
		putchar('\n');
	}
}

int main()
{
	char *m, c, buffer[LEN], *res[NUMSTR];
	int i, j=0, k=0;
	while((c=getchar())!=EOF)
		if (probel(c)!=0)
			if(c!='\n')
			{
				buffer[j]=c;
				j++;
				isfull(j);
			}
			else
			{
				buffer[j]='\0';
 				if((m=(char*)malloc((j+1)*sizeof(char)))==NULL)
 				{
 					printf("ERROR\n");
 					exit(1);
 				}
 				for(i=0;i<=j;i++)
			 	   m[i]=buffer[i];
  			    res[k]=m;
  			    k++; 
				j=0;
			}
	res[k+1]=NULL;
	output_res(res);
}
