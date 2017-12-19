// объявление функций и классов для вычисления арифметических выражений

#include <string>
#include "stack.h"

using namespace std;

enum  LexemTypes { OPEN_BRACKET, CLOSE_BRACKET, OPERATOR, NUMBER, VARIABLE, UNKNOWN };

const string allOperators = "(-+*/)"; 

struct Lexem
{
	LexemTypes type;
	double val;
	char OP;
	string CH;

	Lexem();// конструктор по умолчанию

	Lexem(const char c); // конструктор для символа c
	Lexem(const string& Num); // конструктор для числа
	Lexem(const Lexem &L);// конструктор копирования

	Lexem& operator=(const Lexem &L);
	void inpVar();
    ~Lexem() {};
};

class Arithmetic
{   
private:
	string Str; // строка-выражение 
	Lexem* pLexem; // массив лексем
	Lexem* PolishN; // массив лексем в обратной польской записи
	int nLexemes;
	int NumPolish;

public:
	Arithmetic(const string& str);
	~Arithmetic() { delete[] pLexem; }
   
	void DivideIntoLexemes(); // Разбиение строки на лексемы
	void PolishNotation(); // Перевод в в польскую запись
	double Calculate(); // вычисление по польской записи

	bool CheckBrackets();
	bool CheckSymbols();
	bool CheckOperators();
	bool CheckPoints();
	void DeleteSpaces();
	void Minus();

	string getChar(int i) { return pLexem[i].CH; };
	int getNLexemes() { return nLexemes; };

};