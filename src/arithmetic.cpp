
#include "arithmetic.h"
#include <iostream>
using std::cin;
using std::cout;

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
			OP = '0';
			break;
		}
		case ')':
		{
			type = CLOSE_BRACKET;
			val = 0;
			OP = '0';
			break;
		}
		case '-':
		{
			type = OPERATOR;;
			val = 1;
			OP = '-';
			break;
		}
		case '+':
		{
			type = OPERATOR;;
			val = 1;
			OP = '+';
			break;
		}
		case '*':
		{
			type = OPERATOR;;
			val = 2;
			OP = '*';
			break;
		}
		case '/':
		{
			type = OPERATOR;;
			val = 2;
			OP = '/';
			break;
		}
		default: type = UNKNOWN;
			break;

      }
	if (c >= 97 && c <=122 || c >= 65 && c <= 90)
	{
		type = VARIABLE;;
		//val =  0;
		OP = c;
	}

}

//..........................................................
Lexem::Lexem(const string& Num)
{ 
	val = stod(Num);
	type = NUMBER;
	OP = '0';
}
//..........................................................
Lexem::Lexem(const Lexem &L)
{
	val = L.val;
	type = L.type;
	OP = L.OP;
}
//..........................................................
Lexem& Lexem::operator=(const Lexem &L)
{
	val = L.val;
	type = L.type;
	OP = L.OP;
	return *this;
}

void Lexem::inpVar()
{
	cout << "Input VARIABLE " << OP << " : ";
	cin >> val;
	cout << endl;
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
			Lexem OPER(c);
			pLexem[nLexemes] = OPER;
			nLexemes++;
		}
		else
			if (isdigit(c))
			{
				string Num;
				int j = i;
				int L = Str.length();
				while ((j < L) && ((isdigit(Str[j])) || Str[j] == '.'))
				{
					j++;
				}
				Num = Str.substr(i, j - i);
				pLexem[nLexemes] = Lexem(Num);
				nLexemes++;
				i = j - 1;
			}
			else
				if (c >= 97 && c <= 122 || c >= 65 && c <= 90)
				{
					pLexem[nLexemes] = Lexem(c);
					nLexemes++;
				}
				else 
					if (c != ' ')
					{
						pLexem[nLexemes].type = UNKNOWN;
						nLexemes++;
					}

	}
}

void Arithmetic::PolishNotation()
{    
    
	Stack<Lexem> st; 
	PolishN = new Lexem[nLexemes];
	int j = 0;

	for (int i = 0; i < nLexemes; i++)
	{   

		if (pLexem[i].type == NUMBER || pLexem[i].type == VARIABLE)
			PolishN[j++] = pLexem[i];

		if (pLexem[i].type == OPEN_BRACKET)
			st.push(pLexem[i]);

		if (pLexem[i].type == CLOSE_BRACKET)
		{
			while (st.getTop().type != OPEN_BRACKET)
				PolishN[j++] = st.pop();
			st.pop();
		}
		

		if (pLexem[i].type == OPERATOR)
		{
			if (st.isEmpty())
			{
				st.push(pLexem[i]);
			}
			else
			{
				Lexem L = st.getTop();
				while (!st.isEmpty() && L.val >= pLexem[i].val) // :?
				{
					L = st.pop();
					PolishN[j++] = L;
					L = st.getTop();
				}
				st.push(pLexem[i]);
			}
		}
		

	}
	
	while (!st.isEmpty())
	{
		Lexem L = st.pop();
		PolishN[j++] = L;
	}
	NumPolish = j;
}

