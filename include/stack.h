// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память

// Шаблон стека
const int MAX_STACK_SIZE = 1000;

template <class T>
class Stack
{
protected: 
	T *pStack; //указатель на стек
	int size;  //количество элементов
	int top;   // номер текущего элемента
public:
	//конструкторы
	Stack(int S = 10);  
	Stack(const Stack<T> &St);
	
	~Stack(); // деструктор
	
    //Функции
	void push(const T &elem);// вставить элемент 
	T pop(); // извлечь элемент с вершины 

	T getTop() const { return pStack[top]; }; // Просмотр верхнего элемента
	int getSize() const { return size; } ; // получить размер стэка
	int NumberTop(); // номер верхнего элемента

	bool isEmpty() const { return top == -1; }; //проверка на пустоту
	void clear(); //очистка стека 
	 };
//Реализация методов 

template <class T> 
Stack<T>::Stack(int S) 
{
	if ( (S>=0) && (S<= MAX_STACK_SIZE))
	{
		size = S;
		pStack = new T[size]; 
		top = -1; 
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
	pStack = new T[size]; //выделяем память под новый стек

	for (int i = 0; i < top+1; i++)
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
	if (top != size-1)
		pStack[++top] = value;
	else
	{
		if (size + (size+2)/2 <= MAX_STACK_SIZE) // если size = 0 получим 0+2/2 = 1 ; size = 1 -> 1+ (1+2)/2 = 2
		{
			size+=(size + 2) / 2;
			T* TempStack = new T[size];
			for (int i = 0; i < top+1; i++)
				TempStack[i] = pStack[i];
			TempStack[++top] = value;
			delete[] pStack;
			pStack = new T[size];
			for (int i = 0; i < top+1; i++)
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
			return pStack[top--];
	else
		throw "Error, Empty Stack";
    }

	//......................................................................

	template<class T>
	void Stack<T>::clear()
	{
		top = -1;
		for (int i = 0; i < size; i++)
			pStack[i] = 0;

	}
	template<class T>
	int Stack<T> ::NumberTop()
	{
		if (!IsEmpty())
			return pStack[top];
		else
			throw 0;
	}
	
	
	/*bool Stack<T>::operator==(const T &st) const
	{
		bool flag = false;
		if (size==st.size && top == st.top)
			for (int i=0; i<)
	}*/