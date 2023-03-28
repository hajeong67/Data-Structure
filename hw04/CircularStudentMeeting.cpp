// CircularStudent.h ��� ������ include�մϴ�.
#include "CircularStudent.h"

int main(void)
{
    CircularStudent male, female; // ������ ���� CircularStudent ��ü�� �����մϴ�.
    char name[20];
    char gender; // ������ ������ ������ ������ �����մϴ�.

    cout << "���� �ּ� ���α׷��Դϴ�" << endl; // ���� �ּ� ���α׷��� �˸��� �޽����� ����մϴ�.
    cout << "���α׷� ���� ���Ͻø� �̸��� '�׸�'�� �Է����ּ���" << endl << endl; // ���α׷� ���� ����� �����ϴ� �޽����� ����մϴ�.

    while (1) // ���� ������ �����մϴ�.
    {
        cout << "���̸�: "; // �̸��� �Է¹޴� �޽����� ����մϴ�.
        cin >> name; // �̸��� �Է¹޽��ϴ�.

        if (!strcmp(name, "�׸�")) // �̸��� '�׸�'�� ��� ������ Ż���մϴ�.
            break;

        cout << "������ �Է��ϼ���(f or m) "; // ������ �Է¹޴� �޽����� ����մϴ�.
        cin >> gender; // ������ �Է¹޽��ϴ�.

        if (gender == 'm') // ������ ��� male ��ü�� �̸��� �߰��մϴ�.
            male.enqueue(name);

        else if (gender == 'f') // ������ ��� female ��ü�� �̸��� �߰��մϴ�.
            female.enqueue(name);

        if (!male.isEmpty() && !female.isEmpty()) // male�� female ��ü�� ��� ������� ���� ���
        {
            char boyfriend[20], girlfriend[20]; // Ŀ�� �̸��� ������ ���ڿ� �迭�� �����մϴ�.
            strcpy(boyfriend, male.dequeue()); // male ��ü���� �̸��� ������ boyfriend �迭�� �����մϴ�.
            strcpy(girlfriend, female.dequeue()); // female ��ü���� �̸��� ������ girlfriend �迭�� �����մϴ�.
            cout << "Ŀ���� ź���߽��ϴ�! " << boyfriend << "�� " << girlfriend << endl << endl; // Ŀ���� ź���ߴٴ� �޽����� Ŀ�� �̸��� ����մϴ�.
        }

        else
            cout << "���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�." << endl << endl; // Ŀ���� ���� �� ���� ���¶�� �޽����� ����մϴ�.
    }
    return 0; // ���α׷��� �����մϴ�.
}