double Arithmetic::Calculate()
{
	Stack<double> st;
	double res = 0.0;
	
	for (int i = 0; i < NumPolish; i++)
	{
		if (PolishN[i].type == VARIABLE)
		{
			PolishN[i].inpVar();
			for (int j = i + 1; j< NumPolish; j++)
			{
				if (PolishN[j].OP == PolishN[i].OP)
				{
					PolishN[j].val = PolishN[i].val;
					PolishN[j].type = NUMBER;
				}
			}
			PolishN[i].type = NUMBER;
		}
	}

	//for (int i = 0; i < NumPolish; i++)
		//cout << PolishN[i].OP << ' ' ;
//	cout << endl;

	for (int i = 0; i < NumPolish; i++)
	{   
		
		if (PolishN[i].type == NUMBER)
		{
			st.push(PolishN[i].val);

		}
		if (PolishN[i].type == OPERATOR)
		{
			double A = st.pop();
			double B = st.pop();

			switch (PolishN[i].OP)
			{
			case '+': 
				res = A + B;
				break;
			case '-':
				res = B - A;
				break;
			case '*':
				res = A * B;
				break;
			case '/':
				res = B / A;
				break;
			}
			st.push(res);
		}
	}
	return st.pop();
}

bool Arithmetic::CheckBracket()
{
	int NBR = 0;

	for (int i = 0; i < nLexemes; i++)
	{
		if (pLexem[i].type == OPEN_BRACKET)
			NBR++;

		if (pLexem[i].type == CLOSE_BRACKET)
			NBR--;
	}

	bool flag = true;

	if (NBR != 0)
	{
		cout << "MISMATCHED BRACKETS, PLS CHECK " << endl;
		flag = false;
	}
	return flag;
}

bool Arithmetic::CheckLetters()
{
	bool flag = true;
	for (int i = 0; i < nLexemes; i++)
	{
		if (pLexem[i].type == UNKNOWN)
		{
			cout << " FORBIDENN SYMBOLS IN " << i << endl;
			flag = false;
		}
	}
	for (int i = 0; i < nLexemes - 1; i++)
	{
		if ((pLexem[i].type == VARIABLE) && (pLexem[i + 1].type == VARIABLE))
		{
			/*int k = 1;
			for (int j = i + 2; j < nLexemes - 1; j++)
			{
				if (pLexem[j].type != VARIABLE)
				{
					j = nLexemes;
				}
				k++;
			}*/
			cout << "UNKNOWN SYMBOL in " << i << endl;
			//i = i + k;
			flag = false;
		}
	}
	return flag;
}

bool Arithmetic::CheckOperators()
{   
	bool flag = true;
	
	if ( ( pLexem[0].type == NUMBER || pLexem[0].type == OPEN_BRACKET || pLexem[0].type == VARIABLE || pLexem[0].OP == '-') && (pLexem[nLexemes - 1].type == NUMBER || pLexem[nLexemes - 1].type == CLOSE_BRACKET || pLexem[nLexemes - 1].type == VARIABLE))
	{
		for (int i = 0; i < (nLexemes - 1); i++)
		{
			switch (pLexem[i].type)
			{
			case NUMBER:
				if ((pLexem[i + 1].type != CLOSE_BRACKET) || (pLexem[i + 1].type != OPERATOR))
				{
					flag = false;
					cout << "Mistake: OPERATORS IN" << i+1 << endl;
				}
				break;
			case OPERATOR:
				if ((pLexem[i + 1].type != NUMBER) || (pLexem[i + 1].type != CLOSE_BRACKET))
				{
					flag = false;
					cout << "Mistake: OPERATORS IN" << i+1<< endl;
				}
				break;
			case OPEN_BRACKET:
				if ((pLexem[i + 1].type != NUMBER) || (pLexem[i + 1].type != CLOSE_BRACKET) || pLexem[i + 1].OP != '-')
				{
					flag = false;
					cout << "Mistake: OPERATORS IN" << i+1 << endl;
				}
				break;
			case CLOSE_BRACKET:
				if ((pLexem[i + 1].type != CLOSE_BRACKET) || (pLexem[i + 1].type != OPERATOR))
				{
					flag = false;
					cout << "Mistake: OPERATORS IN" << i+1 << endl;
				}
					break;
			}
		}
	}

	return flag;

}

bool Arithmetic::CheckPoints()
{
	bool flag = true;

	return flag;
}

void Arithmetic::DeleteSpaces()
{
	int A = string::npos;
	int B = Str.find(' ');
	while (B != string::npos)
	{
		Str.erase(B, 1);
		B = Str.find(' ');
	}
	//nLexemes = Str.length();
}




