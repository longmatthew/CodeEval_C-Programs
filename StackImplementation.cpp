#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Stack
{
private:
	typedef struct Node
	{
		Node *pnext;
		int data;
		Node(int num) : data(num), pnext(NULL){}
	}NODE;

	NODE *pTop;
public:
	Stack()
	{
		pTop = NULL;
	}

	~Stack()
	{
		NODE *pTemp;

		while (pTop != NULL)
		{
			pTemp = pTop;
			pTop = pTop->pnext;

			delete pTemp;
		}
	}

	NODE* makeNode(int num)
	{
		NODE *pTemp = NULL;
		pTemp = new NODE(num);

		if (!pTemp)
		{
			cout << "Unable to create node" << endl;
			return NULL;
		}

		return pTemp;
	}

	void push(int num)
	{
		NODE *pTemp = makeNode(num);

		if (pTemp == NULL)
		{
			cout << "MEMORY ERROR" << endl;
		}

		pTemp->pnext = pTop;
		pTop = pTemp;
	}

	int pop(void)
	{
		int retint = 0;
		NODE *pTemp;

		pTemp = pTop;
		if (pTemp != NULL)
		{
			retint = pTemp->data;
			pTop = pTemp->pnext;
			delete pTemp;
		}

		return retint;
	}

	bool isempty()
	{
		return (pTop == NULL);
	}
};

int main(int argc, char *argv[])
{
	Stack *pStack = new Stack();
	ifstream infile;
	string line;

	infile.open(argv[1], ios::in);

	if (!infile.is_open())
	{
		cout << "Unable to open file" << endl;
		exit(1);
	}

	while (getline(infile, line))
	{
		int val;
		istringstream iss(line);

		while (iss >> val)
		{
			pStack->push(val);
		}

		while (!pStack->isempty())
		{
			val = pStack->pop();
			pStack->pop();
			cout << val << " ";
		}
		cout << endl;
	}
	
	return 0;
}
