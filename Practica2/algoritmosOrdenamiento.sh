#!/bin/bash
#Arreglo de métodos
METHOD=(SequentialSearch, BinarySearch, BinTreeSearch)
#Arreglo de numero de hilos
THREAD=(2,3,4)
#Arreglo de numeros a buscar
KEY=(322486, 14700764, 3128036, 6337399, 61396,
10393545, 2147445644, 1295390003, 450057883, 187645041,
1980098116, 152503, 5000, 1493283650, 214826, 1843349527,
1360839354, 2109248666 , 2147470852, 0)
#Arreglo de tamaños del problema
N=(100, 1000, 5000, 10000, 50000, 100000, 200000, 400000, 600000,
800000, 1000000, 2000000, 3000000, 4000000, 5000000, 6000000,
7000000, 8000000, 9000000,  10000000)

#Ciclo para la compilación de los programas
for (( i = 0; i < 3; i++ )); do

	gcc ${METHOD[i]}.c -pthread -o ${METODOS[i]}.o
	echo  "Tiempos para: ${METHOD[i]} \n">${METHOD[i]}.txt
	for (( j = 0; j < 3; j++ )); do
		echo  "Hilos: ${THREAD[j]} \n">>${METHOD[i]}.txt
		for (( k = 0; k < 20; k++ )); do
			echo  "Numero a buscar: ${KEY[k]} \n">>${METHOD[i]}.txt
			for (( l = 0; l < 20; l++ )); do
				echo  "Tamaño del problema: ${N[l]} \n">>${METHOD[i]}.txt
				./${METHOD[i]}.o ${N[l]} ${THREAD[j]} ${KEY[k]} <10millones.txt >>${METODOS[i]}.txt
			done
		done
	done
