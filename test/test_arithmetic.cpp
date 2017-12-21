// тесты для вычисления арифметических выражений
#include <gtest.h>
#include "arithmetic.h"

// value parameterized test



//Ошибочные выражение
string MistakeInOp[15] = {"10++5", "14+)5","--(15+5)", "(15+5)++", "--15+5" , 
"15+5++" , "15+5+", "15+", "+15", "(+11-4)","(11-4+)","15A+14","A15+1","5A6", "()" };
string MistakeInBr[5] = {"11-1)","(11-1", "((11+5)", "A)B", "A(B" };
string MistakeInLt[4] = { "Aa+4","aaaA", "5&6", "15+16="};
//Верные выражения
string CorrectExpressions[10] = { "-1","-11+5","1+1", "-(15+6)*11", "23+11*(18+44/11)","-11*(-8)","2.0-1.0","14/5", "18.6+1.4", "1.5*1.5" };
double Result[10] = { -1,-6,2,-(15 + 6) * 11, 23 + 11 * (18 + 44 / 11),-11 * (-8), 2.0 - 1.0 ,14.0 / 5.0 , 18.6 + 1.4, 1.5*1.5 };

// value parameterized test
struct Check_test
{
	string str;
	bool res;
	double Value;
	Check_test(string inputExp, bool inputRes)
	{
		str = inputExp;
		res = inputRes;
	}
	Check_test(string inputExp, double inputValue)
	{
		str = inputExp;
		Value = inputValue;
	}
};
//............................................................................

class Arithm_check_Operators : public ::testing::TestWithParam<Check_test>
{
protected:
	
	Arithmetic test;
		   
public:
	
	Arithm_check_Operators() : test(GetParam().str)
	{
		test.DeleteSpaces();
		test.Minus();
		test.DivideIntoLexemes();
	}
	~Arithm_check_Operators() {}
};
//............................................................................
class Arithm_check_Brackets :  public Arithm_check_Operators
{
	public:
		Arithm_check_Brackets() :Arithm_check_Operators()
		{};
}; 
//............................................................................
class Arithm_check_Symbols: public Arithm_check_Operators
{
public:
	Arithm_check_Symbols() :Arithm_check_Operators()
	{};
};
//............................................................................
TEST_P(Arithm_check_Operators, can_check_wrong_operators)
{
	EXPECT_EQ (GetParam().res, test.CheckOperators());
}
//............................................................................
INSTANTIATE_TEST_CASE_P(FirstCase, Arithm_check_Operators, ::testing::Values(
	Check_test(MistakeInOp[0], false),
	Check_test(MistakeInOp[1], false),
	Check_test(MistakeInOp[2], false),
	Check_test(MistakeInOp[3], false),
	Check_test(MistakeInOp[4], false),
	Check_test(MistakeInOp[5], false),
	Check_test(MistakeInOp[6], false),
	Check_test(MistakeInOp[7], false),
	Check_test(MistakeInOp[8], false),
	Check_test(MistakeInOp[9], false),
	Check_test(MistakeInOp[10], false),
	Check_test(MistakeInOp[11], false),
	Check_test(MistakeInOp[12], false),
	Check_test(MistakeInOp[13], false),
	Check_test(MistakeInOp[14], false)
	));
//........................................................................

TEST_P(Arithm_check_Brackets, test_can_check_wrong_brackets )
{   
	
	EXPECT_EQ(GetParam().res, test.CheckBrackets());
}
//............................................................................
INSTANTIATE_TEST_CASE_P(SecondCase, Arithm_check_Brackets, ::testing::Values(
	Check_test(MistakeInBr[0], false),
	Check_test(MistakeInBr[1], false),
	Check_test(MistakeInBr[2], false),
	Check_test(MistakeInBr[3], false),
	Check_test(MistakeInBr[4], false)
));
//............................................................................
TEST_P(Arithm_check_Symbols, test_can_check_wrong_Symbols)
{

	EXPECT_EQ(GetParam().res, test.CheckSymbols());
}
//............................................................................
INSTANTIATE_TEST_CASE_P(SecondCase, Arithm_check_Symbols, ::testing::Values(
	
	Check_test(MistakeInLt[0], false),
	Check_test(MistakeInLt[1], false),
	Check_test(MistakeInLt[2], false),
	Check_test(MistakeInLt[3], false)
));
//............................................................................
class Arithm_check_Calculate : public Arithm_check_Operators
{
public:
	Arithm_check_Calculate() :Arithm_check_Operators()
	{
		test.PolishNotation();
	};
};
//............................................................................
TEST_P(Arithm_check_Calculate, test_can_calculate_correct_expressions)
{

	EXPECT_EQ(GetParam().Value, test.Calculate());
}
//............................................................................
INSTANTIATE_TEST_CASE_P(SecondCase, Arithm_check_Calculate, ::testing::Values(

	Check_test(CorrectExpressions[0], Result[0]),
	Check_test(CorrectExpressions[1], Result[1]),
	Check_test(CorrectExpressions[2], Result[2]),
	Check_test(CorrectExpressions[3], Result[3]),
	Check_test(CorrectExpressions[4], Result[4]),
	Check_test(CorrectExpressions[5], Result[5]),
	Check_test(CorrectExpressions[6], Result[6]),
	Check_test(CorrectExpressions[7], Result[7]),
	Check_test(CorrectExpressions[8], Result[8]),
	Check_test(CorrectExpressions[9], Result[9])
));
//............................................................................

TEST(Arithmetic, test_can_divide_into_lexems)
{
	bool check = true;
	Arithmetic A("23+11*(18+44/11)"); 
	A.DivideIntoLexemes();
	string CorrectLexems[] = { "23","+","11","*","(","18","+","44","/","11", ")"};
	for (int i = 0; i < A.getNLexemes(); i++)
	{   
		string ch1 = A.getChar(i);
		string ch2 = CorrectLexems[i];

		if (ch1 != ch2)
			check = false;
	}

	EXPECT_EQ(true, check);

}
//............................................................................
TEST(Arithmetic, test_can_divide_into_polish_lexems)
{
	bool check = true;
	Arithmetic A("(40-10)*3+9");
	A.DivideIntoLexemes();
	A.PolishNotation();
	string CorrectLexems[] = { "40","10","-","3","*","9","+" };
	for (int i = 0; i < 7; i++)
	{
		string ch1 = A.getPolishChar(i);
		string ch2 = CorrectLexems[i];

		if (ch1 != ch2)
			check = false;
	}

	EXPECT_EQ(true, check);

}
//............................................................................
TEST(Arithmetic, test_can_delete_spaces)
{
	bool check = true;
	Arithmetic A("  15+11 +22");
	A.DeleteSpaces();
	string CorrectExp = "15+11+22";
	if (A.getExp() != CorrectExp)
			check = false;

	EXPECT_EQ(true, check);

}
//............................................................................
TEST(Arithmetic, test_can_input_0_before_first_minus)
{
	bool check = true;
	Arithmetic A("-11+10");
	A.Minus();
	string CorrectExp = "0-11+10";
	if (A.getExp() != CorrectExp)
		check = false;

	EXPECT_EQ(true, check);

}

