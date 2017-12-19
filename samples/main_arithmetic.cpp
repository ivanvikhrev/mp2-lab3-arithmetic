// реализация пользовательского приложения
#include "arithmetic.h"
#include  <iostream>
int main()
{
	
	string S = "Y";
	
	while (S == "Y" || S == "y")
	{  

		string Exp = "0";
		cout << "Pls input expression" << endl;
		getline(cin, Exp);
		if (Exp == "")
			getline(cin, Exp);
		Arithmetic A(Exp);
		A.DeleteSpaces();
		A.Minus();
		A.DivideIntoLexemes();
		if (A.CheckBrackets() && A.CheckSymbols() && A.CheckOperators() )
		{
			A.PolishNotation();
			double res = A.Calculate();
			cout << Exp << " = " << res << endl;
		}
		cout << "Would you like to continue? Y/N : ";
		cin >> S;
	}

  return 0;
}
