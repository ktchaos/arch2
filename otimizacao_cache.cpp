#include <stdio.h>
#include <iostream>

#include <math.h>
#include <ctime>
#include <chrono>

using namespace std;

static long N = 10; // Mudar valor de N para diferentes resultados e cenários

int selectionSort() {
	double a[N], b[N];	
    double c[N][N];
	int i, j;
	
    /* init */
    for(i = 0; i < N; i++) {
        a[i] = static_cast<char>(i);
        b[i] = 10 * i;
    }

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

    for(int i = 0; i < N; i++){
        a[i] = a[i] * 21 / 7; 
    }

    for(int i = 0; i < N; i++){
        b[i] = b[i] * 21 / 7; 
    }
    
	return 0;	
}

int invertedSelectionSort() {

	double a[N], b[N];	
    double c[N][N];
	int i, j;
	
    /* init */
    for(i = 0; i < N; i++) {
        a[i] = static_cast<char>(i);
        b[i] = 10 * i;
    }

    for (int j = N - 1; j >= 1; j--) {
        int min_idx = j;
        for (int i = j - 1; i >= 0; i--) {
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

    for(int i = 0; i < N; i++){
        a[i] = a[i] * 21 / 7; 
    }

    for(int i = 0; i < N; i++){
        b[i] = b[i] * 21 / 7; 
    }
    
	return 0;	
}

int mergeArrays(){
    struct conjunto {
        int val;
        int key;
    };

	double c[N][N];

	struct conjunto ms[N];
	
	int i, j;
	
	/* Inicialização */
	for(i = 0; i < N; i++) {
        ms[i].val = static_cast<char>(i);
        ms[i].key = i * 10;
    }

    for (int j = N - 1; j >= 0; j--) {
        int min_idx = j;
        for (int i = j - 1; i >= 0; i--) {
        if (ms[i].val < ms[min_idx].val)
            min_idx = i;
        }
        if (ms[j].val != ms[min_idx].val) {
            int aux1 = ms[j].val;
            ms[j].val = ms[min_idx].val;
            ms[min_idx].val = aux1;

            int aux2 = ms[j].key;
            ms[j].key = ms[min_idx].key;
            ms[min_idx].key = aux2;
        }
    }

	return 1;
}

int main() {
    // inveted selection sort function
	auto t3 = std::chrono::high_resolution_clock::now();
	invertedSelectionSort();
	auto t4 = std::chrono::high_resolution_clock::now();

    auto duration2 = (std::chrono::duration_cast<std::chrono::microseconds>( t4 - t3 ).count());
    float time2 = (float)duration2/1000000;
    std::cout << "Inverted selection sort = " << time2 << " segundos." << std::endl;

    // merge arrays function
	auto t5 = std::chrono::high_resolution_clock::now();
	mergeArrays();
	auto t6 = std::chrono::high_resolution_clock::now();

    auto duration3 = (std::chrono::duration_cast<std::chrono::microseconds>( t6 - t5 ).count());
    float time3 = (float)duration3/1000000;
    std::cout << "Merge arrays = " << time3 << " segundos." << std::endl;

    // selection sort function
    auto t1 = std::chrono::high_resolution_clock::now();
	selectionSort();
	auto t2 = std::chrono::high_resolution_clock::now();

    auto duration1 = (std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count());
    float time1 = (float)duration1/1000000;
    std::cout << "Seleciton sort = " << time1 << " segundos." << std::endl;

    return 0;
}