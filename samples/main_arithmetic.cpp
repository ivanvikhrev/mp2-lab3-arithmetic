// реализация пользовательского приложения
#include "arithmetic.h"
#include  <iostream>
int main()
{
	string Exp, S="YES";
	
	while (S == "YES" || S == "yes")
	{
		cout << "Pls input expression" << endl;
		cin >> Exp;
		Arithmetic A(Exp);
		A.DeleteSpaces();
		A.DivideIntoLexemes();
		if (A.CheckBracket() && A.CheckLetters() && A.CheckOperators() && A.CheckPoints() )
		{
			//A.DivideIntoLexemes();
			A.PolishNotation();
			double res = A.Calculate();
			cout << res << endl;
		}
		cout << "would you like to continue? YES/NO : ";
		cin >> S;
	}

  return 0;
}
