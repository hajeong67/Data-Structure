#include "CircularStudent.h"

int main(void)
{
    CircularStudent male, female; //���� ����
    char name[20];
    char gender; //����

    cout << "���� �ּ� ���α׷��Դϴ�" << endl;
    cout << "���α׷� ���� ���Ͻø� �̸��� '�׸�'�� �Է����ּ���" << endl << endl;

    while (1)
    {
        cout << "���̸�: ";
        cin >> name;

        if (!strcmp(name, "�׸�"))
            break;

        cout << "������ �Է��ϼ���(f or m) ";
        cin >> gender;

        if (gender == 'm')
            male.enqueue(name);

        else if (gender == 'f')
            female.enqueue(name);

        if (!male.isEmpty() && !female.isEmpty()) //���� ���� �ѽ��� �̷� ���
        {
            char boyfriend[20], girlfriend[20];
            strcpy(boyfriend, male.dequeue());
            strcpy(girlfriend, female.dequeue());
            cout << "Ŀ���� ź���߽��ϴ�! " << boyfriend << "�� " << girlfriend << endl << endl;
        }

        else
            cout << "���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�." << endl << endl;
    }
    return 0;
}