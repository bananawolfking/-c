#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void meun()
{
	printf("******************************\n");
	printf("*******    1:play    *********\n");
	printf("*******    0:exit    *********\n");
	printf("******************************\n");
	printf("请输入：\n");
}

void game()
{
	char mine[ROWS][LEFS] = { 0 };
	char out[ROWS][LEFS] = { 0 };
	initialize(mine, ROWS, LEFS, '0');//初始化
	initialize(out, ROWS, LEFS, '#');
	//print(mine, ROW, LEF);
	print(out, ROW, LEF);
	Lay_mines(mine, ROW, LEF, Easy_Count);//埋雷
	//print(mine, ROW, LEF);
	Find_mines(mine, out, ROW, LEF, Easy_Count);//扫雷
}


void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		
		meun();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入格式错误，请重新输入！\n");
			break;
		}
	} while (input);


}




int main()
{
	test();
	return 0;
}