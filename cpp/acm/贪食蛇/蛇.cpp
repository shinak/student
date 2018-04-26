#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#define Key_Up 'w' // ���Ϸ���� ����
#define Key_Down 's' // ���·����
#define Key_Right 'd' // ���ҷ����
#define Key_Left 'a'  // �������
#define Key_Space ' '
#define R 1           //���ҵ�״̬�� 
#define L 2           //�����״̬�� 
#define U 3           //���ϵ�״̬�� 
#define D 4           //���µ�״̬�� 
typedef struct node
{
    int x;
    int y;
    struct node*next;
}snake;
//////////ȫ�ֱ��� 
int score=0;
int endgamestatus=0;
int food_x,food_y;
snake*head;//�ߵ�ͷ��� 
snake*p;//���������õ�ָ�� 
int status=R;//��״̬���� 
int key; 
/////////
void endgame();//�˳���Ϸ���� 
void Pos(int x,int y);//��궨λ���� 
void crosswall();//�ж����Ƿ�ײ��ǽ�� 
void Creat_Food();//����ʳ��
int  Bit_Self();//�ж���ͷ�Ƿ��������нӴ� 
void Crat_Map();//���ɵ�ͼ 
void Snake_Moving();//�����ƶ� 
void gamecircle();// ��Ϸѭ�� 
void pause();//��Ϸ��ͣ 
////////
void Pos(int x,int y)
{
    COORD pos;
    HANDLE hOutput;
    pos.X=x;
    pos.Y=y;
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput,pos);
}
int  Bit_Self()
{
    p=head->next;
    while(p)
    {
        if(p->x==head->x&&p->y==head->y)
        return 1;
        p=p->next;
    }
    return 0;
}
Creat_Map()
{
    int i,j;
    for(i=0;i<=54;i++)
    for(j=0;j<=26;j++)
    {
        Pos(i,0);
        printf("@");
        Pos(i,26);
        printf("@");
        Pos(0,j);
        printf("@");
        Pos(54,j);
        printf("@");
    }
}
void crosswall()
{
    if(head->x==0||head->y==0||head->x==54||head->y==26)
    {
    endgamestatus=1;
    endgame();
    }
}
void Creat_Food()
{
    srand(time(NULL));
    food_x=rand()%50+2;
    food_y=rand()%24+2;
    Pos(food_x,food_y);
    printf("@");
}
Init_Snake()
{
    int i;
    snake*tail;
    head=(snake*)malloc(sizeof(snake));
    head->x=25;
    head->y=5;
    head->next=NULL;
    for(i=1;i<4;i++)
    {
        tail=(snake*)malloc(sizeof(snake));
        tail->x=25+i*1;
        tail->y=5;
        tail->next=head;
        head=tail;
    }
    while(tail)
    {
        Pos(tail->x,tail->y);
        printf("@");
        tail=tail->next;
    }
}
 
