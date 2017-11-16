// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память

using namespace std;
// Шаблон стека

template <class T>
class Stack
{
protected: 
	T *pStack; //указатель на стек
	int size;  //количество элементов
	int top;   // номер элемента
public:
	//конструкторы
	Stack(int S = 10); 
	Stack(const Stack &S);
	
	~Stack(); // деструктор
	
    //Функции
	void push(const T &elem);// вставить элемент 
	T pop(); // извлечь элемент с вершины 
	T &getTop() // Просмотр верхнего элемента
	int getSize() // получить размер стэка
	bool isEmpty(); //проверка на пустоту
	Stack clear(); //очистка
	 };
//Реализация методов 

template <class T> 
Stack<T>::Stack(int S) : size(S)// инициализация константы?
{
	*pStack = new T[size]; // выделяем память под стек
	top = 0; // инициализация текущего элемента нулем
}
//......................................................................

template <class T>
Stack<T>::Stack(const Stack<T> &StackToCpy) :size(StackToCpy.getSize()) // инициализация константы 
{
	pStack = new T[size]; //выделяем память под новый стек
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