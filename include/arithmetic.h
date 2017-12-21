// объявление функций и классов для вычисления арифметических выражений

#include <string>
#include "stack.h"




enum  LexemTypes { OPEN_BRACKET, CLOSE_BRACKET, OPERATOR, NUMBER, VARIABLE, UNKNOWN };

const string allOperators = "(-+*/)"; 

struct Lexem
{
	LexemTypes type; // тип лексемы
	double val; // числовое значение
	char OP; // символьное значение
	string CH = "0"; // сама лексема

	Lexem();// конструктор по умолчанию

	Lexem(const char c); // конструктор для символа c
	Lexem(const string& Num); // конструктор для числа
	Lexem(const Lexem &L);// конструктор копирования

	Lexem& operator=(const Lexem &L);
	void inpVar(); // ввод значения переменной
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
	void DeleteSpaces();
	void Minus();

	string getChar(int i) { return pLexem[i].CH; };
    string getPolishChar(int i) { return PolishN[i].CH; };
	string getExp() { return Str; };
	int getNLexemes() { return nLexemes; };

};