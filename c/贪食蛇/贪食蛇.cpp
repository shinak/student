#include <iostream>
using namespace std;
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>
#include <windows.h>

class SNAKE
{
public:
	SNAKE(){Sx=220;Sy=240;Scount=1;}    //初始化蛇的位置长度
	int getSx() const {return Sx;}   //获取蛇的x坐标
	int getSy() const {return Sy;}   //获取蛇的y坐标
	int getScount() const {return Scount;}   //获取蛇的长度
	void setSxSy(int x,int y);   //蛇头的位置
	int setScount();   //吃到食物+1长度
	void head();   //绘制蛇头
	void deltail();   //擦除痕迹
private:
	int Sx;   //蛇的x坐标
	int Sy;   //蛇的y坐标
	int Scount;   //蛇的长度
};
void SNAKE::setSxSy(int x,int y)
{
	Sx += x;
	Sy += y;
}
int SNAKE::setScount()
{
	return Scount++;
}
void SNAKE::head()
{
	setfillcolor(WHITE);
	solidrectangle(Sx,Sy,Sx+20,Sy+20);
}
void SNAKE::deltail()
{
	clearrectangle(Sx,Sy,Sx+20,Sy+20);
	if(Sx == 20 || Sy == 40 || Sx == 420 || Sy == 420)
	{
		setlinecolor(WHITE);
		rectangle(20,40,440,440);
	}
}


int* food(SNAKE snake[421]);    //食物位置
bool eat(int *p,SNAKE snake);    //吃到食物
SNAKE* up(SNAKE snake[421]);   //上    返回蛇头新位置与旧位置，下同
SNAKE* down(SNAKE snake[421]);   //下
SNAKE* left(SNAKE snake[421]);   //左
SNAKE* right(SNAKE snake[421]);   //右
int crash(SNAKE snake[421]);   //碰撞检测


int main()
{   
	
	srand(time(NULL));
	initgraph(640,480);   // 创建绘图窗口，大小为 640x480 像素
	
	settextstyle(20,10, _T("华文彩云"));
	char s[] = "贪食蛇1.0";
	outtextxy(200, 0, s);
	
	/*********************************************************************************
	int xt=20,yt=40;
	while(yt != 440)
	{
	yt+=20;
	xt+=20;
	line(20,yt,440,yt);
	line(xt,40,xt,440);
	}  //测试格子
	*********************************************************************************/


	while(1)
	{
		int ch = 1;
		settextstyle(20,0, _T("黑体"));
		outtextxy(200,100, _T("开始游戏-(1)"));
		outtextxy(200,200, _T("退出-(0)"));
		ch = getch();
		
		while( ch != 48)    //48 = '0'
		{
			
			if(ch == 49)
				{
					clearrectangle(10,20,460,460);
					//////////////////////////////////////////////////////////////////////////////////
					setlinestyle(PS_SOLID, 3);
					setlinecolor(WHITE);
					rectangle(20,40,440,440);

					SNAKE *snake_t = new SNAKE[421];   //蛇的位置标记
					snake_t[0].head();
					int *f ;
					f = food(snake_t);   //初始化食物位置
					int ch1=224;
					int ch2=72;
					int ch3=0;
					while (ch1 == 224)   //方向控制  kbhit()
					{
						if(snake_t[0].getScount() > 1)
							ch3=ch2;
						if(kbhit())
						{
							if (ch1=getch())
								ch2=getch();  
						}	
						if((ch3 == 72 && ch2 == 80) || (ch3 == 80 && ch2 == 72) || (ch3 == 75 && ch2 == 77) || (ch3 == 77 && ch2 == 75))
							ch2=ch3;
						switch (ch2)   
						{
						case 72: {
							
							snake_t = up(snake_t);
							if(!eat(f,snake_t[0]))
							{
								snake_t[420].deltail();
							}
							if(eat(f,snake_t[0]))
							{
								snake_t[snake_t[0].getScount()] = snake_t[420];
								snake_t[0].setScount();
								f=food(snake_t);
							}
								 }break;   //上
						case 80: {
							snake_t = down(snake_t);
							if(!eat(f,snake_t[0]))
							{
								snake_t[420].deltail();
							}
							if(eat(f,snake_t[0]))
							{
								snake_t[snake_t[0].getScount()] = snake_t[420];
								snake_t[0].setScount();
								f=food(snake_t);
							}
								 }break;   //下
						case 75: {
							snake_t = left(snake_t);
							if(!eat(f,snake_t[0]))
							{
								snake_t[420].deltail();
							}
							if(eat(f,snake_t[0]))
							{
								snake_t[snake_t[0].getScount()] = snake_t[420];
								snake_t[0].setScount();
								f=food(snake_t);
							}
								 }break;   //左
						case 77: {
							snake_t = right(snake_t);
							if(!eat(f,snake_t[0]))
							{
								snake_t[420].deltail();
							}
							if(eat(f,snake_t[0]))
							{
								snake_t[snake_t[0].getScount()] = snake_t[420];
								snake_t[0].setScount();
								f=food(snake_t);
							}
								 }break;   //右                            
						}       //
						
						if((ch1 = crash(snake_t)) == 224)   //难度
						{
							if(snake_t[0].getScount() < 10)
								Sleep(400);
							else if(snake_t[0].getScount() < 10*2)
								Sleep(300);
							else if(snake_t[0].getScount() < 30*3)
								Sleep(200);
							else if(snake_t[0].getScount() < 40*4)
								Sleep(100);
							else if(snake_t[0].getScount() < 70*5)
								Sleep(50);	
						}
					}
					delete[] snake_t;
					////////////////////////////////////////////////////////////////////////////////

					Sleep(1000);
					clearrectangle(10,20,460,460);
					settextstyle(20,0, _T("黑体"));
					outtextxy(200,100, _T("重新开始-(1)"));
					outtextxy(200,200, _T("退出-(0)"));
					ch = getch();

				}   //开始游戏
			
		}
		closegraph();
	}



	return 0;
}


