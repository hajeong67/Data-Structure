#include "CircularIntQueue.h"
#include <ctime>

class CircularSimulator
{
private:
    int maxStudent; //������ �� �ο� ��
    double perticipate; //�����ð��� ����ϴ� �л� ��
    int couple; //���� �ּ��� ������ Ŀ���� ���� ��ȣ
    int count; //�л� ��ȣ
    int student; //������ �л� ��
    double probArrival; //�����ð� �� ���ÿ� ������ ��� �л� ��
    int m;
    int f;
    int random; //���� ������

    CircularIntQueue que;
    //���� ���ڸ� �����Ͽ� �� ���� ���ο� ���� �ð� �ڵ� ���� �ڵ�

    double Random()
    {
        return rand() / (double)RAND_MAX;
    }

    bool IsNewStudent()
    {
        return (Random() > probArrival);
    }

public:
    CircularSimulator()
    {
        count = couple = m = f = student = 0;
    }

    void readSimulationParameters()
    {
        cout << "�ùķ��̼� �� �ִ� �ο�(��:100) = ";
        cin >> maxStudent;
        cout << "�����ð��� ������ �л� ��(��:0.5) = ";
        cin >> probArrival;
    }

    void run()
    {
        CircularIntQueue male, female; //���л� ���л�
        while (count < maxStudent)
        {
            cout << count + 1 << "��° �õ�" << endl;
            if (IsNewStudent())
            {
                student++;
                random = rand() % 2;
                if (!random)
                {
                    male.enqueue(count);
                    m++;
                    cout << "���л��� �����߽��ϴ�" << endl;
                }

                else
                {
                    female.enqueue(count);
                    f++;
                    cout << "���л��� �����߽��ϴ�" << endl;
                }
            }

            else
            {
                cout << "�ƽ��Ե� " << count << " �л��� �ٺ��� �������� ���߽��ϴ�" << endl;
            }

            if (!male.isEmpty() && !female.isEmpty())
            {
                int boyfriend, girlfriend;
                boyfriend = male.dequeue();
                girlfriend = female.dequeue();

                cout << "���� ����! " << boyfriend << "��" << girlfriend << "�� Ŀ���� �Ǿ����ϴ�" << endl << endl;
                couple++;
            }

            else
                cout << "���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�" << endl << endl;
            count++;
        }
    }

    void printStat()
    {
        cout << "=================================================================" << endl;
        cout << "���ÿ� ������ �� �л� ��= " << maxStudent << endl;
        cout << "���ÿ� ������ �л� ��= " << student << endl;
        cout << "����(���л�:���л�) = " << m << " : " << f << endl;
        cout << "����� Ŀ�� ��= " << couple << endl;
        cout << "��Ÿ��� �ַε�= " << maxStudent - 2 * (couple) << endl;
    }
}; 