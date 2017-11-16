// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, 
// - ���������� ��������, 
// - �������� �������� �������� (��� ��������)
// - �������� �� �������, 
// - ��������� ���������� ��������� � �����
// - ������� �����
// ��� ������� � ������ ���� ������ �������������� ������

using namespace std;
// ������ �����

template <class T>
class Stack
{
protected: 
	T *pStack; //��������� �� ����
	int size;  //���������� ���������
	int top;   // ����� ��������
public:
	//������������
	Stack(int S = 10); 
	Stack(const Stack &S);
	
	~Stack(); // ����������
	
    //�������
	void push(const T &elem);// �������� ������� 
	T pop(); // ������� ������� � ������� 
	T &getTop() // �������� �������� ��������
	int getSize() // �������� ������ �����
	bool isEmpty(); //�������� �� �������
	Stack clear(); //�������
	 };
//���������� ������� 

template <class T> 
Stack<T>::Stack(int S) : size(S)// ������������� ���������?
{
	*pStack = new T[size]; // �������� ������ ��� ����
	top = 0; // ������������� �������� �������� �����
}
//......................................................................

template <class T>
Stack<T>::Stack(const Stack<T> &StackToCpy) :size(StackToCpy.getSize()) // ������������� ��������� 
{
	pStack = new T[size]; //�������� ������ ��� ����� ����
	top = StckToCpy.getTop();

	for (int i = 0; i < top; i++)
		pStack[i] = StckToCpy.pStack[i];
}
//......................................................................

template <class T>
Stack<T>::~Stack()
{
	delete[] stackPtr;
}
//......................................................................

template <class T>
void Stack<T>::push(const T &value)
{
	if (size - top >= 1)
		pStack[++top] = value;
	else
	{
		size = size + 5;
		T* TempStack = new T[size];
		for (int i = 0; i < top; i++)
			TempStack[i] = pStack[i];
		TempStack[++top] = value;
		delete[] pStack;
		pStack = Stack;
	}
	//......................................................................

	template <class T>
	T Stack<T>::Pop()
	{
		return pStack[top--];
	}
	//......................................................................

	template <class T>
	T& Stack<T>::getTop()
	{
		return pStack[top];
	}
	//......................................................................

	template <class T>
	int Stack<T>::getSize() const
	{
		return size;
	}
	template <class T>
	//......................................................................

	bool Stack<T>::isEmpty()
	{
		bool check
			if top < 0
				check = 1;
			else
				check = 0;
		return check;
	}
	//......................................................................
	template <class T>
	void Stack<T>::clear()
	{
		top = -1;
	}

  
}