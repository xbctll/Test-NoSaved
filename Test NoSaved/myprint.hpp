#pragma once
#include<iostream>
#include<vector>


class myprint {
	public:
		template<typename T>
		static void print(const T& val);
		template<typename container>
		static void containerprint(const container& v);
}; 


template<typename T>
void myprint::print(const T& val) {
	std::cout << val <<"\n";
}

template<typename container>
void myprint::containerprint(const container& v) {
	for (const auto& it :v) {
		std::cout << it << " ";
	}
	std::cout << std::endl;
}