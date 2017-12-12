// тесты для стека

#include "stack.h"
#include <gtest.h>

class TestStack : public ::testing::Test
{
protected:
	Stack<int> st;
public:
	TestStack() : st(10)
	{
		for (int i = 0; i < st.getSize(); i++)
			st.push(i);
	}
	~TestStack() {}
};

TEST(Stack, can_create_stack_with_positive_lenght)
{
	ASSERT_NO_THROW(Stack<int> st(1));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> st(-1));
}

TEST(Stack, can_create_empty_stack)
{
	ASSERT_NO_THROW(Stack<int> st);
}

TEST_F(TestStack, can_get_size)
{
	EXPECT_EQ(10, st.getSize());
}

TEST_F(TestStack, can_pop_value)
{
	st.push(10);
	EXPECT_EQ (10, st.pop());
}

TEST_F(TestStack, can_check_stack_status)
{
	EXPECT_EQ(false, st.isEmpty());
}

TEST_F(TestStack, can_clean_stack)
{
	st.clear();
	EXPECT_EQ(true, st.isEmpty());
}

TEST(Stack, cant_pop_empty_Stack)
{
	Stack<int> st;
	ASSERT_ANY_THROW(st.pop());
}
TEST_F(TestStack, can_get_top)
{
	st.push(10);
	EXPECT_EQ(10, st.getTop());
}
