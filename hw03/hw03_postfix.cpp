#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string expression) {
    stack<int> S;

    // ���ڿ����� �ϳ��� �����鼭 postfix ���
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        // �ǿ������� ���, ���ÿ� push
        if (isdigit(c)) {
            S.push(c - '0');
        }
        // �������� ���, ���ÿ��� �ǿ����� �� �� pop �� ���� ����� �ٽ� ���ÿ� push
        else {
            int operand2 = S.top();
            S.pop();
            int operand1 = S.top();
            S.pop();

            switch (c) {
            case '+':
                S.push(operand1 + operand2);
                break;
            case '-':
                S.push(operand1 - operand2);
                break;
            case '*':
                S.push(operand1 * operand2);
                break;
            case '/':
                S.push(operand1 / operand2);
                break;
            }
        }
    }

    // ���� ��� ��ȯ
    return S.top();
}

int main() {
    string postfix = "ABE+D-*";
    cout << "Postfix ����: " << postfix << endl;

    // (1) ������ �ִ� ũ�� ���ϱ�
    int maxStackSize = 0;
    stack<int> S;
    for (int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) {
            S.push(postfix[i] - '0');
            maxStackSize = max(maxStackSize, (int)S.size()); // ���� ���� ũ��� �ִ� ũ�� �� �� ����
        }
        else {
            int operand2 = S.top();
            S.pop();
            int operand1 = S.top();
            S.pop();
            S.push(0); // ���� ����� ���ÿ� push���� �ʰ� ����
        }
    }
    cout << "(1) ������ �ִ� ũ��: " << maxStackSize << endl;

    // (2) ����° ����Ǵ� �����ڸ� ó���ϱ� ������ ���� ����
    stack<int> T = S; // ���� ����
    for (int i = postfix.length() - 1; i >= 0; i--) {
        if (isdigit(postfix[i])) {
            T.pop();
        }
        else {
            T.push(0); // ���� ����� ���ÿ� push���� �ʰ� ����
            if (T.size() == maxStackSize) { // �ִ� ���� ũ�⿡ �����ϸ� ��� �� ����
                cout << "(2) ����° ����Ǵ� �����ڸ� ó���ϱ� ������ ���� ����: ";
                while (!T.empty()) {
                    cout << T.top() << " ";
                    T.pop();
                }
                cout << endl;
                break;
            }
        }
    }

    // (3) ��� ��� ���
    int result = evaluatePostfix(postfix);
    cout << "(3) ��� ���: " << result << endl;