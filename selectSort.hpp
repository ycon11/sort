#pragma once
#include<vector>
#include <functional>
//版本一
template<typename Comparator>
void selectSort(std::vector<Comparator> &vec) {
	for (int i = 0; i < vec.size();i++) {
		int min = i;
		for (int j = i+1; j < vec.size(); j++) {
			if (vec[j] < vec[min]) {
				min = j;
			}
			std::swap(vec[i],vec[min]);
		}
	}
}
//版本二
template<typename Iter, typename Comparator>
void selectSort(Iter begin, Iter end, Comparator lessThan);
template<typename Iter ,typename Comparator>
void selectSort(Iter begin,Iter end) {
	selectSort(begin, end, std::less<decltype<*begin>>());
}
template<typename Iter, typename Comparator>
void selectSort(Iter begin, Iter end,Comparator lessThan) {
	for (Iter iter = begin; iter != end; iter++) {
		Iter min = iter;
		for (Iter p = iter + 1; p != end; p++) {
			if (lessThan(*p, *min)) {
				min = p;
			}
		}
		std::swap(*min, *iter);
	}
}