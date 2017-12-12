// объявление функций и классов для вычисления арифметических выражений

#include <string>
#include "stack.h"

using namespace std;

enum  LexemTypes { OPEN_BRACKET, CLOSE_BRACKET, OPERATOR, NUMBER, UNKNOWN };

const string allOperators = "*/+-()"; 

struct Lexem
{
	LexemTypes type;
	double val;

	Lexem();// конструктор по умолчанию
	Lexem(const char c); // конструктор для символа c
	Lexem(const string& Num); // конструктор для числа
	Lexem(const Lexem &L);// конструктор копирования
	Lexem& operator=(const Lexem &L);
    ~Lexem() {};
};

class Arithmetic
{   
private:
	string Str; // строка-выражение 
	Lexem* pLexem; // массив лексем
	Lexem* PolishN; // массив лексем в обратной польской записи
	int nLexemes; 

	void DivideIntoLexemes(); // Разбиение строки на лексемы
	void PolishNotation(); // Перевод в в польскую запись
	double Calculate(); // вычисление по польской записи
public:
	Arithmetic(const string& str);
	~Arithmetic() { delete[] pLexem; }
    void Check(); //  проверка синтаксиса 
};