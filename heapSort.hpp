#pragma once
#include<vector>
template<typename T,typename Comparator = std::less<T>()>
class BinaryHeap {
public:
	explicit BinaryHeap(int capacity = 100);
	explicit BinaryHeap(const std::vector<T>& items);
	bool isEmpty();
	void insert(const T& x);
	void insert(T&& x);
	void deleteMin();
	const T &findMin() const;
	void makeEmpty();
private:
	int currSize;
	std::vector<T> vec;
	void buildHeap();
	int percolateDown(int i);
	int percolateUp(int i);
	int properParent(int i);
	int leftChild(int i);
	int rightChild(int i);
	bool isRoot(int i);
	int parent(int i);
	bool hasParent(int i);
	bool hasLeftChild(int i);
	bool hasRightChild(int i);
};
template<typename T,typename Comparator>
BinaryHeap<T, Comparator>::BinaryHeap(int capacity):currSize(capacity){

}
template<typename T, typename Comparator>
BinaryHeap<T, Comparator>::BinaryHeap(const std::vector<T>& items) : array(items) {
	buildHeap();
}
template<typename T, typename Comparator>
bool BinaryHeap<T, Comparator>::isEmpty(){
	return currSize == 0;
}
template<typename T, typename Comparator>
void BinaryHeap<T, Comparator>::insert(const T& x) {
}
template<typename T, typename Comparator>
void BinaryHeap<T, Comparator>::insert(T&& x) {
}
template<typename T, typename Comparator>
void BinaryHeap<T, Comparator>::deleteMin();
template<typename T, typename Comparator>
const T& BinaryHeap<T, Comparator>::findMin() const {
}
template<typename T, typename Comparator>
void BinaryHeap<T, Comparator>::makeEmpty() {
}
template<typename T, typename Comparator>
void BinaryHeap<T, Comparator>::buildHeap() {

}
template<typename T, typename Comparator>
int BinaryHeap<T, Comparator>::percolateDown(int i){
	while (i < vec.size()) {
		int j = properParent(i);
		if (i == j) {
			break;
		}
		std::swap(vec[i], vec[j]);
		i = j;
	}
	return i;
}
template<typename T, typename Comparator>
int BinaryHeap<T, Comparator>::percolateUp(int i) {
	while (!isRoot(i)) {
		int j = parent(i);
		if (Comparator(vec[i],vec[j])) {
			break;
		}
		std::swap(vec[i], vec[j]);
		i = j;
	}
	return i;
}
template<typename T, typename Comparator>
int BinaryHeap<T, Comparator>::properParent(int i) {
	if (vec[i] >= vec[leftChild[i]] && vec[i] >= vec[leftChild[i] + 1]) {
		return i;
	}
	else if (vec[i] < vec[leftChild(i)] && vec[leftChild(i)] >= vec[leftChild(i) + 1]) {
		return leftChild(i)
	}
	else if (vec[i] < vec[leftChild(i)+1] && vec[leftChild(i)] < vec[leftChild(i) + 1]) {
		return leftChild(i) + 1;
	}
}
template<typename T, typename Comparator>
int BinaryHeap<T, Comparator>::leftChild(int i) {
	return 2 * i + 1;
}
template<typename T, typename Comparator>
int BinaryHeap<T, Comparator>::rightChild(int i) {
	return leftChild(i) + 1;
}
template<typename T, typename Comparator>
int BinaryHeap<T, Comparator>::parent(int i) {
	return (i - 1) >> 1;
}
template<typename T, typename Comparator>
bool BinaryHeap<T, Comparator>::hasParent(int i) {
	return i != 0;
}
template<typename T, typename Comparator>
bool BinaryHeap<T, Comparator>::hasLeftChild(int i) {
	return leftChild(i) < vec.size();
}
template<typename T, typename Comparator>
bool BinaryHeap<T, Comparator>::hasRightChild(int i) {
	return rightChild(i) < vec.size();
}