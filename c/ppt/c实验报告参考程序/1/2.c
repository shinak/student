#include<stdio.h>
#define PI 3.14
int main()
{
	float r,h,length,area_yuan,area_qiu,v_qiu,v_yuanzhu;
	scanf("%f%f",&r,&h);
	length=2*PI*r;
	area_yuan=PI*r*r;
	area_qiu=6*PI*r*r;
	v_qiu=4.0/3*PI*r*r*r;
	v_yuanzhu=area_yuan*h;
	printf("Բ�ܳ�Ϊ��%.2f\n",length);
	printf("Բ���Ϊ��%.2f\n",area_yuan);
	printf("Բ�����Ϊ��%.2f\n",area_qiu);
	printf("Բ�����Ϊ��%.2f\n",v_qiu);
	printf("Բ�����Ϊ��%.2f\n",v_yuanzhu);
	return 0;
}