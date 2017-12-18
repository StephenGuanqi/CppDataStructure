//
// Created by Guanqi Yu on 12/18/17.
//

#include <iostream>
#include <vector>

using namespace std;
using sz = vector<int>::size_type;


void merge(vector<int> &vec, vector<int> &aux, sz left, sz mid, sz right) {

	for (sz i = left; i <= right; ++i) {
		aux[i] = vec[i];
	}

	sz i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {
		if (aux[i] < aux[j])
			vec[k++] = aux[i++];
		else
			vec[k++] = aux[j++];
	}

	while (i <= mid) vec[k++] = aux[i++];
	while (j <= right) vec[k++] = aux[j++];

}

void merge2(vector<int> &vec, vector<int> &aux, sz left, sz mid, sz right) {
	for (sz i = left; i <= right; i++)
		aux[i] = vec[i];
	sz i = left, j = mid + 1;
	for (sz k = left; k <= right; ++k) {
		if (i > mid) vec[k] = aux[j++];
		else if (j > right) vec[k] = aux[i++];
		else if (aux[i] < aux[j]) vec[k] = aux[i++];
		else vec[k] = aux[j++];
	}
}

void mergeSort(vector<int> &vec, vector<int> &aux, sz left, sz right) {
	if (right <= left) return;
	sz mid = left + (right - left) / 2;
	mergeSort(vec, aux, left, mid);
	mergeSort(vec, aux, mid + 1, right);
	merge2(vec, aux, left, mid, right);
}

void mergeSort(vector<int> &vec) {
	sz n = vec.size();
	vector<int> aux(n);
	mergeSort(vec, aux, 0, n - 1);
}