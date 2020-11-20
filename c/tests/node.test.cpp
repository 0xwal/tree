#include <catch2/catch.hpp>
#include <node.h>

TEST_CASE("node")
{
    node_s* rootNode = create_node(5);
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
        node_s* root = create_node(5);
        insert_right(root, 6);
        REQUIRE(root->right->data == 6);
    }

    SECTION("able to insert to the left of the rootNode")
    {
        insert_left(rootNode, 6);
        REQUIRE(rootNode->left->data == 6);
    }

    SECTION("freeing nodes")
    {
        node_s* root = create_node(5);
        insert_right(root, 6);
        insert_left(root, 7);

        free_nodes(&root);

        REQUIRE(root == NULL);
    }

    free_nodes(&rootNode);
}
