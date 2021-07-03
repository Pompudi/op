#! /bin/bash
now_time=` date '+ %Y' `    #текущий год
other=${2:-0}   	#считывает введеный год
year=` expr "$other" \| "$now_time" `		#если ввели год то берем его, иначе берем текущий
num_mounth=(12 11 10 09 08 07 06 05 04 03 02 01)
rim=("X||" "X|" "X" "|X" "V|||" "V||" "V|" "V" "|V" "|||" "||" "|")
output=()
for (( i=11; $i!=0; i=$i-1));
do
	case ${num_mounth[$i]} in 
		[01,03,05,07,08,10,12])
			mdy=${num_mounth[$i]}/31/$year
			day=` date -d "$mdy" "+%u" `
			echo $day
			if [ $day -le $1]
				then output+=(${rim[$i]}) 
			fi
		;;
		02)
			mdy=${num_mounth[$i]}/29/$year
			if [ $? -ne 0 ]
				then mdy=${num_mounth[$i]}/28/$year
			fi
			day=` date -d "$mdy" "+%u" `
			echo $day
			if [ $day -le $1 ]
				then output+=(${rim[$i]})
			fi 
		;;
		*)
			mdy=${num_mounth[$i]}/30/$year
			day=` date -d "$mdy" "+%u" `
			echo $day
			if [ $day -le $1 ]
				then output+=(${rim[$i]}) 
			fi
		;;
	esac
done
echo $output
