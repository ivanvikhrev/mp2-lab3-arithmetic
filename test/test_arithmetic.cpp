// тесты для вычисления арифметических выражений
#include <gtest.h>
#include "arithmetic.h"

//Ошибочные выражение
string MistakeInOp[15] = {"10++5", "14+)5","--(15+5)", "(15+5)++", "--15+5" , 
"15+5++" , "15+5+", "15+", "+15", "(+11-4)","(11-4+)","15A+14","A15+1","5A6", "()" };
string MistakeInBr[5] = {"11-1)","(11-1", "((11+5)", "A)B", "A(B" };
string MistakeInLt[4] = { "Aa+4","aaaA", "5&6", "15+16="};
//Верные выражения
string CorrectExpressions[6] = { "-1","-11+5","1+1", "-(15+6)*11", "23+11*(18+44/11)","-11*(-8)" };
double Result1[6] = { -1,-6,2,-(15 + 6) * 11, 23 + 11 * (18 + 44 / 11),-11 * (-8) };
string ExpressionsWithDoubles[4] = { "2.0-1.0","14/5", "18.6+1.4", "1.5*1.5" };
double Result2[4] = { 2.0 - 1.0 ,14.0/5.0 , 18.6 + 1.4, 1.5*1.5 };


/*class ArithmTest : public ::testing::Test
{
	protected:
		Arithmetic A;

};*/

TEST(Arithmetic, test_can_check_wrong_operators)
{
	bool check=false;
	for (int i = 0; i < 15; i++)
	{
		Arithmetic A(MistakeInOp[i]);
		A.DeleteSpaces();
		A.Minus();
		A.DivideIntoLexemes();
		cout << "Expression  : " << MistakeInOp[i] << " " ;
		check = A.CheckOperators();
		if (check == true) { break;  };

	}
	EXPECT_EQ(false, check);
}
TEST(Arithmetic, test_can_check_wrong_brackets)
{
	bool check = false;
	for (int i = 0; i < 5; i++)
	{
		Arithmetic A(MistakeInBr[i]);
		A.DeleteSpaces();
		A.Minus();
		A.DivideIntoLexemes();
		cout << "Expression  : " << MistakeInOp[i] << " ";
		check = A.CheckBrackets();
		if (check == true) { break; }

	}
	EXPECT_EQ(false, check);
}

TEST(Arithmetic, test_can_check_wrong_symbols)
{
	bool check = false;
	for (int i = 0; i < 4; i++)
	{
		Arithmetic A(MistakeInLt[i]);
		A.DeleteSpaces();
		A.Minus();
		A.DivideIntoLexemes();
		cout << "Expression  : " << MistakeInLt[i] << " ";
		check = A.CheckSymbols();
		if (check == true) { break; }

	}
	EXPECT_EQ(false, check);
}
TEST(Arithmetic, test_can_calculate_correct_expressions)
{
	bool check = true;
	for (int i = 0; i < 6; i++)
	{
		Arithmetic A(CorrectExpressions[i]);
		double res = 0;
		A.DeleteSpaces();
		A.Minus();
		A.DivideIntoLexemes();
		if (A.CheckBrackets() && A.CheckSymbols() && A.CheckOperators())
		{
			A.PolishNotation();
			res = A.Calculate();
			if (res != Result1[i])
			{
				check = false;
				break;
			}
		}
			else 
			{
				check = false; 
				break;
			     
			} 
		cout << "Expression  : " << CorrectExpressions[i] << "=" << res << endl;

	}
	EXPECT_EQ(true, check);
}

TEST(Arithmetic, test_can_calculate_correct_expressions_with_doubles)
{
	bool check = true;
	for (int i = 0; i < 4; i++)
	{
		Arithmetic A(ExpressionsWithDoubles[i]);
		double res = 0;
		A.DeleteSpaces();
		A.Minus();
		A.DivideIntoLexemes();
		if (A.CheckBrackets() && A.CheckSymbols() && A.CheckOperators())
		{
			A.PolishNotation();
			res = A.Calculate();
			if (res != Result2[i])
			{
				check = false;
				break;
			}
		}
		else
		{
			check = false;
			break;

		}
		cout << "Expression  : " << ExpressionsWithDoubles[i] << "=" << res << endl;

	}
	EXPECT_EQ(true, check);
}

