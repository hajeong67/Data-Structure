#include <cstdio>
#include <stack>
using namespace std;

stack<double> s;
char c, str[101];
int n, num[27];
double a, b;

int main() {
	scanf("%d ", &n);
	scanf("%s", str);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	for (int i = 0; str[i] != NULL; i++) {
		c = str[i];
		if (c == '\n')break;
		if ((c >= 'A') && (c <= 'Z')) {
			s.push(num[c - 'A']);
		}
		else {
			a = s.top(); s.pop();
			b = s.top(); s.pop();
			switch (c) {
			case '+':
				s.push(a + b);
				break;
			case '*':
				s.push(a * b);
				break;
			case '-':
				s.push(b - a);
				break;
			case '/':
				s.push((double)b / a);
				break;
			}
		}
	}

	printf("%.2lf", s.top());

	return 0;
}