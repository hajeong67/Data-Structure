#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string expression) {
    stack<int> S;

    // 문자열에서 하나씩 읽으면서 postfix 계산
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        // 피연산자인 경우, 스택에 push
        if (isdigit(c)) {
            S.push(c - '0');
        }
        // 연산자인 경우, 스택에서 피연산자 두 개 pop 후 연산 결과를 다시 스택에 push
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

    // 최종 결과 반환
    return S.top();
}

int main() {
    string postfix = "ABE+D-*";
    cout << "Postfix 수식: " << postfix << endl;

    // (1) 스택의 최대 크기 구하기
    int maxStackSize = 0;
    stack<int> S;
    for (int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) {
            S.push(postfix[i] - '0');
            maxStackSize = max(maxStackSize, (int)S.size()); // 현재 스택 크기와 최대 크기 비교 후 갱신
        }
        else {
            int operand2 = S.top();
            S.pop();
            int operand1 = S.top();
            S.pop();
            S.push(0); // 연산 결과를 스택에 push하지 않고 버림
        }
    }
    cout << "(1) 스택의 최대 크기: " << maxStackSize << endl;

    // (2) 세번째 수행되는 연산자를 처리하기 직전의 스택 상태
    stack<int> T = S; // 스택 복사
    for (int i = postfix.length() - 1; i >= 0; i--) {
        if (isdigit(postfix[i])) {
            T.pop();
        }
        else {
            T.push(0); // 연산 결과를 스택에 push하지 않고 버림
            if (T.size() == maxStackSize) { // 최대 스택 크기에 도달하면 출력 후 종료
                cout << "(2) 세번째 수행되는 연산자를 처리하기 직전의 스택 상태: ";
                while (!T.empty()) {
                    cout << T.top() << " ";
                    T.pop();
                }
                cout << endl;
                break;
            }
        }
    }

    // (3) 계산 결과 출력
    int result = evaluatePostfix(postfix);
    cout << "(3) 계산 결과: " << result << endl;