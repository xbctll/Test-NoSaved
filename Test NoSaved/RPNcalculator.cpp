#include"RPNcalculator.h"



bool IsbiggerOperator(char ch, char top) {
	if ((ch == '*' || ch == '/') && (top == '+' || top == '-'))return true;
	return false;
}


void RPNcalculator(const std::string& s) {
	std::vector<char>result;
	std::stack<char>st;
	for (auto& ch : s) {
		if (ch >= '0' && ch <= '9') {
			result.push_back(ch);
		}
		else {
			if (ch == '(') {
				st.push(ch);
			}
			if (!st.empty() && ch == ')') {
				while (!st.empty() && st.top() != '(') {
					result.push_back(st.top());
					st.pop();
				}
				st.pop();
			}
			if (ch == '+' || ch == '-' || ch == '/' || ch == '*') {
				while (!st.empty() && st.top() != '(' && !IsbiggerOperator(ch, st.top())) {
					result.push_back(st.top());
					st.pop();
				}
				st.push(ch);

			}

		}
	}
	while (!st.empty()) {
		result.push_back(st.top());
		st.pop();
	}
	for (const auto& e : result) {
		std::cout << e;
	}
}