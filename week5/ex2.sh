echo 13 > ex2_data

if ln ex2_data ex2_data.lock
  then
	for i in `seq 1 7`;
	  do
   	 last_num=`tail -1 ex2_data`
   	 last_num=$((last_num+1))
   	 echo $last_num >> ex2_data
 	 done
	rm ex2_data.lock
fi
