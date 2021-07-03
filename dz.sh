#! /bin/bash
flag=True
count_word=0
count_number=0
count_prep=0
while [ $flag = True ]
do
	echo Введите символ
	read simvol
	case $simvol in 
		[A-z]|[А-я]) ((count_word++));;
		[0-9]) ((count_number++));;
		[,.:-]) ((count_prep++));;
		*) flag=False;;
	esac
done
echo Количество букв\: $count_word
echo Количество цифр\: $count_number
echo Количество знаков препинания\:  $count_prep

