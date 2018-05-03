#define DataType int

const int MaxQueueSize = 50;

class Queue{
private:
	int front,rear;
	DataType QueueList[MaxQueueSize];
public:
	Queue();
	~Queue(){};
	void EnQueue(DataType item);  //入队
	DataType DeQueue();  //出队
	DataType GetFront();  //取队头元素
	void ClearQueue();  //清空
	bool IsEmpty();  //判断队列空否
	bool IsFull();  //判断队列满否
	int Length();  //求队列中的元素个数
};
Queue::Queue()
{
	front = rear = 0;
}
void Queue::EnQueue(DataType item)
{
	if((rear+1)%MaxQueueSize == front)
	{
		cout<<"队列已满!"<<endl;
		return ;
	}
	else
	{
		QueueList[rear] = item; //QueueList在rear位置插入item
		rear = (rear+1)%MaxQueueSize;  //rear向后移动
	}
}
DataType Queue::DeQueue()
{
	DataType data;
	if(front == rear)
	{
		cout<<"队列为空"<<endl;
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