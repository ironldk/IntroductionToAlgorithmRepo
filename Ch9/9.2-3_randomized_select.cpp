//9.2 - 3
//Write an iterative version of RANDOMIZED-SELECT.
//RANDOMIZED-SELECT(A, p, r, i)
//1 if p == r
//2		return A[p]
//3 q = RANDOMIZED-PARTITION(A, p, r)
//4 k = q - p + 1
//5 if i == k // the pivot value is the answer
//6		return A[q]
//7 elseif i < k
//8 return RANDOMIZED-SELECT(A, p, q - 1, i)
//9 else return RANDOMIZED-SELECT(A, q + 1, r, i - k)
#include "stdafx.h"
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using it = vector<int>::iterator;
it partition(vector<int> &A, it p, it r) {
	auto j = p;
	auto i = p;
	for (; j < r; ++j) {	//r denotes the pivot
		if (*j <= *r) {
			auto temp = *j;
			*j = *i;
			*i = temp;
			++i;
		}
		//every time before ++j, i denotes the one after the last one <= pivot
		//j denotes the last one > pivot
	}
	auto temp = *j;
	*j = *i;
	*i = temp;
	return i;
}
it randomized_partition(vector<int> &A, it p, it r) {
	auto pivot = rand() % int(r - p + 1) + p;
	auto temp = *pivot;
	*pivot = *r;
	*r = temp;
	return partition(A, p, r);
}
it randomized_select(vector<int> &A, it p, it r, int i) {
	while (p < r) {
		auto q = randomized_partition(A, p, r);
		auto k = int(q - p + 1);
		if (i == k) {
			return p + k - 1;
		}
		else if (i < k) {
			r = q - 1;
		}
		else {
			p = q + 1;
			i = i - k;
		}
	}
	return p;
}
void quick_sort(vector<int> &A, it p, it r) {
	auto q = randomized_partition(A, p, r);
	if (p < q)quick_sort(A, p, q - 1);
	if (q < r)quick_sort(A, q + 1, r);
}
int main() {
	vector<int> A = { 3, 2, 9, 0, 7, 5, 4, 8, 6, 1 };
	//quick_sort(A, A.begin(), A.end() - 1);
	for (int i = 0; i < 10; i++) {
		cout << *randomized_select(A, A.begin(), A.end() - 1, i + 1) << " ";
		//cout << A[i] << " ";
	}
	return 0;
}