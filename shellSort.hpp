#pragma once
#include<vector>
#include <functional>
//版本一
template<typename Comparable>
void shellSort(std::vector<Comparable> &vec) {
	for (int gap = vec.size / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < vec.size(); i+=gap) {
			Comparable tmp = std::move(a[i]);
			int j = i;
			for (; j >= gap&& tmp > vec[j - gap]; j -= gap) {
				vec[j] = vec[j - gap];
			}
			vec[j] = std::move(tmp);
		}
	}
}
//版本二
template<typename  Iter, typename Comparator>
void shellSort(Iter begin, Iter end, Comparator less);
template<typename  Iter, typename Comparator>
void shellSort(Iter begin,Iter end) {
	shellSort(begin, end, std::less<decltype<*(begin)>>());
}
template<typename  Iter, typename Comparator>
void shellSort(Iter begin, Iter end, Comparator lessThan) {
	if (begin == end) {
		return;
	}
	int size = end - begin;
	Iter beg = begin;
	for (int gap = size / 2; gap > 0;gap/=2) {
		for (Iter beg = begin + gap; beg != end;beg+=gap) {
			Comparator tmp = *beg;
			Iter p = beg;
			for (; p >= beg && lessThan(tmp ,*(p - gap));p-gap) {
				*p = *(p - gap);
			}
			*p = tmp;
		}
	}
}