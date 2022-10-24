
platground:
	make compile-file-only dir="playground" f="constThings"


lab6:
	make compile-file-only dir="lab-6" f="main"


lab5:

	echo "running program p1"
	make compile-file-input dir="lab-5" f="p1" inputfile=inputfilep1

	echo "running Program p2"
	make compile-file-only dir="lab-5" f="p2"

	echo "running Program p3"
	make compile-file-only dir="lab-5" f="p3"


	echo "running program Ex4.5\n"
	make compile-file-only dir="lab-5" f="ex45" 

save:
	git add --all
	git commit -m "random progress :sob:"
	git push origin HEAD


lab4:
	echo "running program Ex3.17\n"
	make compile-file-input dir="lab-4" f="ex317" inputfile="inputfile317"
	cd ..

	echo "running program Ex3.23\n"
	make compile-file-only dir="lab-4" f="ex323"
	cd ..

	echo "running program Ex4.28\n"
	make compile-file-only dir="lab-4" f="ex428"
	cd ..

	echo "running program Problem 1\n"
	make compile-file-input dir="lab-4" f="p1" inputfile="inputfilep1"
	cd ..

	echo "running program Problem 2\n"
	make compile-file-input dir="lab-4" f="p2" inputfile="inputfilep2"
	cd ..


lab2:

	echo "running program Ex1.5\n"
	make compile-file dir="lab-2" f="ex15"
	echo "running program Ex1.11\n"
	# echo "using 1, 10 as arguments\n"
	make compile-file dir="lab-2" f="ex11"
	cd ..
	

compile-file: 
	cd ${dir} && g++ ${f}.cpp -o ${f} 
	cd ${dir} && ${f} < inputfile


compile-file-only: 
	cd ${dir} && g++ ${f}.cpp -o ${f} 
	cd ${dir} && ${f}

compile-file-input: 
	cd ${dir} && g++ ${f}.cpp -o ${f} 
	cd ${dir} && ${f} < ${inputfile}





