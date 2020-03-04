#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <math.h>
#define uint unsigned int
using std::cout;
using std::endl;
struct subarray {
	uint low;
	uint high;
	int sum;
};
subarray bruteForce(int *, uint, uint);
subarray findMaximumSubarray(int *, uint, uint);
subarray findMaxCrossingSubarray(int *, uint, uint, uint);

int main() {
	clock_t start, finish;
	double bruteTime, divideTime;
	srand((unsigned)time(NULL));
	int L = -100, R = 100;
	for (uint len = 1; len <= 2; len++) {
		int A[2];
		for (uint i = 0; i != len; i++) {
			A[i] = rand() % (int)(R - L + 1) + L;
		}
		start = clock();
		bruteForce(A, 0, len - 1);
		finish = clock();
		bruteTime = (double)(finish - start) / CLOCKS_PER_SEC;
		start = clock();
		findMaximumSubarray(A, 0, len - 1);
		finish = clock();
		divideTime = (double)(finish - start) / CLOCKS_PER_SEC;
		cout << "BruteTime is: " << bruteTime << " seconds.\t"
			<< "DivideTime is: " << divideTime << " seconds." << endl;
	}
	return 0;
}

subarray bruteForce(int *A, uint low, uint high) {
	int max = A[low];
	subarray arr = { 0, 0, 0 };
	for (uint i = low; i <= high; i++) {
		int sum = 0;
		for (uint j = i; j <= high; j++) {
			sum += A[j];
			if (sum > max) {
				arr.sum = sum;
				arr.low = i;
				arr.high = j;
			}
		}
	}
	return arr;
}

subarray findMaximumSubarray(int *A, uint low, uint high) {
	if (high == low) {
		subarray arr = { 0, 0, 0 };
		arr.low = low;
		arr.high = high;
		arr.sum = A[low];
		return arr;
	}
	else {
		uint mid = (low + high) / 2;
		subarray subLeft = findMaximumSubarray(A, low, mid);
		subarray subRight = findMaximumSubarray(A, mid, high);
		subarray subCross = findMaxCrossingSubarray(A, low, mid, high);
		if (subLeft.sum >= subRight.sum && subLeft.sum >= subCross.sum)
			return subLeft;
		else if (subRight.sum >= subLeft.sum && subRight.sum >= subCross.sum)
			return subRight;
		else
			return subCross;
	}
}

subarray findMaxCrossingSubarray(int *A, uint low, uint mid, uint high) {
	int left_sum = A[low];
	uint max_left = mid;
	int sum = 0;
	for (uint i = mid; i >= low; i--) {
		sum = sum + A[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = A[mid + 1];
	uint max_right = mid + 1;
	sum = 0;
	for (uint j = mid + 1; j <= high; j++) {
		sum = sum + A[j];
		if (sum > left_sum) {
			right_sum = sum;
			max_right = j;
		}
	}
	subarray arr;
	arr.low = max_left;
	arr.high = max_right;
	arr.sum = left_sum + right_sum;
	return arr;
}