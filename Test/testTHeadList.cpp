#include "gtest.h"
#include "../Polinom/THeadList.h"

TEST(THeadList, can_create_list)
{
	ASSERT_NO_THROW(THeadList<int> l);
}
TEST(THeadList, list_after_creating_is_empty)
{
	THeadList<int> l;
	ASSERT_EQ(true, l.isEmpty());
}
TEST(THeadList, list_can_insert_last)
{
	THeadList<int> l;
	l.insFirst(2);
	ASSERT_EQ(false, l.isEmpty());
}
TEST(THeadList, list_can_insert_first)
{
	THeadList<int> l;
	l.insLast(2);
	ASSERT_EQ(false, l.isEmpty());
}
TEST(THeadList, list_can_insert_current)
{
	THeadList<int> l;
	l.insCurrent(2);
	ASSERT_EQ(false, l.isEmpty());
}
TEST(THeadList, list_can_delete_first)
{
	THeadList<int> l;
	l.insFirst(2);
	l.delFirst();
	ASSERT_EQ(true, l.isEmpty());
}
TEST(THeadList, list_can_delete_current)
{
	THeadList<int> l;
	l.insCurrent(2);
	l.delCurr();
	ASSERT_EQ(true, l.isEmpty());
}

TEST(THeadList, list_can_get_current_value)
{
	THeadList<int> l;
	l.insCurrent(2);
	ASSERT_EQ(2, l.getCurrValue());
}
TEST(THeadList, list_can_set_current_value)
{
	THeadList<int> l;
	l.insCurrent(2);
	l.setCurrValue(3);
	ASSERT_EQ(3, l.getCurrValue());
}