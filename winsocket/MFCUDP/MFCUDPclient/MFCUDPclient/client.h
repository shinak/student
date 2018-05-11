
class client
{
public:
	int i;//客户端顺序
	SOCKET soc;//套接字
	struct sockaddr_in ca;//客服端地址
	client(void);
	~client(void);
};
