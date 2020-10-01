#include <stdio.h>
#include <omp.h>

int main(){
	int n = 5;
	double x, y = 1.0;
	float c[n][n], a[n][n];

	for(int ai = 0; ai < n; ai++){
		for(int aj = 0; aj < n; aj++){
			a[ai][aj] = x;
		}
		x = x+1.0;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			c[i][j] = 0.0;
			for(int k = 0; k < n; k++){
				c[i][j] = c[i][j] + (a[i][k]*a[k][j]);
			}
			printf("%f ",c[i][j]);
		}
		printf("\n");
	}	
}