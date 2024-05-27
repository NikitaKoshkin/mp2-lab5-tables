#include "list.h"
#include "gtest.h"

TEST(list, can_create_list)
{
	ASSERT_NO_THROW(List<int> l);
}

TEST(list, can_copy_list) 
{
	List<int> l;
	ASSERT_NO_THROW(List<int> l2(l));
}

TEST(list, can_get_element_head) 
{
	List<int> l;
	int n = 3;
	l.push_back(n);
	EXPECT_EQ(l.GetHead()->data, 3);
}

TEST(list, can_get_element_tail)
{
	List<int> l;
	int n = 3;
	l.push_back(n);
	EXPECT_EQ(l.GetTail()->data, 3);
}

TEST(list, can_get_element_head_with_2_data)
{
	List<int> l;
	int a = 3;
	int b = 7;
	l.push_back(a);
	l.push_back(b);
	EXPECT_EQ(l.GetHead()->data, 3);
}

TEST(list, can_get_element_tail_with_2_data)
{
	List<int> l;
	int a = 5;
	int b = 7;
	l.push_back(a);
	l.push_back(b);
	EXPECT_EQ(l.GetTail()->data, 7);
}


TEST(list, can_delete_list)
{
	List<int> l;
	int a = 5;
	int b = 7;
	l.push_back(a);
	l.push_back(b);
	l.pop_list(l.GetHead());
	//мы удалили первый элемент, т.к. голова
	EXPECT_EQ(l.GetHead()->data, 7);
}

TEST(list, can_sort_list)
{
	List<int> l;
	l.push_back(4);
	l.push_back(6);
	l.push_back(8);
	l.push_back(7);
	l.sort();
	// 4-6-8-7 -> 8-7-6-4

	EXPECT_EQ(l.GetHead()->data, 8);
	EXPECT_EQ(l.GetTail()->data, 4);
}