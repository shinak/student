// LinkList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkHeader.h"

int main(int argc, char* argv[])
{
	LinkList la;
	la.Create(5);
	la.Print();
    la.Seqence();
	la.Print();
	return 0;
}
