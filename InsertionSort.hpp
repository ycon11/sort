#pragma once
#include<iostream>
#include <functional>
//版本一
template<typename Comparator>
void insertSort(std::vector<Comparator> &vec) {
	int n = vec.size();
	for (int i = 1; i < n; i+=1) {
		Comparator tmp = std::move(vec[i]);
		int j = i;
		for ( ; j >= 1 && vec[j] > vec[j-1]; j-=1) {
			vec[j] = std::move(vec[j - 1]);
		}
		vec[j] = std::move(tmp);
	}
}
//版本二
template<typename Iter,typename Comporator>
void insertionSort(Iter begin,Iter end) {
	insertionSort(begin,end,less<decltype(*begin)>())
}
template<typename Iter, typename Comporator>
void insertionSort(Iter begin, Iter end, Comporator lessthan) {
	if (begin == end) {
		return;
	}
	for (Iter j = begin; j != end; beg++) {
		Iter p;
		Iter tmp =std::move(j)
		for (p = j; p != begin && lessthan(*tmp,*p-1); p++) {
			*p = std::move(*(p - 1));
		}
		*p = std::move(*tmp);
	}
}