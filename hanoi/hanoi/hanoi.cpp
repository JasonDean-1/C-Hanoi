#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

struct T
{
	int h;						//塔的高度 
	int x;						//塔的第一个盘的x坐标 ,y坐标等于(7+n-塔的高度h) 
	int l;						//塔的第一个盘的长度 	
}ta[3] = { { 10, 15, 2 }, { 0, 0, 0 }, { 0, 0, 0 } };

char  hnt[18][79] = {
	{ "                                                                              " },
	{ "                                 汉诺塔动画演示                               " },
	{ "                                                                              " },
	{ "  ╔════════════════════════════════════╗" },
	{ "  ║                                                                        ║" },
	{ "  ║                                                                        ║" },
	{ "  ║                                                                        ║" },
	{ "  ║           ▆                                                           ║" },
	{ "  ║          ▆▆                                                          ║" },
	{ "  ║         ▆▆▆                                                         ║" },
	{ "  ║        ▆▆▆▆                                                        ║" },
	{ "  ║       ▆▆▆▆▆                                                       ║" },
	{ "  ║      ▆▆▆▆▆▆                                                      ║" },
	{ "  ║     ▆▆▆▆▆▆▆                                                     ║" },
	{ "  ║    ▆▆▆▆▆▆▆▆                                                    ║" },
	{ "  ║   ▆▆▆▆▆▆▆▆▆                                                   ║" },
	{ "  ║  ▆▆▆▆▆▆▆▆▆▆                                                  ║" },
	{ "  ╚════════════════════════════════════╝" } };

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
	printf("\n\n   从%c塔移动一个盘到%c塔\n", ta_1 + 65, ta_3 + 65);
	printf("\n   步数:%d\n\n   ", sum);
	if (computerorpeople == 2)
		system("pause");
	else
	for (i = 0; i<200000 * speed; i++);
}
void hanoi(int ta_1, int ta_2, int ta_3, int m) //递归,ta_1/ta_2/ta_3分别为3座塔的代号，m为盘子数
{
	if (m == 1)
		move(ta_1, ta_3);						//如果盘子为1，将这个盘子从塔座A移动到塔座C
	else
	{
		hanoi(ta_1, ta_3, ta_2, m - 1);			//将塔座A的前m-1个盘子移到塔座B
		move(ta_1, ta_3);						//将塔座A的第m个盘子移到塔座C
		hanoi(ta_2, ta_1, ta_3, m - 1);			//将塔座B的m-1个盘子移到塔座C
	}
}

void main()
{
	int i;
	printf("请输入汉诺塔的高度（范围1->10）：");
	scanf("%d", &n);
	printf("请选择：输入1由电脑自动控制；\n");
	printf("        输入2由人控制。\n");
	printf("请输入：");
	scanf("%d", &computerorpeople);
	if (computerorpeople != 1 && computerorpeople != 2)
		computerorpeople = 1;
	if (computerorpeople == 1)
	{
		printf("请输入移动盘的速度(例如：输入1000则代表1秒)：");
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
