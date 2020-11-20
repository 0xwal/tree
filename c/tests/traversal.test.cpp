

#include <catch2/catch.hpp>
#include <node.h>
#include <traversal.h>

TEST_CASE("traversal")
{
    /*
     *      0
     *    3   2
     *   5     4
     *
     * */

    node_s* root = node_create(0);
    node_s* innerRight = node_insert_right(root, 2);
    node_s* innerLeft = node_insert_left(root, 3);
    node_insert_right(innerRight, 4);
    node_insert_left(innerLeft, 5);

    clist_s* list = clist_init(16);

    SECTION("inorder should return the correct order")
    {

        inorder_traversal(root, list);
        int expected[] = { 5, 3, 0, 2, 4 };
        for (int i = 0; i < list->size; ++i)
        {
            REQUIRE(expected[i] == list->data[i]);
        }
    }


    SECTION("preorder should return the correct order")
    {
        preorder_traversal(root, list);
        int expected[] = { 0, 3, 5, 2, 4 };
        for (int i = 0; i < list->size; ++i)
        {
            REQUIRE(expected[i] == list->data[i]);
        }
    }

    SECTION("postorder should return the correct order")
    {
        postorder_traversal(root, list);
        int expected[] = { 5, 3, 4, 2, 0 };
        for (int i = 0; i < list->size; ++i)
        {
            REQUIRE(expected[i] == list->data[i]);
        }
    }
    clist_free(&list);
}
