#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


void game()
{
	
	
	char chessboard[ROW][LEF] = { 0 };
	initialize(chessboard, ROW, LEF);
	int ret = 0;//决定棋盘下面该怎么走
	int n = 0;
	int m = 0;
	int chi = 0;//控制棋盘翻转的关键字
	while (1)
	{
		n++;
		chi = changechess(chessboard, ROW, LEF, n, ret, m, chi);//控制翻转回来棋盘
		n--;
		print_chessboard(chessboard, ROW, LEF);//打印棋盘
		if (m > 2)
		{
			if ('A' == judgment(chessboard, ROW, LEF))//判断
			{

				printf("恭喜你获胜了,厉害啊\n");
				break;
			}
			else if ('B' == judgment(chessboard, ROW, LEF))
			{

				printf("不会吧，这么菜\n");
				break;
			}
			else if ('D' == judgment(chessboard, ROW, LEF))
			{

				printf("棋逢对手，可以可以\n");
				break;
			}
		}
		playgame(chessboard, ROW, LEF);//玩家下棋
		n++;
		print_chessboard(chessboard, ROW, LEF);//打印棋盘
		if (n > 2)
		{
			if ('A' == judgment(chessboard, ROW, LEF))//判断
			{
				
				printf("恭喜你获胜了,厉害啊\n");
				break;
			}
			else if ('B' == judgment(chessboard, ROW, LEF))
			{
				
				printf("不会吧，这么菜\n");
				break;
			}
			else if ('D' == judgment(chessboard, ROW, LEF))
			{
				
				printf("棋逢对手，可以可以\n");
				break;
			}
			else
			{
				printf("加油！\n");
			}
		}
		chi = changechess(chessboard, ROW, LEF ,  n,  ret,  m,  chi);//控制翻转棋盘
		//print_chessboard(chessboard, ROW, LEF);//打印棋盘
		Sleep(1000);
		//computergame(chessboard, ROW, LEF);//电脑下棋
		ret = computergameend(chessboard, ROW, LEF, n, ret, m);
		//print_chessboard(chessboard, ROW, LEF);//打印棋盘
		m++;
		
	}

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		
		meun(1);//开始界面
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入");
			break;
		}
	} while (input);
	return 0;
}