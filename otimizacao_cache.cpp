#include <stdio.h>
#include <iostream>

#include <math.h>
#include <ctime>
#include <chrono>

static long N = 1000;

int main(){

	double a[N], b[N];	
    double c[N][N];
	int i, j;
	
    /* init */
    for(i = 0; i < N; i++) {
        a[i] = static_cast<char>(i);
        b[i] = 10 * i;
    }

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            c[i][j] = 5 * i;
        }
    }

    /* Selection sort */
    for (int j = 0; j < N - 1; j++) {
        int min_idx = j;
        for (int i = j + 1; i < j; i++) {
        if (b[i] < b[min_idx])
            min_idx = i;
        }
        if (b[j] != b[min_idx]) {
            int aux1 = b[j];
            b[j] = b[min_idx];
            b[min_idx] = aux1;

            int aux2 = a[j];
            a[j] = a[min_idx];
            a[min_idx] = aux2;
        }
    }

    for (int i = N - 1; i >= 0; i--) 
    std::cout << a[i] << std::endl;

    std::cout << "AGORA NOMES!!!" <<std::endl;

    for (int i = N - 1; i >= 0; i--) 
    std::cout << b[i] << std::endl;


	return 0;	
}

// int mergeArrays(){
//     struct conjunto {
//         int val;
//         int key;
//     };

// 	double c[N][N];

// 	struct conjunto ms[N];	
	
// 	int i, j;
	
// 	/* Inicialização */
// 	for (i=0; i<N; i++){
// 		ms[i].a = i*5.3;
// 		ms[i].b = 0.8+i;
// 		ms[i].d = 0.1*i;
// 	}

// 	for (int k=0; k<M; k++)
// 	for (i=0; i<N; i++){
// 		if(k==0) ms[i].d = 1.0/ms[i].a;
// 		for (j=0; j<N; j++){
// 			c[i][j] = i*0.3;
// 			c[i][j] += k + (ms[i].b * ms[i].a)/(j+1);
// 		}
// 	}
		 
// 	return 1;	
// }