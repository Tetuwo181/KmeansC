k_means: cluster.o dataset.o k_means.cluster
	gcc -o k_means cluster.o dataset.o 
cluster.o: cluster.c
	gcc -c cluster.c
dataset.o: dataset.c
	gcc -c dataset.c