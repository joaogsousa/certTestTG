all: program

program: main2_certtest.c
	gcc main2_certtest.c -lmiracl -o certTest2 

help:
	@echo "Use make execute to execute with default certificates cert1 and cert2, simply make to compile and make clean to clean!"
