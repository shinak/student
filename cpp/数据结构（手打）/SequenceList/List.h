#include <stdio.h>
#include <iostream.h>
//*********���Ա��˳��洢�ṹ*********//
#define DataType int
const int MaxListSize = 100;

class List{
private:
	DataType data[MaxListSize];
	int size;
public:
	List();
	~List();
	void Clear();
	bool IsEmpty();
	DataType GetElem(int i);
	int Locate(DataType e);
	DataType Prior(DataType e);
	DataType Next(DataType e);
	void Insert(DataType e, int i);
	DataType Delete(int i);
	int Length();
	void Print();
};
List::List()
{
	size = 0;
}
void List::Clear()
{
	size = 0;
}
bool List::IsEmpty()
{
	if (size != 0)
		return false;
	else
		return true;
}
DataType List::GetElem(int i)
{
	if (i<1 && i>size)
	{
		printf("��λ��û��ֵ!\n");
		return -1;
	}
	return data[i-1];
}
int List::Locate(DataType e)
{
	int i;
	if (size != 0)
	{
		for (i=0; i<size; i++ )
		{
			if(data[i] == e)
				return i+1;
		}
	}
	printf("û���ҵ���ֵ!\n");
	return 0;
}
DataType List::Prior(DataType e)
{
	int i;
	if (size != 0)
	{
		for (i=0; i<size; i++)
		{
			if(data[i] == e)
			{
				if(i != 0)
					return data[i-2];
				else
				{
					printf("������ǰ��!\n");
					return 0;
				}
			}
				 
		}
	}
	printf("û���ҵ���ֵ!\n");
	return 0;
}
DataType List::Next(DataType e)
{
	int i;
	if (size != 0)
	{
		for (i=0; i<size; i++)
		{
			if(data[i] == e)
			{
				if(i != size-1)
					return data[i];
				else
				{
					printf("�����޺��!\n");
					return 0;
				}
			}
				 
		}
	}
	printf("û���ҵ���ֵ!\n");
	return 0;
}

int List::Length ()
{
	return size;
}
void List::Print ()
{
	int i;
	if(size != 0)
	{
		for (i=0; i<size; i++)
			printf("%d",data[i]);
	}
	else
		printf("�ձ�\n");
}