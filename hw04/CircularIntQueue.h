/*
(3)���� �̿��Ͽ� ���л� ť�� ���л� ť�� �����ϰ� ť�� �Էµ� �� ��� ���ϴ�����
����� ��� ���Ѵٰ� �ϸ� ť�� �� ó���� �����Ѵ�.
*/

#include "CircularStudent.h"

class CircularStudentDeque :public CircularStudent
{
public:
    CircularStudentDeque()
    {
        front = rear = 0;
        data = new char* [MAX_QUEUE_SIZE];
        for (int i = 0; i < MAX_QUEUE_SIZE; i++)
            data[i] = new char[20];
    }

    ~CircularStudentDeque()
    {
        for (int i = 0; i < MAX_QUEUE_SIZE; i++)
            delete[]data[i];
        delete[]data;
    }

    void addRear(char* name)
    {
        enqueue(name);
    }

    char* deleteFront()
    {
        return dequeue();
    }

    char* getFront()
    {
        return peek();
    }

    void addFront(char* name) //���ܿ� ����
    {
        if (isFull())
            error("Error: ���� ��ȭ�����Դϴ�\n");
        else
        {
            strcpy(data[front], name);
            front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; //front ����
        }
    }

    char* deleteRear() //�Ĵܿ��� ����
    {
        if (isEmpty())
            error("Error: ���� ��������Դϴ�\n");
        else
        {
            char* ret;
            strcpy(ret, data[rear]);
            rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            return ret;
        }
    }

    char* getRear() //�Ĵܿ��� peek
    {
        if (isEmpty())
            error("Error: ���� ��������̺��\n");
        else
            return data[rear];
    }

    void display() //CircularQueue::display() �������̵�
    {
        cout << "���� ����: ";
        if (!isEmpty())
        {
            int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
            for (int i = front + 1; i <= maxi; i++)
                cout << data[i % MAX_QUEUE_SIZE] << " ";
        }

        else
            cout << "�л��� ���� �����ϴ�";
        cout << endl;
    }
};
