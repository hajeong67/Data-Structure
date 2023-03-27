#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 연산자 우선 순위 반환 함수
int prec(char ch) {
	switch (ch) {
	case '+': case '-':
		return 1;
	case '*': case '/':
		return 2;
	case '(':
		// 실제로는 우선순위가 더 높지만 왼쪽 괄호가 top인 경우 상관없이 push해야하므로
		return 0;
	}
}

int main() {
	string input;
	string answer;
	stack<char> st;

	getline(cin, input);

	for (int i = 0; i < input.size(); i++) {
		char ch = input[i];
		switch (ch) {
			// 연산자를 만나면 스택 상단의 연산자와 우선순위 비교
			// 지금 넣으려는 연산자의 우선 순위가 더 크면 해당 연산자를 스택에 삽입
			// 작거나 같으면 스택 상단의 연산자를 변환 문자열에 추가하고 다시 반복
		case '+': case '-':	case '*': case '/':
			while (!st.empty() && prec(ch) <= prec(st.top())) {
				answer += st.top();
				st.pop();
			}
			st.push(ch);
			break;

			// 왼쪽 괄호가 나오면 스택에 삽입
		case '(':
			st.push(ch);
			break;

			// 오른쪽 괄호가 나오면 스택에서 왼쪽 괄호가 나올때까지 
			// 모든 연산자를 변환 문자열에 추가하고 pop. 왼쪽 괄호는 삭제
		case ')':
			while (!st.empty() && st.top() != '(') {
				answer += st.top();
				st.pop();
			}
			st.pop(); //왼쪽 괄호
			break;

			// 피연산자는 바로 변환 문자열에 추가
		default:
			answer += ch;
			break;
		}
	} //for문 끝

	//처리할 문자가 표기식에 남아있지 않다면 스택에 남아있는 모든 연산자 변환 표기식에 추가와 pop
	while (!st.empty()) {
		answer += st.top();
		st.pop();
	}

	cout << answer;

	return 0;
}