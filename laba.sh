#!/bin/bash
max=0
min=0
for i in $*
do
	word=`expr "$i" : '.*[A-z]'`
	(( count_word += $word ))
	number=`expr "$i" : '.*[0-9]*.*'`
	(( count_number+=$number ))
	(( min=$count_number - $count_word ))
	if [[ $min -le 0]]
		then 
		(( min $count_word - $count_number ))
		fi
if [[ $min -ge $max ]]
	then 
	max=$min
	imax=$i
	fi
done
(( otn = $count_number / $count_word ))
echo otn=$count_number / $count_word
