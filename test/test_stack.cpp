// тесты для стека

#include "stack.h"
#include <gtest.h>

TEST (Stack, test_can_create_stack_with_positive_index)
{
	ASSERT_NO_THROW ( Stack<int> s(5));

}

TEST(Stack, test_cant_create_stack_with_negative_index)
{
  ASSERT_ANY_THROW(Stack<int> s(-1));
}

TEST(Stack, can_create_copied_stack)
{
   Stack<int> s(5);
   ASSERT_NO_THROW(Stack<int> s1(s)); 
   
}
//!!!