#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define STROKI 6
#define STOLBIKI 5

//создание массива с рандомными числами от -5 до 5
int create_mas(int mas[][STOLBIKI])
{
	int random_number[]={-5,-4,-3,-2,-1,0,1,2,3,4,5};
	int i, j;
	srand(time(NULL));
	for (i=0; i<STROKI; i++)
	{
		for (j=0;j<STOLBIKI;j++)
		{
			
			mas[i][j]=random_number[rand()%11];
		}
	}
}

//вывод созданного массива
int print_mas(int mas[STROKI][STOLBIKI])
{
	int i,j;
	printf("Изначальный массив:\n");
	for (i=0;i<STROKI;i++)
	{
		for (j=0;j<STOLBIKI;j++)
		{
		 	printf("%2d  ",mas[i][j]);
		}
		printf("\n");
	}
}
//вывод массива со ср. ар. значениям 
double print_mas_ar(double mas_ar[STROKI])
{
	int i;
	printf("\nСреднее арифметическое каждой строки: ");
	for (i=0;i<STROKI;i++)
		{
		 	printf("%2.1lf  ",mas_ar[i]);
		}
		printf("\n\n");
}	

//массив со средним арифметическим значением каждой строки
double arithmetic_mean(int mas[][STOLBIKI],double mas_ar[STROKI])
{
	int i,j;
	double sum;
	for (i=0;i<STROKI;i++)
	{	
		sum=0;
		for (j=0;j<STOLBIKI;j++)
		{
			sum+=mas[i][j];	
		}
		mas_ar[i]=sum/STOLBIKI;
	}	
    print_mas_ar(mas_ar);
}	
double print_mas2(double mas2[STROKI][STOLBIKI])
{
	int i,j;
	printf("Изменённый массив\n");
	for (i=0;i<STROKI;i++)
	{
		for (j=0;j<STOLBIKI;j++)
		{
		 	printf("%4.1lf  ",mas2[i][j]);
		}
		printf("\n");
	}
}
//создание 2-ого массива
double create_mas2(int mas[][STOLBIKI],double mas_ar[STROKI])
{
	int i,j;	
	double mas2[STROKI][STOLBIKI];
	for (i=0;i<STROKI;i++)
	{
		for (j=0;j<STOLBIKI;j++)
		{
			if (j%2==0)
			{
				mas2[i][j]=mas[i][j]+mas_ar[i];
			}
			else
			{
				mas2[i][j]=mas[i][j];
			}
		}
	}
	print_mas2(mas2);
}	

int main()
{
  int mas[STROKI][STOLBIKI];
  double mas_ar[STROKI];
  create_mas(mas);
  print_mas(mas);
  arithmetic_mean(mas,mas_ar);
  create_mas2(mas,mas_ar);
}

