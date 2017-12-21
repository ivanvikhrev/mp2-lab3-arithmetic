// ���������� ������� � ������� ��� ���������� �������������� ���������

#include <string>
#include "stack.h"




enum  LexemTypes { OPEN_BRACKET, CLOSE_BRACKET, OPERATOR, NUMBER, VARIABLE, UNKNOWN };

const string allOperators = "(-+*/)"; 

struct Lexem
{
	LexemTypes type; // ��� �������
	double val; // �������� ��������
	char OP; // ���������� ��������
	string CH = "0"; // ���� �������

	Lexem();// ����������� �� ���������

	Lexem(const char c); // ����������� ��� ������� c
	Lexem(const string& Num); // ����������� ��� �����
	Lexem(const Lexem &L);// ����������� �����������

	Lexem& operator=(const Lexem &L);
	void inpVar(); // ���� �������� ����������
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
	void DeleteSpaces();
	void Minus();

	string getChar(int i) { return pLexem[i].CH; };
    string getPolishChar(int i) { return PolishN[i].CH; };
	string getExp() { return Str; };
	int getNLexemes() { return nLexemes; };

};