void Snake_Moving()
{
    snake*newhead;
    newhead=(snake*)malloc(sizeof(snake));
    crosswall();
        if(Bit_Self())
    {
        endgamestatus=2;
        endgame();
    }
    if(status==R)//������ 
    {
        if(head->x==food_x&&head->y==food_y)
        {
            score=score+10;
            newhead->x=head->x+1;
            newhead->y=head->y;
            newhead->next=head;
            head=newhead;
            p=head;
            while(p)
            {
                Pos(p->x,p->y);
                printf("@");
                p=p->next;
            }
            Creat_Food();
        }
        else
        {
        newhead->x=head->x+1;
        newhead->y=head->y;
        newhead->next=head;
        head=newhead;
        p=head;
        while(p->next->next)
        {
            Pos(p->x,p->y);
            printf("@");
            p=p->next;
        }
        Pos(p->next->x,p->next-> y);
        printf(" ");
        free(p->next);
        p->next=NULL;
        }
    }
    if(status==L)
    {
            if(head->x==food_x&&head->y==food_y)
        {
            score=score+10;
            newhead->x=head->x-1;
            newhead->y=head->y;
            newhead->next=head;
            head=newhead;
            p=head;
            while(p)
            {
                Pos(p->x,p->y);
                printf("@");
                p=p->next;
            }
            Creat_Food();
        }
        else
        {
        newhead->x=head->x-1;
        newhead->y=head->y;
        newhead->next=head;
        head=newhead;
        p=head;
        while(p->next->next)
        {
            Pos(p->x,p->y);
            printf("@");
            p=p->next;
        }
        Pos(p->next->x,p->next-> y);
        printf(" ");
        free(p->next);
        p->next=NULL;
        }
    }
    if(status==D)
    {
        if(head->x==food_x&&head->y==food_y)
        {
            score=score+10;
            newhead->x=head->x+1;
            newhead->y=head->y;
            newhead->next=head;
            head=newhead;
            p=head;
            while(p)
            {
                Pos(p->x,p->y);
                printf("@");
                p=p->next;
            }
            Creat_Food();
        }
        else
        {
        newhead->x=head->x;
        newhead->y=head->y+1;
        newhead->next=head;
        head=newhead;
        p=head;
        while(p->next->next)
        {
            Pos(p->x,p->y);
            printf("@");
            p=p->next;
        }
        Pos(p->next->x,p->next-> y);
        printf(" ");
        free(p->next);
        p->next=NULL;
        }
    }
        if(status==U)
    {
        if(head->x==food_x&&head->y==food_y)
        {
            score=score+10;
            newhead->x=head->x;
            newhead->y=head->y-1;
            newhead->next=head;
            head=newhead;
            p=head;
            while(p)
            {
                Pos(p->x,p->y);
                printf("@");
                p=p->next;
            }
            Creat_Food();
        }
        else
        {
        newhead->x=head->x;
        newhead->y=head->y-1;
        newhead->next=head;
        head=newhead;
        p=head;
        while(p->next->next)
        {
            Pos(p->x,p->y);
            printf("@");
            p=p->next;
        }
        Pos(p->next->x,p->next-> y);
        printf(" ");
        free(p->next);
        p->next=NULL;
        }
    }
     
     
     
}
void gamecircle()
{
    Pos(57,4);
    printf("����˵��");
    Pos(57,5);
    printf("w a s d�ֱ��Ӧ�� �� �� �� ");
    Pos(57,6);
    printf("���ո����ͣ");   
    while(1)
    {   
        Pos(57,7);
    printf("��Ϸ����:%d",score);
        if(kbhit())
        key=getch();
        switch(key)
            {
                case Key_Right:
                    if(status!=L)   
                        status=R;
                    break;
                case Key_Left:
                    if(status!=R)
                        status=L;
                    break;
                case Key_Up:
                    if(status!=D)
                        status=U;
                    break;
                case Key_Down:
                    if(status!=U)
                        status=D;
                    break;
                case Key_Space:
                    pause();
                    break;
                default:
                break;
            }
        Sleep(300);
        Snake_Moving();
    }
}
void pause()
{   
    while(1)
    {
        if(key=getch()==' ')
        break;
     } 
}
void endgame()
{
    system("cls");
    Pos(27,13);
    if(endgamestatus==1)
    printf("��ײ��ǽ��");
    if(endgamestatus==2)
    printf("��ҧ�����Լ�");
    Pos(27,14);
    printf("���ĵ÷�Ϊ%d",score);
    exit(0);
}
void welcome()
{
    Pos(27,13);
    printf("��ӭ����̰������Ϸ");
    system("pause");
    system("cls");
    Pos(50,9);
    printf("��ӭ��Ҷ�Դ��������޸�");
    Pos(50,11);
    printf("���������������淨");
    Pos(50,12);
    system("pause");
    system("cls");
}
int main()
{
    welcome();
    Creat_Map();
    Creat_Food();
    Init_Snake();
    gamecircle();
    return 0;
}