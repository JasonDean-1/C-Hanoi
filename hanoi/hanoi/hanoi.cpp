#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

struct T
{
	int h;						//���ĸ߶� 
	int x;						//���ĵ�һ���̵�x���� ,y�������(7+n-���ĸ߶�h) 
	int l;						//���ĵ�һ���̵ĳ��� 	
}ta[3] = { { 10, 15, 2 }, { 0, 0, 0 }, { 0, 0, 0 } };

char  hnt[18][79] = {
	{ "                                                                              " },
	{ "                                 ��ŵ��������ʾ                               " },
	{ "                                                                              " },
	{ "  �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" },
	{ "  �U                                                                        �U" },
	{ "  �U                                                                        �U" },
	{ "  �U                                                                        �U" },
	{ "  �U           �}                                                           �U" },
	{ "  �U          �}�}                                                          �U" },
	{ "  �U         �}�}�}                                                         �U" },
	{ "  �U        �}�}�}�}                                                        �U" },
	{ "  �U       �}�}�}�}�}                                                       �U" },
	{ "  �U      �}�}�}�}�}�}                                                      �U" },
	{ "  �U     �}�}�}�}�}�}�}                                                     �U" },
	{ "  �U    �}�}�}�}�}�}�}�}                                                    �U" },
	{ "  �U   �}�}�}�}�}�}�}�}�}                                                   �U" },
	{ "  �U  �}�}�}�}�}�}�}�}�}�}                                                  �U" },
	{ "  �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" } };

int n;
int sum = 0;
int computerorpeople = 1;
int speed = 0;
void count_ta_1(int ta_1)
{
	int i;
	int j;
	int k = 0;
	for (i = 7; i<7 + n; i++)
	for (j = 4 + ta_1 * 24; j<28 + ta_1 * 24; j++)
	{
		if (hnt[i][j] != ' ')
		{
			for (; hnt[i][j + k] != ' '; k++);
			ta[ta_1].x = j;
			ta[ta_1].l = k;
			return;
		}
	}
}
void move(int ta_1, int ta_3)
{
	int i;
	sum++;
	ta[ta_3].h++;
	ta[ta_3].x = ta[ta_1].x + (ta_3 - ta_1) * 24;
	ta[ta_3].l = ta[ta_1].l;
	for (i = 0; i<ta[ta_1].l; i++)
	{
		hnt[7 + n - ta[ta_3].h][ta[ta_3].x + i] = hnt[7 + n - ta[ta_1].h][ta[ta_1].x + i];
		hnt[7 + n - ta[ta_1].h][ta[ta_1].x + i] = ' ';
	}
	ta[ta_1].h--;
	count_ta_1(ta_1);
	system("cls");
	for (i = 0; i<7 + n; i++)
		printf("%s\n", hnt[i]);
	printf("%s", hnt[17]);
	printf("\n\n   ��%c���ƶ�һ���̵�%c��\n", ta_1 + 65, ta_3 + 65);
	printf("\n   ����:%d\n\n   ", sum);
	if (computerorpeople == 2)
		system("pause");
	else
	for (i = 0; i<200000 * speed; i++);
}
void hanoi(int ta_1, int ta_2, int ta_3, int m) //�ݹ�,ta_1/ta_2/ta_3�ֱ�Ϊ3�����Ĵ��ţ�mΪ������
{
	if (m == 1)
		move(ta_1, ta_3);						//�������Ϊ1����������Ӵ�����A�ƶ�������C
	else
	{
		hanoi(ta_1, ta_3, ta_2, m - 1);			//������A��ǰm-1�������Ƶ�����B
		move(ta_1, ta_3);						//������A�ĵ�m�������Ƶ�����C
		hanoi(ta_2, ta_1, ta_3, m - 1);			//������B��m-1�������Ƶ�����C
	}
}

void main()
{
	int i;
	printf("�����뺺ŵ���ĸ߶ȣ���Χ1->10����");
	scanf("%d", &n);
	printf("��ѡ������1�ɵ����Զ����ƣ�\n");
	printf("        ����2���˿��ơ�\n");
	printf("�����룺");
	scanf("%d", &computerorpeople);
	if (computerorpeople != 1 && computerorpeople != 2)
		computerorpeople = 1;
	if (computerorpeople == 1)
	{
		printf("�������ƶ��̵��ٶ�(���磺����1000�����1��)��");
		scanf("%d", &speed);
	}
	if (n<1 || n>10)
		n = 10;
	ta[0].h = n;
	system("cls");
	for (i = 0; i<7 + n; i++)
		printf("%s\n", hnt[i]);
	printf("%s\n\n   ", hnt[17]);
	system("pause");
	hanoi(0, 1, 2, n);
	if (computerorpeople == 1)
		system("pause");
}
