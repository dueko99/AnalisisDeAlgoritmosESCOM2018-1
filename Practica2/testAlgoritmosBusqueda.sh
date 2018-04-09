#!/bin/bash   

#Compilación de los diferentes programas según su método
gcc testLinealSearch.c -o testLinealSearch 							#Secuencial sencilla
gcc testThreadsLinealSearch.c -o testThreadsLinealSearch -pthread		#Secuencial con hilos
gcc testBinarySearch.c -o testBinarySearch 									#Binaria sencilla
gcc testThreadsBinarySearch.c -o testThreadsBinarySearch -pthread				#Binaria con hilos
gcc testBSTSearch.c -o testBSTSearch  						#Con ABB sencilla
gcc testThreadsBSTSearch.c -o testThreadsBSTSearch -pthread		#Con ABB con hilos

#BÚSQUEDA SECUENCIAL SIN HILOS
echo -e "BUSQUEDA SECUENCIAL SIN HILOS\n" >>Lineal.txt
./testLinealSearch < SortedNumbers.txt >>Lineal.txt

#BÚSQUEDA SECUENCIAL CON 2, 3 y 4 HILOS
for k in {2..4}
do
	echo -e "\nBUSQUEDA SECUENCIAL CON '$k' HILOS\n" >>Lineal.txt
	./testThreadsLinealSearch $k < SortedNumbers.txt >>Lineal.txt
done

#BÚSQUEDA BINARIA SIN HILOS
echo -e "BUSQUEDA BINARIA SIN HILOS\n" >>Binary.txt
./testBinarySearch < SortedNumbers.txt >>Binary.txt

#BÚSQUEDA BINARIA CON 2, 3 y 4 HILOS
for k in {2..4}
do
	echo -e "\nBUSQUEDA BINARIA CON '$k' HILOS\n" >>Binary.txt
	./testThreadsBinarySearch $k < SortedNumbers.txt >>Binary.txt
done

#BÚSQUEDA EN ABB SIN HILOS
echo -e "BUSQUEDA ARBOL BINARIO SIN HILOS\n" >>BST.txt
./testBSTSearch < UnsortedNumbers.txt >>BST.txt

#BÚSQUEDA EN ABB CON 2, 3 Y 4 HILOS
for k in {2..4}
do
	echo -e "\nBUSQUEDA ARBOL BINARIO CON '$k' HILOS\n" >>BST.txt
	./testThreadsBSTSearch $k < UnsortedNumbers.txt >>BST.txt
done
