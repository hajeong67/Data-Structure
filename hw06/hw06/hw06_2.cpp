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

// �ܼ� ���� ����Ʈ���� Ư���� ������ ���� ���� ����� ������ ����ϴ� �Լ�
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
    // �ܼ� ���� ����Ʈ ����
    Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 2);
    append(&head, 4);
    append(&head, 5);

    // Ư���� ������ ���� ���� ����� ���� ��� �� ���
    int value = 2;
    cout << "The number of nodes with value " << value << " is " << countNodesWithValue(head, value) << endl;

    return 0;
}