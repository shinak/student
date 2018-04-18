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
	SNAKE(){Sx=220;Sy=240;Scount=1;}    //��ʼ���ߵ�λ�ó���
	int getSx() const {return Sx;}   //��ȡ�ߵ�x����
	int getSy() const {return Sy;}   //��ȡ�ߵ�y����
	int getScount() const {return Scount;}   //��ȡ�ߵĳ���
	void setSxSy(int x,int y);   //��ͷ��λ��
	int setScount();   //�Ե�ʳ��+1����
	void head();   //������ͷ
	void deltail();   //�����ۼ�
private:
	int Sx;   //�ߵ�x����
	int Sy;   //�ߵ�y����
	int Scount;   //�ߵĳ���
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


int* food(SNAKE snake[421]);    //ʳ��λ��
bool eat(int *p,SNAKE snake);    //�Ե�ʳ��
SNAKE* up(SNAKE snake[421]);   //��    ������ͷ��λ�����λ�ã���ͬ
SNAKE* down(SNAKE snake[421]);   //��
SNAKE* left(SNAKE snake[421]);   //��
SNAKE* right(SNAKE snake[421]);   //��
int crash(SNAKE snake[421]);   //��ײ���


int main()
{   
	
	srand(time(NULL));
	initgraph(640,480);   // ������ͼ���ڣ���СΪ 640x480 ����
	
	settextstyle(20,10, _T("���Ĳ���"));
	char s[] = "̰ʳ��1.0";
	outtextxy(200, 0, s);
	
	/*********************************************************************************
	int xt=20,yt=40;
	while(yt != 440)
	{
	yt+=20;
	xt+=20;
	line(20,yt,440,yt);
	line(xt,40,xt,440);
	}  //���Ը���
	*********************************************************************************/


	while(1)
	{
		int ch = 1;
		settextstyle(20,0, _T("����"));
		outtextxy(200,100, _T("��ʼ��Ϸ-(1)"));
		outtextxy(200,200, _T("�˳�-(0)"));
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

					SNAKE *snake_t = new SNAKE[421];   //�ߵ�λ�ñ��
					snake_t[0].head();
					int *f ;
					f = food(snake_t);   //��ʼ��ʳ��λ��
					int ch1=224;
					int ch2=72;
					int ch3=0;
					while (ch1 == 224)   //�������  kbhit()
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
								 }break;   //��
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
								 }break;   //��
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
								 }break;   //��
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
								 }break;   //��                            
						}       //
						
						if((ch1 = crash(snake_t)) == 224)   //�Ѷ�
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
					settextstyle(20,0, _T("����"));
					outtextxy(200,100, _T("���¿�ʼ-(1)"));
					outtextxy(200,200, _T("�˳�-(0)"));
					ch = getch();

				}   //��ʼ��Ϸ
			
		}
		closegraph();
	}



	return 0;
}


int* food(SNAKE snake[421])   //ʳ��(ʳ�ﲻ�������ص�����Խ��)
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

bool eat(int *p,SNAKE snake)    //�Ե�ʳ��
{
	if(*p == snake.getSx() && *(++p) == snake.getSy())
		return true;
	else
		return false;
}


SNAKE* up(SNAKE snake[421])   //��   
{
	
	snake[420] = snake[snake[0].getScount()-1];   //��¼��β
	
	
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

SNAKE* down(SNAKE snake[421])   //��
{
	snake[420] = snake[snake[0].getScount()-1];   //��¼��β
	
	
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
SNAKE* left(SNAKE snake[421])   //��
{
	snake[420] = snake[snake[0].getScount()-1];   //��¼��β
	
	
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
SNAKE* right(SNAKE snake[421])   //��
{
	snake[420] = snake[snake[0].getScount()-1];   //��¼��β
	
	
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
		settextstyle(20,10, _T("���Ĳ���"));
		char s[] = "game over";
		outtextxy(160, 240, s);
		return 1;
	}
	return 224;
}