int* food(SNAKE snake[421])   //食物(食物不与蛇身重叠、不越界)
{
	srand(time(NULL));
	int *fxy = new int[2];
	fxy[0] = fxy[1] = 0;
	while(fxy[0] == 0 && fxy[1] == 0)
	{
		fxy[0] = 20 + 20 * (rand()%21);
		fxy[1] = 40 + 20 * (rand()%20);
		setfillcolor(YELLOW);
		solidrectangle(fxy[0],fxy[1],fxy[0]+20,fxy[1]+20);
		for(int i=0; i < snake[0].getScount(); i++)
		{
			if(fxy[0] == snake[i].getSx() && fxy[1] == snake[i].getSy())
				fxy[0] = fxy[1] = 0;
		}
	}
	return fxy;
	
}

bool eat(int *p,SNAKE snake)    //吃到食物
{
	if(*p == snake.getSx() && *(++p) == snake.getSy())
		return true;
	else
		return false;
}


SNAKE* up(SNAKE snake[421])   //上   
{
	
	snake[420] = snake[snake[0].getScount()-1];   //记录蛇尾
	
	
	for(int i=snake[0].getScount();i > 1 ;i--)
	{
		SNAKE t;
		t = snake[i-2];
		snake[i-1] = t;
	}
	
	int x=0,y=0;
	x = x;
	y = y - 20;
	snake[0].setSxSy(x,y);
	snake[0].head();
	return snake;
}

SNAKE* down(SNAKE snake[421])   //下
{
	snake[420] = snake[snake[0].getScount()-1];   //记录蛇尾
	
	
	for(int i=snake[0].getScount();i > 1 ;i--)
	{
		SNAKE t;
		t = snake[i-2];
		snake[i-1] = t;
	}
	
	int x=0,y=0;
	x = x;
	y = y + 20;
	snake[0].setSxSy(x,y);
	snake[0].head();
	return snake;
}
SNAKE* left(SNAKE snake[421])   //左
{
	snake[420] = snake[snake[0].getScount()-1];   //记录蛇尾
	
	
	for(int i=snake[0].getScount();i > 1 ;i--)
	{
		SNAKE t;
		t = snake[i-2];
		snake[i-1] = t;
	}
	
	int x=0,y=0;
	x = x - 20;
	y = y;
	snake[0].setSxSy(x,y);
	snake[0].head();
	
	
	return snake;
}
SNAKE* right(SNAKE snake[421])   //右
{
	snake[420] = snake[snake[0].getScount()-1];   //记录蛇尾
	
	
	for(int i=snake[0].getScount();i > 1 ;i--)
	{
		SNAKE t;
		t = snake[i-2];
		snake[i-1] = t;
	}
	
	int x=0,y=0;
	x = x + 20;
	y = y;
	snake[0].setSxSy(x,y);
	snake[0].head();
	
	return snake;
}



int crash(SNAKE snake[421])
{
	int t = 0;
	if(snake[0].getSx() < 20 || snake[0].getSy() < 40 || snake[0].getSx() > 420 || snake[0].getSy() > 420 )
		t = 1;
	
	for(int i=1; i < snake[0].getScount(); i++)
	{
		
		if(snake[0].getSx() == snake[i].getSx() && snake[0].getSy() == snake[i].getSy())
			t = 1;
	}
	
	if(t == 1)
	{
		clearrectangle(0,200,640,300);
		settextstyle(20,10, _T("华文彩云"));
		char s[] = "game over";
		outtextxy(160, 240, s);
		return 1;
	}
	return 224;
}