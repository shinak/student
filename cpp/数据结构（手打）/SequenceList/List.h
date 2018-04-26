#include <stdio.h>
#include <iostream.h>
//*********线性表的顺序存储结构*********//
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
		printf("该位置没有值!\n");
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
	printf("没有找到该值!\n");
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
					printf("该数无前驱!\n");
					return 0;
				}
			}
				 
		}
	}
	printf("没有找到该值!\n");
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
					printf("该数无后继!\n");
					return 0;
				}
			}
				 
		}
	}
	printf("没有找到该值!\n");
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
		printf("空表\n");
}