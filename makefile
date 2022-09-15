lab2:

	echo "running program Ex1.5\n"
	make compile-file dir="lab-2" f="ex15"
	echo "running program Ex1.11\n"
	# echo "using 1, 10 as arguments\n"
	make compile-file dir="lab-2" f="ex11"
	cd ..
	

compile-file: 
	cd ${dir} && g++ ${f}.cpp -o ${f} 
	cd ${dir} && ./${f}







