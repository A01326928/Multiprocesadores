/*
	Miguel Angel Fierro Gutiérrez
	A01326928

	Multipliación de una matriz NxN por sí misma por los métodos: Natural, 
	Unrolled, y Unrolled and Jammed.
*/

#include <stdio.h>
#include <omp.h>

int main(){
	int n = 500; // Medida de la matriz
	double x = 0.0;
	float c[n][n], c2[n][n], c3[n][n], a[n][n];

	// Construcción de una matriz NxN
	//printf("Matriz NxN inicial:\n");
	for(int ai = 0; ai < n; ai++){
		for(int aj = 0; aj < n; aj++){
			a[ai][aj] = x;
			//printf("%.2f ", a[ai][aj]);
		}
		x = x+1.0;
		//printf("\n");
	}

	printf("\n\n\n");
	// Variables para lectura de tiempos de ejecución
	float t1, t2, t3, t4, t5, t6, time, time2, time3;

	// Forma natural para la multiplicación de matrices
	printf("Multiplicación de forma natural:\n");
	t1 = omp_get_wtime();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			c[i][j] = 0.0;
			for(int k = 0; k < n; k++){
				c[i][j] = c[i][j]+(a[i][k]*a[k][j]);
			}
			//printf("%.2f ",c[i][j]);
		}
		//printf("\n");
	}
	t2 = omp_get_wtime();
	time = t2-t1;
	printf("Tiempo de ejecución: %f segundos\n", time);

	printf("\n\n\n");

	// Algoritmo Unrolled para la multiplicación de matrices
	printf("Multiplicación Unrolled:\n");
	t3 = omp_get_wtime();
	
	for(int j = 0; j < n; j+=2){
		for(int i = 0; i < n; i++){
			c2[i][j] = 0.0;
			for(int k = 0; k < n; k++){
				c2[i][j] = c2[i][j]+(a[i][k]*a[k][j]);
			}
		}
		for(int i = 0; i < n; i++){
			c2[i][j+1] = 0.0;
			for(int k = 0; k < n; k++){
				c2[i][j+1] = c2[i][j+1]+(a[i][k]*a[k][j+1]);

			}
		}
	}

	t4 = omp_get_wtime();
	time2 = t4-t3;

	//Impresión de la matriz resultante
	/*for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%.2f ", c2[i][j]);
		}
		printf("\n");
	}*/

	printf("Tiempo de ejecución: %f segundos\n", time2);
	
	printf("\n\n\n");

	// Algoritmo Unrolled and Jammed para la multiplicación de matrices
	printf("Multiplicación Unrolled and Jammed:\n");
	t5 = omp_get_wtime();
	
	for(int j = 0; j < n; j+=2){
		for(int i = 0; i < n; i++){
			c3[i][j] = 0.0;
			c3[i][j+1] = 0.0;
			for(int k = 0; k < n; k++){
				c3[i][j] = c3[i][j]+(a[i][k]*a[k][j]);
				c3[i][j+1] = c3[i][j+1]+(a[i][k]*a[k][j+1]);
			}
		}
	}

	t6 = omp_get_wtime();
	time3 = t6-t5;

	//Impresión de la matriz resultante
	/*for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%.2f ", c3[i][j]);
		}
		printf("\n");
	}*/

	printf("Tiempo de ejecución: %f segundos\n", time3);	
}