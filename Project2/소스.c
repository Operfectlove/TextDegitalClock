/*

2603 �輺��
�߰��������� ���� ���α׷��� ����

<������ �ð� ������Ʈ>
���� �ð��� ��ǥ �ٷ�� ��ũ���� ���� �ؽ�Ʈ�� �ܼ�â�� ��Ÿ��.
���� ���α׷����� �۵��ϵ��� ������ �ܺ� ���̺귯���� �ƴ� ��������� �̿��� �ð��� �ҷ��� �ۼ�.

*/

#define _CRT_SECURE_NO_WARNINGS //Warring ����

#include <stdio.h>
#include <time.h>
#include <windows.h>

void printTime(struct tm* t1);
void arrIn(char* clockDigits, int digit, int beginNumber);

void printTime(struct tm* t1)
{
	char clockDigits[5][33] = { 0, }; // �迭 ũ�� 

	arrIn(clockDigits, (t1->tm_hour / 10), 0); // �ð� 10�� �ڸ�
	arrIn(clockDigits, (t1->tm_hour % 10), 5); // �ð� 1�� �ڸ�
	arrIn(clockDigits, (t1->tm_min / 10), 12); // �� 10�� �ڸ�
	arrIn(clockDigits, (t1->tm_min % 10), 17); // �� 1�� �ڸ�
	arrIn(clockDigits, (t1->tm_sec / 10), 24); // �ð� 10�� �ڸ�
	arrIn(clockDigits, (t1->tm_sec % 10), 29); // �ð� 1�� �ڸ�

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 33; j++)
		{
			if (clockDigits[i][j] == 1)
				printf("��");

			else if ((i == 1 || i == 3) && (j == 10 || j == 22))
				printf("��");

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
		{	// 0�� ǥ��
		{1,1,1,1},
		{1,0,0,1},
		{1,0,0,1},
		{1,0,0,1},
		{1,1,1,1}
		},
		{	// 1�� ǥ��
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1}
		},
		{	// 2�� ǥ��
		{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1}
		},
		{	// 3�� ǥ��
		{1,1,1,1},
		{0,0,0,1},
		{0,1,1,1},
		{0,0,0,1},
		{1,1,1,1}
		},
		{	// 4�� ǥ��
		{1,0,0,1},
		{1,0,0,1},
		{1,1,1,1},
		{0,0,0,1},
		{0,0,0,1}
		},
		{	// 5�� ǥ��
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1}
		},
		{	// 6�� ǥ��
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1}
		},
		{	// 7�� ǥ��
		{1,1,1,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1}
		},
		{	// 8�� ǥ��
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1}
		},
		{	// 9�� ǥ��
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
	time_t curr;
	struct tm* curTime;

	do
	{
		time(&curr);
		curTime = localtime(&curr);

		printf("���α׷� ���� :  CTRL + C \n\n");

		printTime(curTime);
		Sleep(100);
		system("cls");

	} while (1);

	return 0;
}