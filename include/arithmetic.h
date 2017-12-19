// ���������� ������� � ������� ��� ���������� �������������� ���������

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

	Lexem();// ����������� �� ���������

	Lexem(const char c); // ����������� ��� ������� c
	Lexem(const string& Num); // ����������� ��� �����
	Lexem(const Lexem &L);// ����������� �����������

	Lexem& operator=(const Lexem &L);
	void inpVar();
    ~Lexem() {};
};

class Arithmetic
{   
private:
	string Str; // ������-��������� 
	Lexem* pLexem; // ������ ������
	Lexem* PolishN; // ������ ������ � �������� �������� ������
	int nLexemes;
	int NumPolish;

public:
	Arithmetic(const string& str);
	~Arithmetic() { delete[] pLexem; }
   
	void DivideIntoLexemes(); // ��������� ������ �� �������
	void PolishNotation(); // ������� � � �������� ������
	double Calculate(); // ���������� �� �������� ������

	bool CheckBrackets();
	bool CheckSymbols();
	bool CheckOperators();
	bool CheckPoints();
	void DeleteSpaces();
	void Minus();

	string getChar(int i) { return pLexem[i].CH; };
	int getNLexemes() { return nLexemes; };

};