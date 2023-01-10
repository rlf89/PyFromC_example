app: 	ex.o
	
	#-L/usr/lib/python3.10/config-3.10-x86_64-linux-gnu
	#gcc -o app ex.o -L/usr/lib -lpython3.10 -lpthread -lm -ldl -lutil
	
	gcc -o app ex.o -L/usr/lib -lpython3.10

ex.o:	ex.c
	
	gcc -Wall -Wextra -pedantic -c ex.c -I/usr/include/python3.10

clean:
	
	rm ex.o app