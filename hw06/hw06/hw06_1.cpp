#include <iostream>
using namespace std;

// �ܼ� ���� ����Ʈ ��� ����ü
struct Node {
    int data;
    Node* next;
};

// �ܼ� ���� ����Ʈ ��� �߰� �Լ�
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

// �ܼ� ���� ����Ʈ ��� ���� ��� ���ϴ� �Լ�
int sumList(Node* head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

int main() {
    // �ܼ� ���� ����Ʈ ����
    Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    // �ܼ� ���� ����Ʈ�� ��� ������ ���� ���� �� ���
    cout << "Sum of all elements in the list is " << sumList(head) << endl;

    return 0;
}