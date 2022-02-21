#include "gtest.h"
#include "../Polinom/TList.h"

TEST(TStack, can_create_list)
{
	ASSERT_NO_THROW(TList<int> l);
}
TEST(TStack, list_after_creating_is_empty)
{
	TList<int> l;
	ASSERT_EQ(true, l.isEmpty());
}
TEST(TStack, list_can_insert_last)
{
	TList<int> l;
	l.insFirst(2);
	ASSERT_EQ(false, l.isEmpty());
}
TEST(TStack, list_can_insert_first)
{
	TList<int> l;
	l.insLast(2);
	ASSERT_EQ(false, l.isEmpty());
}