#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX_QUEUE_SIZE 100

inline void error(char* str)
{
    cout << str << endl;
    exit(1);
}
class CircularStudent
{
protected:
    int front; //첫 번째 요소 앞의 위치
    int rear; //마지막 요소 위치
    char** data;
public:
    CircularStudent()
    {
        front = rear = 0;
        data = new char* [MAX_QUEUE_SIZE];
        for (int i = 0; i < MAX_QUEUE_SIZE; i++)
            data[i] = new char[20];
    }
    ~CircularStudent()
    {
        for (int i = 0; i < MAX_QUEUE_SIZE; i++)
            delete[]data[i];
        delete[]data;
    }
    bool isEmpty()
    {
        return front == rear;
    }
    bool isFull()
    {
        return (rear + 1) % MAX_QUEUE_SIZE == front;
    }
    void enqueue(char* name) //큐에 삽입
    {
        if (isFull())
            error("error:큐가 포화상태입니다\n");
        else
        {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            strcpy(data[rear], name);
        }
    }
    char* dequeue() //첫 항목을 큐에서 빼서 반환
    {
        if (isEmpty())
            error("Error: 큐가 공백상태입니다\n");
        else
        {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }

    char* peek() //첫 항목을 큐에서 빼지 않고 반환
    {
        if (isEmpty())
            error("Error: 큐가 공백상태입니다\n");
        else
            return data[(front + 1) % MAX_QUEUE_SIZE];
    }

    void display() //큐의 모든 내용을 순서대로 출력
    {
        cout << "학생 : ";
        if (!isEmpty())
        {
            int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
            for (int i = front + 1; i <= maxi; i++)
                cout << data[i % MAX_QUEUE_SIZE] << " ";
        }

        else
            cout << "학생이 아직 없습니다";
        cout << endl;
    }
};