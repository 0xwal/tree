#include <catch2/catch.hpp>
#include <node.h>

TEST_CASE("node")
{
    SECTION("initialization")
    {
        node_s* rootNode = node_create(5);
        SECTION("create rootNode")
        {
            REQUIRE(rootNode->data == 5);
        }

        SECTION("left and right of the rootNode should be NULL when creating a rootNode")
        {
            REQUIRE(rootNode->right == NULL);
            REQUIRE(rootNode->left == NULL);
        }
        node_destroy(&rootNode);
    }


    SECTION("insertion")
    {
        SECTION("able to insert to the right of the rootNode")
        {
            node_s* rootNode = node_create(5);
            node_insert_right(rootNode, 6);
            REQUIRE(rootNode->right->data == 6);
            node_destroy(&rootNode);
        }

        SECTION("able to insert to the left of the rootNode")
        {
            node_s* rootNode = node_create(5);
            node_insert_left(rootNode, 6);
            REQUIRE(rootNode->left->data == 6);
            node_destroy(&rootNode);
        }
    }

    SECTION("destroying")
    {
        node_s* root = node_create(5);
        SECTION("freeing nodes")
        {
            node_insert_right(root, 6);
            node_insert_left(root, 7);

            node_destroy(&root);

            REQUIRE(root == NULL);
        }

    }


    SECTION("traversal")
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

        SECTION("preorder should return the correct order")
        {
            node_preorder_traversal(root, list);

            int expected[] = { 0, 3, 5, 2, 4 };

            for (int i = 0; i < 5; ++i)
            {
                REQUIRE(expected[i] == list->data[i]);
            }
        }


        SECTION("inorder should return the correct order")
        {

            node_inorder_traversal(root, list);

            int expected[] = { 5, 3, 0, 2, 4 };
            for (int i = 0; i < 5; ++i)
            {
                REQUIRE(expected[i] == list->data[i]);
            }
        }


        SECTION("postorder should return the correct order")

        {
            node_postorder_traversal(root, list);
            int expected[] = { 5, 3, 4, 2, 0 };
            for (int i = 0; i < 5; ++i)
            {
                REQUIRE(expected[i] == list->data[i]);
            }
        }

//        node_destroy(&root);
        clist_free(&list);
    }
}
