

#include <catch2/catch.hpp>
#include <clist.h>

TEST_CASE("clist")
{
    SECTION("clist initialization")
    {
        clist_s* list = clist_init(5);

        SECTION("capacity should be multiplied by 2")
        {
            REQUIRE(list->capacity == 10);
        }

        SECTION("size should be 0")
        {
            REQUIRE(list->size == 0);
        }

        SECTION("data should be zero")
        {
            REQUIRE(list->data[0] == 0);
            REQUIRE(list->data[1] == 0);
            REQUIRE(list->data[2] == 0);
            REQUIRE(list->data[3] == 0);
            REQUIRE(list->data[4] == 0);
        }
    }

    SECTION("clist capacity")
    {
        clist_s* list = clist_init(1);
        SECTION("capacity will be doubled when we add more than the current capacity")
        {
            REQUIRE(list->capacity == 2);
            clist_add(list, 2);
            clist_add(list, 2);
            clist_add(list, 2);
            REQUIRE(list->capacity == 4);
        }
    }

    SECTION("clist insertion")
    {
        clist_s* list = clist_init(2);

        SECTION("the used should be incremented by 1 when add a new element")
        {
            clist_add(list, 5);
            REQUIRE(list->size == 1);
            clist_add(list, 6);
            REQUIRE(list->size == 2);
        }

        SECTION("able to insert less than the size")
        {
            clist_add(list, 5);
            clist_add(list, 6);
            REQUIRE(list->data[0] == 5);
            REQUIRE(list->data[1] == 6);
        }

        SECTION("able to insert and size will be increased dynamically")
        {
            clist_add(list, 5);
            clist_add(list, 6);
            clist_add(list, 5);
            clist_add(list, 6);
            clist_add(list, 5);

            REQUIRE(list->data[0] == 5);
            REQUIRE(list->data[1] == 6);
            REQUIRE(list->data[2] == 5);
            REQUIRE(list->data[3] == 6);
            REQUIRE(list->data[4] == 5);

            REQUIRE(list->size == 5);
        }

//        clist_free(&list);// no idea why i cannot i get segfault on freeing the memory, might be due to the test framework?
    }

    SECTION("clist destroy")
    {
        clist_s* list = clist_init(2);
        clist_add(list, 5);

        SECTION("size should be zero the list pointer")
        {
            clist_free(&list);
            REQUIRE(list == 0);
        }

        SECTION("fields should be set to 0")
        {
            clist_s* anotherPossiblePointerToSameList = list;
            clist_free(&list);
            REQUIRE(anotherPossiblePointerToSameList->size == 0);
            REQUIRE(anotherPossiblePointerToSameList->capacity == 0);
            REQUIRE(anotherPossiblePointerToSameList->data == NULL);
        }


    }
}
