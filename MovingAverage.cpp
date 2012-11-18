#include "MovingAverage.h"

void MovingAverage::init() {
	filter_complete = false;
	index = -1;
	sum = 0;
	average = 0;
	data = new double[filter_length];
	clear();
}
MovingAverage::MovingAverage(unsigned short filterLength) {
	filter_length = filterLength;
	init();
}

MovingAverage::MovingAverage() {
	filter_length = default_filter_length;
	init();
}

MovingAverage::~MovingAverage() {
	delete[] data;
}
void MovingAverage::clear() {
	for (unsigned short i = 0; i < filter_length; i++) {
		data[i] = 0;
	}
}

void MovingAverage::add(double x) {
	index = (index + 1) % filter_length;
	sum -= data[index];
	data[index] = x;
	sum += x;
	if (!filter_complete && index == filter_length - 1) {
		filter_complete = true;
	}
	if (filter_complete) {
		average = sum / filter_length;
	} else {
		average = sum / (index+1);
	}
}

double MovingAverage::getCurrentAverage() {
	return average;
}

double* MovingAverage::getData() {
	return data;
}

unsigned short MovingAverage::getFilterLength() {
	return filter_length;
}
