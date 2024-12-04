#include "../mp2-lab5/TQueue.h"

#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_length)
{
    ASSERT_NO_THROW(TQueue<int> v(5));
}

TEST(TQueue, cant_create_queue_with_negative_length)
{
    ASSERT_ANY_THROW(TQueue<int> v(-5));
}

TEST(TQueue, can_create_copied_queue)
{
    TQueue<int> v(5);
    ASSERT_NO_THROW(TQueue<int> v1(v));
}

TEST(TQueue, can_push_and_pop_element)
{
    TQueue<int> v(5);
    ASSERT_NO_THROW(v.Push(5));
    ASSERT_NO_THROW(EXPECT_EQ(v.Pop(), 5));
}

TEST(TQueue, can_get_front_element)
{
    TQueue<int> v(5);
    v.Push(5);
    v.Push(2);
    v.Push(3);
    TQueue<int> v1(v);
    EXPECT_EQ(v.TFront(), 5);
    EXPECT_EQ(v, v1);
}

TEST(TQueue, can_get_back_element)
{
    TQueue<int> v(5);
    v.Push(5);
    v.Push(2);
    v.Push(3);
    TQueue<int> v1(v);
    EXPECT_EQ(v.TBack(), 3);
    EXPECT_EQ(v, v1);
}

TEST(TQueue, queues_with_not_equal_count_elements_are_not_equal)
{
    TQueue<int> v(5);
    TQueue<int> v1(7);

    v.Push(3);
    v.Push(5);
    v.Push(2);

    v1.Push(3);
    v1.Push(5);

    EXPECT_NE(v, v1);
}

TEST(TQueue, compare_equal_queues_return_true)
{
    TQueue<int> v(5);
    TQueue<int> v1(5);

    v.Push(3);
    v.Push(5);
    v.Push(2);
    
    v1.Push(3);
    v1.Push(5);
    v1.Push(2);

    EXPECT_EQ(v, v1);
}

TEST(TQueue, compare_equal_queues_with_different_indexes_return_true)
{
    TQueue<int> v(5);
    TQueue<int> v1(5);
    v.Push(3);
    v.Push(5);
    v.Push(2);

    v1.Push(3);
    v1.Push(8);
    v1.Push(3);
    v1.Push(5);
    v1.Push(2);
    v1.Pop();
    v1.Pop();

    EXPECT_EQ(v, v1);
}

TEST(TQueue, compare_queues_with_equal_elements_with_different_order_return_false)
{
    TQueue<int> v(5);
    TQueue<int> v3(5);
    v.Push(3);
    v.Push(5);
    v.Push(2);

    v3.Push(2);
    v3.Push(5);
    v3.Push(3);

    EXPECT_NE(v, v3);
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
    TQueue<int> v(5);
    v.Push(3);
    v.Push(5);
    v.Push(2);
    TQueue<int> v1(v);
    EXPECT_EQ(v, v1);
}

TEST(TQueue, copied_queue_has_its_own_memory)
{
    TQueue<int> v(5);
    v.Push(3);
    v.Push(5);
    v.Push(2);
    TQueue<int> v1(v);
    v.Pop();

    EXPECT_NE(v, v1);
}

TEST(TQueue, can_assign_queues_of_equal_size)
{
    TQueue<int> v(5);
    v.Push(3);
    v.Push(5);
    v.Push(2);

    TQueue<int> v1(5);
    ASSERT_NO_THROW(v = v1);
    EXPECT_EQ(v, v1);
}

TEST(TQueue, can_assign_queue_to_itself)
{
    TQueue<int> v(5);
    ASSERT_NO_THROW(v = v);
}

TEST(TQueue, assign_operator_change_queue_size)
{
    TQueue<int> v(5);
    TQueue<int> v1(7);
    v = v1;
    EXPECT_EQ(v.getSize(), 7);
}

TEST(TQueue, cant_push_element_to_full_queue)
{
    TQueue<int> v(4);
    v.Push(5);
    v.Push(5);
    v.Push(5);
    v.Push(5);
    ASSERT_ANY_THROW(v.Push(5));
}

TEST(TQueue, cant_pop_element_from_empty_queue)
{
    TQueue<int> v(4);
    v.Push(5);
    v.Push(5);
    v.Pop();
    v.Pop();
    ASSERT_ANY_THROW(v.Pop());
}

TEST(TQueue, can_assign_queues_of_different_size)
{
    TQueue<int> v(5);
    v.Push(3);
    v.Push(5);
    v.Push(2);

    TQueue<int> v1(7);
    ASSERT_NO_THROW(v = v1);
    EXPECT_EQ(v, v1);
}

TEST(TQueue, compare_queue_with_itself_return_true)
{
    TQueue<int> v(5);
    EXPECT_EQ(v, v);
}

TEST(TQueue, created_queue_is_empty)
{
    TQueue<int> v(5);
    EXPECT_EQ(v.isEmpty(), true);

    v.Push(3);
    v.Push(5);
    v.Pop();
    v.Push(2);
    v.Pop();
    v.Pop();
    EXPECT_EQ(v.isEmpty(), true);
}