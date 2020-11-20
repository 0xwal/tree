#include <catch2/catch.hpp>
#include <node.h>

TEST_CASE("node")
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


    SECTION("able to insert to the right of the rootNode")
    {
        node_s* root = node_create(5);
        node_insert_right(root, 6);
        REQUIRE(root->right->data == 6);
    }

    SECTION("able to insert to the left of the rootNode")
    {
        node_insert_left(rootNode, 6);
        REQUIRE(rootNode->left->data == 6);
    }

    SECTION("freeing nodes")
    {
        node_s* root = node_create(5);
        node_insert_right(root, 6);
        node_insert_left(root, 7);

        node_destroy(&root);

        REQUIRE(root == NULL);
    }

    node_destroy(&rootNode);
}
