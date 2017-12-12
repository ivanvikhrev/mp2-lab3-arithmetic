// ���������� ������� � ������� ��� ���������� �������������� ���������

#include <string>
#include "stack.h"

using namespace std;

enum  LexemTypes { OPEN_BRACKET, CLOSE_BRACKET, OPERATOR, NUMBER, UNKNOWN };

const string allOperators = "*/+-()"; 

struct Lexem
{
	LexemTypes type;
	double val;

	Lexem();// ����������� �� ���������
	Lexem(const char c); // ����������� ��� ������� c
	Lexem(const string& Num); // ����������� ��� �����
	Lexem(const Lexem &L);// ����������� �����������
	Lexem& operator=(const Lexem &L);
    ~Lexem() {};
};

class Arithmetic
{   
private:
	string Str; // ������-��������� 
	Lexem* pLexem; // ������ ������
	Lexem* PolishN; // ������ ������ � �������� �������� ������
	int nLexemes; 

	void DivideIntoLexemes(); // ��������� ������ �� �������
	void PolishNotation(); // ������� � � �������� ������
	double Calculate(); // ���������� �� �������� ������
public:
	Arithmetic(const string& str);
	~Arithmetic() { delete[] pLexem; }
    void Check(); //  �������� ���������� 
};