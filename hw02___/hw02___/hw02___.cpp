#include "pch.h"
#include <iostream>
using namespace std;

#define MAX_DEGREE 80 

class Polynomial
{
    int degree; //다항식의 최고 차수
    float coef[MAX_DEGREE]; //각 항에 대한 계수

public:
    Polynomial() //생성자:최대 차수를 0으로 초기화
    {
        degree = 0;
    }

    //다항식의 내용을 입력받는 함수
    void read()
    {
        cout << "다항식의 최고 차수를 입력하십시오: ";
        cin >> degree;
        cout << "각 항의 개수를 입력하시오 (총 " << degree + 1 << "개): ";

        for (int i = 0; i <= degree; i++)
            cin >> coef[i];
    }

    //다항식의 내용을 화면에 출력하는 함수
    void display(const char* str = " Poly = ") //디폴트 매개변수 사용
    {
        cout << "\t" << str;

        for (int i = 0; i < degree; i++)
        {
            if (coef[i])
                cout << coef[i] << "x^(" << degree - i << ")";
            if (coef[i + 1])
                cout << " + ";
        }

        if (coef[degree])
            cout << coef[degree];
        cout << endl;
    }

    //다항식 a와 b를 더하는 함수
    void add(Polynomial a, Polynomial b)
    {
        if (a.degree > b.degree) //a항>b항
        {
            *this = a; //a 다항식을 자기 객체에 복사
            for (int i = 0; i <= b.degree; i++)
                coef[i + (degree - b.degree)] += b.coef[i];
        }

        else //a항<=b항
        {
            *this = b; //b다항식을 자신에 복사
            for (int i = 0; i <= a.degree; i++)
                coef[i + (degree - a.degree)] += a.coef[i];
        }
        trim();
    }

    //다항식 a에서 b를 빼는 함수
    void sub(Polynomial a, Polynomial b)
    {
        if (a.degree > b.degree) //a항>b항
        {
            *this = a; //a 다항식을 자기 객체에 복사
            for (int i = 0; i <= b.degree; i++)
                coef[i + (degree - b.degree)] -= b.coef[i];
        }

        else //a항<=b항
        {
            b.negate(); //부호를 다 바꾼다
            *this = b; //b다항식을 자신에 복사
            for (int i = 0; i <= a.degree; i++)
                coef[i + (degree - a.degree)] += a.coef[i];
        }
        trim();
    }

    //다항식 a와 b를 곱하는 함수
    void mult(Polynomial a, Polynomial b)
    {
        *this = a;
        int temp = degree; //기존 차수 저장
        degree += b.degree;
        int* temporary = new int[degree + 1]; //임시 배열
        for (int i = 0; i <= degree; i++)
            temporary[i] = 0; //초기화
        if (temp < b.degree)
        {
            for (int i = 0; i <= temp; i++) //자리 옮김
            {
                coef[i + b.degree] = coef[i];
                coef[i] = 0;
            }
        }

        else if (temp == b.degree)
        {
            for (int i = 0; i <= temp; i++)
            {
                coef[i + temp] = coef[i];
                if (i != temp)
                    coef[i] = 0;
            }
        }

        else
        {
            for (int i = 0; i <= temp; i++)
                temporary[i] = coef[i];

            for (int i = 0; i <= temp; i++)
            {
                coef[i + b.degree] = temporary[i];
                if (i < b.degree)
                    coef[i] = 0;
            }
            for (int i = 0; i <= degree; i++)

                temporary[i] = 0;

        }
        for (int i = 0; i <= temp; i++)
            for (int j = 0; j <= b.degree; j++)
                temporary[i + j] += coef[b.degree + i] * b.coef[j];//임시배열에 결과값 저장하고

        for (int i = 0; i <= temp; i++)
            for (int j = 0; j <= b.degree; j++)
                coef[i + j] = temporary[i + j]; //데이터를 옮긴다

        trim();

        delete[]temporary; //메모리 반환

    }

    bool isZero()
    {
        return degree == 0; //최고차수가 0인가?
    }

    void negate() //계수의 부호를 바꿈
    {
        for (int i = 0; i <= degree; i++)
            coef[i] = -coef[i];
    }

    void trim() //다항식의 속성값들을 변경
    {
        int count = 0;
        while (!coef[count]) //최고차항이 0이 아닐때까지
            count++;

        if (count) //최고차항이 0이 아니라면 실행 X
        {
            int temp = degree; //기존 차수 저장
            degree -= count; //최고차항을 감소시킨다
            for (int i = 0; i <= temp - count; i++) //자리를 옮긴다
                coef[i] = coef[i + count];
        }
    }
};

//다항식 클래스 테스트 프로그램
int main(void)
{
    Polynomial a, b, c;
    a.read();
    b.read();

    c.add(a, b); //c=a+b;
    a.display("A= ");
    b.display("B= ");
    c.display("덧셈= ");

    c.sub(a, b); //c=a-b;
    c.display("뺄셈= ");

    c.mult(a, b); //c=a*b;
    c.display("곱셈= ");

    return 0;
}