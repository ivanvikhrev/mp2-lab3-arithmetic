
#include "arithmetic.h"

Lexem::Lexem()
{
	type = UNKNOWN;
	val = 0;
}
//..........................................................
Lexem::Lexem(const char c)
{
	
	switch (c)
	{
		case '(':
		{
			type = OPEN_BRACKET;
			val = 0;
			break;
		}
		case ')':
		{
			type = CLOSE_BRACKET;
			val = 0;
			break;
		}
	}

	if ((c == '*') || (c == '/') || (c == '+') || (c == '-'))
	{
		type = OPERATOR;
		val = allOperators.find(c);
	}
}

//..........................................................
Lexem::Lexem(const string& Num)
{ 
	val = stod(Num);
	type = NUMBER;
}
//..........................................................
Lexem::Lexem(const Lexem &L)
{
	val = L.val;
	type = L.type;
}
//..........................................................
Lexem& Lexem::operator=(const Lexem &L)
{
	val = L.val;
	type = L.type;
	return *this;
}

Arithmetic::Arithmetic(const string& str)
{
	pLexem = new Lexem[str.length()];
	Str = str;
	nLexemes = 0;
}

void Arithmetic::DivideIntoLexemes()
{
	for (int i = 0; i < Str.length(); i++)
	{
		char c = Str[i];
		if ((c == '*') || (c == '/') || (c == '+') || (c == '-') || (c == ')') || (c == '(')) 
		{
			pLexem[nLexemes] = Lexem(c); 
			nLexemes++;
		}
		else if (isdigit(c)) 
		{
			string Num;
			int j = i;
			while (j < Str.length() && (Str[j] == isdigit(c) || Str[j] == '.'))
				j++;
			Num = Str.substr(i, j - i);
			pLexem[nLexemes] = Lexem(Num); 
			nLexemes;
			i = j - 1;
		}
		else if (c != ' ')
			throw "ErrorCantDivide";
	}
}

void Arithmetic::Check()
{
	DivideIntoLexemes();// делим на лексемы
	// считаем количество открывающих и закрывающих скобок
	int OP, CL;
	for (int i = 0; i < nLexemes; i++)
	{
		if (pLexem[i].type == OPEN_BRACKET) OP++;
		if (pLexem[i].type == CLOSE_BRACKET) CL++;
	}
	if (OP != CL) throw "MISMATHCED BRACKETS";
    
	// проверяем, что выражение может начинаться и заканчиваться либо с числа, либо со скобки
	if (!(((pLexem[0].type == NUMBER) || (pLexem[0].type == OPEN_BRACKET)) && ((pLexem[nLexemes - 1].type == NUMBER) || (pLexem[nLexemes - 1].type == CLOSE_BRACKET))))
		throw "Erorr";
	//Проверяем что за чем может следовать в выражении

		for (int i = 0; i < (nLexemes - 1); i++)
			switch (pLexem[i].type)
		{
			case NUMBER: 
				if ((pLexem[i + 1].type != CLOSE_BRACKET) || (pLexem[i + 1].type != OPERATOR))
					throw "ErrorOrder";
			case OPERATOR:
				if ((pLexem[i + 1].type != NUMBER) || (pLexem[i + 1].type != CLOSE_BRACKET))
					throw "ErrorOrder";
			case OPEN_BRACKET:
				if ((pLexem[i + 1].type != NUMBER) || (pLexem[i + 1].type != CLOSE_BRACKET))
					throw "ErrorOrder";
			case CLOSE_BRACKET:
				if ((pLexem[i + 1].type != CLOSE_BRACKET) || (pLexem[i + 1].type != OPERATOR))
					throw "ErrorOrder";
		}
		
}

void Arithmetic::PolishNotation()
{    
    
	Stack<Lexem> st; 
	PolishN = new Lexem[nLexemes];
	for (int i = 0; i < nLexemes; i++)
	{
		if (pLexem[i].type == NUMBER) 
			PolishN[i] = pLexem[i];

		if (pLexem[i].type == OPEN_BRACKET)
			st.push(pLexem[i]);

		if (pLexem[i].type == OPERATOR)
		{
			if (st.isEmpty())
				st.push(pLexem[i]);
			else
			{
				Lexem L = st.getTop();

			}
		}
		

	}

}