// CircularStudent.h 헤더 파일을 include합니다.
#include "CircularStudent.h"

int main(void)
{
    CircularStudent male, female; // 남성과 여성 CircularStudent 객체를 선언합니다.
    char name[20];
    char gender; // 성별을 저장할 문자형 변수를 선언합니다.

    cout << "미팅 주선 프로그램입니다" << endl; // 미팅 주선 프로그램을 알리는 메시지를 출력합니다.
    cout << "프로그램 종료 원하시면 이름에 '그만'을 입력해주세요" << endl << endl; // 프로그램 종료 방법을 설명하는 메시지를 출력합니다.

    while (1) // 무한 루프를 시작합니다.
    {
        cout << "고객이름: "; // 이름을 입력받는 메시지를 출력합니다.
        cin >> name; // 이름을 입력받습니다.

        if (!strcmp(name, "그만")) // 이름이 '그만'일 경우 루프를 탈출합니다.
            break;

        cout << "성별을 입력하세요(f or m) "; // 성별을 입력받는 메시지를 출력합니다.
        cin >> gender; // 성별을 입력받습니다.

        if (gender == 'm') // 남성인 경우 male 객체에 이름을 추가합니다.
            male.enqueue(name);

        else if (gender == 'f') // 여성인 경우 female 객체에 이름을 추가합니다.
            female.enqueue(name);

        if (!male.isEmpty() && !female.isEmpty()) // male과 female 객체가 모두 비어있지 않은 경우
        {
            char boyfriend[20], girlfriend[20]; // 커플 이름을 저장할 문자열 배열을 선언합니다.
            strcpy(boyfriend, male.dequeue()); // male 객체에서 이름을 가져와 boyfriend 배열에 복사합니다.
            strcpy(girlfriend, female.dequeue()); // female 객체에서 이름을 가져와 girlfriend 배열에 복사합니다.
            cout << "커플이 탄생했습니다! " << boyfriend << "와 " << girlfriend << endl << endl; // 커플이 탄생했다는 메시지와 커플 이름을 출력합니다.
        }

        else
            cout << "아직 대상자가 없습니다. 기다려주십시요." << endl << endl; // 커플을 만들 수 없는 상태라는 메시지를 출력합니다.
    }
    return 0; // 프로그램을 종료합니다.
}