/*

2603 김성윤
추가교육과정 자율 프로그래밍 과제

<디지털 시계 프로젝트>
현재 시간을 좌표 다루는 테크닉을 통해 텍스트로 콘솔창에 나타냄.
단일 프로그램으로 작동하도록 서버나 외부 라이브러리가 아닌 헤더파일을 이용해 시간을 불러와 작성.

*/

#define _CRT_SECURE_NO_WARNINGS //Warring 방지

#include <stdio.h>
#include <time.h>
#include <windows.h>

void printTime(struct tm* t1);
void arrIn(char* clockDigits, int digit, int beginNumber);

void printTime(struct tm* t1)
{
	char clockDigits[5][33] = { 0, }; // 배열 크기 

	arrIn(clockDigits, (t1->tm_hour / 10), 0); // 시간 10의 자리
	arrIn(clockDigits, (t1->tm_hour % 10), 5); // 시간 1의 자리
	arrIn(clockDigits, (t1->tm_min / 10), 12); // 분 10의 자리
	arrIn(clockDigits, (t1->tm_min % 10), 17); // 분 1의 자리
	arrIn(clockDigits, (t1->tm_sec / 10), 24); // 시간 10의 자리
	arrIn(clockDigits, (t1->tm_sec % 10), 29); // 시간 1의 자리

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 33; j++)
		{
			if (clockDigits[i][j] == 1)
				printf("■");

			else if ((i == 1 || i == 3) && (j == 10 || j == 22))
				printf("■");

			else
				printf("  ");
		}
		printf("\n");
	}
}

void arrIn(char clockDigits[][33], int digit, int beginNumber)
{
	char numDigits[10][5][4] =
	{
		{	// 0을 표시
		{1,1,1,1},
		{1,0,0,1},
		{1,0,0,1},
		{1,0,0,1},
		{1,1,1,1}
		},
		{	// 1을 표시
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1}
		},
		{	// 2를 표시
		{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1}
		},
		{	// 3을 표시
		{1,1,1,1},
		{0,0,0,1},
		{0,1,1,1},
		{0,0,0,1},
		{1,1,1,1}
		},
		{	// 4를 표시
		{1,0,0,1},
		{1,0,0,1},
		{1,1,1,1},
		{0,0,0,1},
		{0,0,0,1}
		},
		{	// 5을 표시
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1}
		},
		{	// 6을 표시
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1}
		},
		{	// 7을 표시
		{1,1,1,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1}
		},
		{	// 8을 표시
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1}
		},
		{	// 9를 표시
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1}
		}
	};

	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = beginNumber; j < beginNumber + 4; j++)
		{
			clockDigits[i][j] = numDigits[digit][i][cnt];
			cnt++;
		}
		cnt = 0;
	}
}

int main(void)
{
	int yn;
	printf("시간을 출력할까요?(Yes : 1 / NO : 0)");
	scnaf_s("%d", &yn); // 비주얼스튜디오에서 실행 
	//scnaf("%d", &yn); // 다른 IDE에서 실행
	
	if(yn == 0)
		return 0;
	
	time_t curr;
	struct tm* curTime;

	do
	{
		time(&curr);
		curTime = localtime(&curr);

		printf("프로그램 종료 :  CTRL + C \n\n");

		printTime(curTime);
		Sleep(100);
		system("cls");

	} while (1);

	return 0;
}
