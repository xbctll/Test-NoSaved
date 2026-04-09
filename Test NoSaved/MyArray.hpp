#pragma once
#include<iostream>

template<typename T>
class MyArray {
public:
	int m_Size;
	int m_Capacity;
	T* m_pAddress =nullptr;
public:
	MyArray(int capacity) :m_Capacity(capacity),m_Size(0) {
		this->m_pAddress = new T[this->m_Capacity];
	}
	MyArray(const MyArray& arr);
	MyArray& operator=(const MyArray& arr);
	T& operator[](int index);
	void PushBack(const T& val);
	void PopBack();
	int GetCapacity();
	int GetSize();
	~MyArray();
};


template<typename T>
MyArray<T>::MyArray(const MyArray& arr) {
	this->m_Size = arr.m_Size;
	this->m_Capacity = arr.m_Capacity;
	this->m_pAddress = new T[arr.m_Capacity];
	for (int i = 0; i < arr.m_Size; i++) {
		this->m_pAddress[i] = arr.m_pAddress[i];
	}
}
template<typename T>
MyArray<T>& MyArray<T>:: operator=(const MyArray& arr) {
	if (this == &arr) {
		return *this;
	}
	if (this->m_pAddress != nullptr) {
		delete[] this->m_pAddress;
		this->m_pAddress = nullptr;
	}
	this->m_Size = arr.m_Size;
	this->m_Capacity = arr.m_Capacity;
	this->m_pAddress = new T[arr.m_Capacity];
	for (int i = 0; i < this->m_Size; i++) {
		this->m_pAddress[i] = arr.m_pAddress[i];
	}
	return *this;
}
template<typename T>
T& MyArray<T>::operator[](int index) {
	if (index >= 0 && index < this->m_Size) {
		return this->m_pAddress[index];
	}
}
template<typename T>
void MyArray<T>::PushBack(const T& val) {
	if (this->m_Size >= this->m_Capacity) {
		return;
	}
	this->m_pAddress[this->m_Size] = val;
	this->m_Size++;
}
template<typename T>
void MyArray<T>::PopBack() {
	if (this->m_Size == 0) {
		return;
	}
	this->m_Size--;
}
template<typename T>
int MyArray<T>::GetCapacity() {
	return this->m_Capacity;
}
template<typename T>
int MyArray<T>::GetSize() {
	return this->m_Size;
}
template<typename T>
MyArray<T>::~MyArray() {
	if (this->m_pAddress != nullptr) {
		delete[] this->m_pAddress;
		this->m_pAddress = nullptr;
	}
}