#include <stdio.h>
#include <iostream>

#include <math.h>
#include <ctime>
#include <chrono>

using namespace std;

static long N = 1;

int original() {
	struct m_struct{
		double a, b, d;
	};

	struct m_struct ms[N];
	double c[N][N];
	int i, j;
	int count1=0, count2=0;
	
	for (i=0; i<N; i++){
		ms[i].a = i*5.3;
		ms[i].b = 0.8+i;
		ms[i].d = 0.1*i;
	}

	for (i=0; i<N; i++)
		for (j=0; j<N; j++)
			c[i][j] = i*0.3;
	

	for (int k=0; k<N; k++){
		if(ms[k].a > ms[k].b){
			for (i=0; i<N; i++){
				for (j=0; j<N; j++){
					c[i][j] += k + (ms[i].b * ms[i].a)/(j+1);
				}
			}
		}
		else{
			count2++;
			for (i=0; i<N; i++){
				for (j=0; j<N; j++){
					c[i][j] += k + (ms[i].b * ms[i].a)/(j+1);
				}
			}
		}
	}
	// for (i=0; i<N; i++){
	// 	std::cout << ms[i].d << std::endl;
	// }
	
	return 1;	
}

int segunda() {
	struct m_struct{
		double a, b, d;
	};

	struct m_struct ms[N];
	double c[N][N];
	int i, j;
	int count1=0, count2=0;
	
	for (i=0; i<N; i++){
		ms[i].a = i*5.3;
		ms[i].b = 0.8+i;
		ms[i].d = 0.1*i;
	}

	for (i=0; i<N; i++)
		for (j=0; j<N; j++)
			c[i][j] = i*0.3;
	

	for (int k=0; k<N; k++){
        int y = ms[k].a > ms[k].b;
		if(y){
			for (i=0; i<N; i++){
				for (j=0; j<N; j++){
					c[i][j] += k + (ms[i].b * ms[i].a)/(j+1);
				}
			}
		}
		else{
			count2++;
			for (i=0; i<N; i++){
				for (j=0; j<N; j++){
					c[i][j] += k + (ms[i].b * ms[i].a)/(j+1);
				}
			}
		}
	}
	// for (i=0; i<N; i++){
	// 	std::cout << ms[i].d << std::endl;
	// }
	
	return 1;	
}

int main() {
	auto t1 = std::chrono::high_resolution_clock::now();
	original();
	auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = (std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count());
    float time = (float)duration/1000000;
    std::cout << "Primeira = " << time << " segundos." << std::endl;
	

	t1 = std::chrono::high_resolution_clock::now();
	segunda();
	t2 = std::chrono::high_resolution_clock::now();

    duration = (std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count());
    time = (float)duration/1000000;
    std::cout << "Segunda = " << time << " segundos." << std::endl;

    return 0;
}