#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "MovingAverage.h"

using namespace std;

void printData(double* dt, unsigned short length);

int main(void) {
	MovingAverage* movingAve = new MovingAverage(5);
	double* my_data = movingAve->getData();
	printData(my_data,5);
	movingAve->~MovingAverage();
	return EXIT_SUCCESS;
}

inline void printData(double* dt, unsigned short length){
	cout << "[ ";
	for (unsigned short j=0;j<length;j++){
		cout << dt[j] << " ";
	}
	cout << "]" << endl;
}
