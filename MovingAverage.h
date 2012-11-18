#ifndef MOVING_AVERAGE__H
#define MOVING_AVERAGE__H

class MovingAverage {

private:
	const static unsigned short default_filter_length = 5;
	// Length of the filter
	unsigned short filter_length;
	// Vector with raw data
	double * data;
	double sum, average;
	unsigned short index;
	bool filter_complete;
	void init();

public:
	/**
	 * Creates a new instance of MovingAverage with
	 * given filter length.
	 */
	MovingAverage(unsigned short);
	/**
	 * Creates a new instance of MovingAverage with
	 * the default filter length value 5.
	 */
	MovingAverage();
	/**
	 * Releases the memory objects associated with the
	 * current MovingAverage instance.
	 */
	~MovingAverage();
	/**
	 * Adds a new element in the Moving Average vector.
	 * Updates the current average.
	 */
	void add(double);
	/**
	 * Returns the Filter's Length.
	 */
	unsigned short getFilterLength();
	/**
	 * Returns the current average as update after the invocation
	 * of MovingAverage::add(double).
	 */
	double getCurrentAverage();
	/**
	 * Clears the vector of data by setting it to zero.
	 */
	void clear();
	/**
	 * Returns the raw data that are currently stored
	 * in an internal vector.
	 */
	double* getData();
};
#endif
