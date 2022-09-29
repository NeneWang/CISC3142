lab4:
	echo "running program Ex3.17\n"
	make compile-file-input dir="lab-4" f="ex317" inputfile="inputfile317"
	make compile-file dir="lab-4" f="ex323"
	make compile-file dir="lab-4" f="ex428"
	
	make compile-file-input dir="lab-4" f="p1" inputfile="inputfilep1"
	make compile-file-input dir="lab-4" f="p2" inputfile="inputfilep2"



lab2:

	echo "running program Ex1.5\n"
	make compile-file dir="lab-2" f="ex15"
	echo "running program Ex1.11\n"
	# echo "using 1, 10 as arguments\n"
	make compile-file dir="lab-2" f="ex11"
	cd ..
	

compile-file: 
	cd ${dir} && g++ ${f}.cpp -o ${f} 
	cd ${dir} && ./${f} < inputfile

compile-file-input: 
	cd ${dir} && g++ ${f}.cpp -o ${f} 
	cd ${dir} && ./${f} < ${inputfile}





