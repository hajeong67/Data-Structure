#include <iostream>
using namespace std;

// 단순 연결 리스트 노드 구조체
struct Node {
    int data;
    Node* next;
};

// 단순 연결 리스트 노드 추가 함수
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

// 단순 연결 리스트 노드 값을 모두 더하는 함수
int sumList(Node* head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

int main() {
    // 단순 연결 리스트 생성
    Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    // 단순 연결 리스트의 모든 데이터 값을 더한 합 출력
    cout << "Sum of all elements in the list is " << sumList(head) << endl;

    return 0;
}