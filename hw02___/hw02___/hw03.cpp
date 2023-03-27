#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// ������ �켱 ���� ��ȯ �Լ�
int prec(char ch) {
	switch (ch) {
	case '+': case '-':
		return 1;
	case '*': case '/':
		return 2;
	case '(':
		// �����δ� �켱������ �� ������ ���� ��ȣ�� top�� ��� ������� push�ؾ��ϹǷ�
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
			// �����ڸ� ������ ���� ����� �����ڿ� �켱���� ��
			// ���� �������� �������� �켱 ������ �� ũ�� �ش� �����ڸ� ���ÿ� ����
			// �۰ų� ������ ���� ����� �����ڸ� ��ȯ ���ڿ��� �߰��ϰ� �ٽ� �ݺ�
		case '+': case '-':	case '*': case '/':
			while (!st.empty() && prec(ch) <= prec(st.top())) {
				answer += st.top();
				st.pop();
			}
			st.push(ch);
			break;

			// ���� ��ȣ�� ������ ���ÿ� ����
		case '(':
			st.push(ch);
			break;

			// ������ ��ȣ�� ������ ���ÿ��� ���� ��ȣ�� ���ö����� 
			// ��� �����ڸ� ��ȯ ���ڿ��� �߰��ϰ� pop. ���� ��ȣ�� ����
		case ')':
			while (!st.empty() && st.top() != '(') {
				answer += st.top();
				st.pop();
			}
			st.pop(); //���� ��ȣ
			break;

			// �ǿ����ڴ� �ٷ� ��ȯ ���ڿ��� �߰�
		default:
			answer += ch;
			break;
		}
	} //for�� ��

	//ó���� ���ڰ� ǥ��Ŀ� �������� �ʴٸ� ���ÿ� �����ִ� ��� ������ ��ȯ ǥ��Ŀ� �߰��� pop
	while (!st.empty()) {
		answer += st.top();
		st.pop();
	}

	cout << answer;

	return 0;
}