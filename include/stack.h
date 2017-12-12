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
const int MAX_STACK_SIZE = 1000;

template <class T>
class Stack
{
protected: 
	T *pStack; //��������� �� ����
	int size;  //���������� ���������
	int top;   // ����� �������� ��������
public:
	//������������
	Stack(int S = 10); 
	Stack(const Stack<T> &St);
	
	~Stack(); // ����������
	
    //�������
	void push(const T &elem);// �������� ������� 
	T pop(); // ������� ������� � ������� 
	T getTop() const { return pStack[top - 1]; }; // �������� �������� ��������
	int getSize() const { return size; } ; // �������� ������ �����
	bool isEmpty() { return top == 0; }; //�������� �� �������
	void clear(); //�������
	 };
//���������� ������� 

template <class T> 
Stack<T>::Stack(int S) 
{
	if ( (S>=0) && (S<= MAX_STACK_SIZE))
	{
		size = S;
		pStack = new T[size]; 
		top = 0; 
	}
	else 
		throw "Wrong Size";
}
//......................................................................

template <class T>
Stack<T>::Stack(const Stack<T> &St) 
{
	size = St.size;
	top = St.top;
	pStack = new T[size]; //�������� ������ ��� ����� ����

	for (int i = 0; i < top; i++)
		pStack[i] = St.pStack[i];
}
//......................................................................

template <class T>
Stack<T>::~Stack()
{
	delete[] pStack;
}
//......................................................................

template <class T>
void Stack<T>::push(const T &value)
{
	if (top<size)
		pStack[top++] = value;
	else
	{
		if (size + (size+2)/2 <= MAX_STACK_SIZE) // ���� size = 0 ������� 0+2/2 = 1 ; size = 1 -> 1+ (1+2)/2 = 2
		{
			size+=(size + 2) / 2;
			T* TempStack = new T[size];
			for (int i = 0; i < top; i++)
				TempStack[i] = pStack[i];
			TempStack[top++] = value;
			delete[] pStack;
			pStack = new T[size];
			for (int i = 0; i < top; i++)
				pStack[i] = TempStack[i];
			delete[] TempStack;
		}
		else
			throw "ErrorMaxSize";
	}
}
	//......................................................................

	template <class T>
	T Stack<T>::pop()
	{   if (!isEmpty())
			return pStack[--top];
	else
		throw "Error, Empty Stack";
    }

	//......................................................................

	template<class T>
	void Stack<T>::clear()
	{
		top = 0;
		for (int i = 0; i < size; i++)
			pStack[i] = 0;

	}