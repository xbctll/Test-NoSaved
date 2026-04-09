#pragma once
#include<string>

class Person {
public:
	Person(std::string name, int age);
	std::string m_name;
	int m_age;
	~Person(){}
};
