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

// 단순 연결 리스트에서 특정한 데이터 값을 갖는 노드의 개수를 계산하는 함수
int countNodesWithValue(Node* head, int value) {
    int count = 0;
    while (head != NULL) {
        if (head->data == value) {
            count++;
        }
        head = head->next;
    }
    return count;
}

int main() {
    // 단순 연결 리스트 생성
    Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 2);
    append(&head, 4);
    append(&head, 5);

    // 특정한 데이터 값을 갖는 노드의 개수 계산 및 출력
    int value = 2;
    cout << "The number of nodes with value " << value << " is " << countNodesWithValue(head, value) << endl;

    return 0;
}