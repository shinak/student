#define DataType int

const int MaxQueueSize = 50;

class Queue{
private:
	int front,rear;
	DataType QueueList[MaxQueueSize];
public:
	Queue();
	~Queue(){};
	void EnQueue(DataType item);  //���
	DataType DeQueue();  //����
	DataType GetFront();  //ȡ��ͷԪ��
	void ClearQueue();  //���
	bool IsEmpty();  //�ж϶��пշ�
	bool IsFull();  //�ж϶�������
	int Length();  //������е�Ԫ�ظ���
};
Queue::Queue()
{
	front = rear = 0;
}
void Queue::EnQueue(DataType item)
{
	if((rear+1)%MaxQueueSize == front)
	{
		cout<<"��������!"<<endl;
		return ;
	}
	else
	{
		QueueList[rear] = item; //QueueList��rearλ�ò���item
		rear = (rear+1)%MaxQueueSize;  //rear����ƶ�
	}
}
DataType Queue::DeQueue()
{
	DataType data;
	if(front == rear)
	{
		cout<<"����Ϊ��"<<endl;
		exit(0);
	}
	else
	{
		data = QueueList[front];
		front = (front+1)%MaxQueueSize;
		return data;
	}
}
DataType Queue::GetFront()
{
	return QueueList[front];
}

void Queue::ClearQueue()
{
	front = rear = 0;
}
bool Queue::IsEmpty()
{
	if(front == rear)
		return true;
	else
		return false;
}
bool Queue::IsFull()
{
	if((rear+1)%MaxQueueSize == front)
		return true;
	else
		return false;
}
int Queue::Length()
{
	int l;
	l = rear - front +1;
	return l;
}