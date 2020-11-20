

#include <catch2/catch.hpp>
#include <binary-search-tree.h>

TEST_CASE("binary search tree")
{
    SECTION("initialization")
    {
        binary_search_tree_s* bst = bst_create();
        REQUIRE(bst->root == NULL);
    }

    SECTION("when adding for first time we should assign the node to root")
    {
        binary_search_tree_s* bst = bst_create();
        bst_add(bst, 4);
        REQUIRE(bst->root != NULL);
        REQUIRE(bst->root->data == 4);
    }

    SECTION("added node should have NULL for both right and left")
    {
        binary_search_tree_s* bst = bst_create();
        bst_add(bst, 4);
        REQUIRE(bst->root->right == NULL);
        REQUIRE(bst->root->left == NULL);
    }

    SECTION("when adding for second or more time we should not change the root")
    {
        binary_search_tree_s* bst = bst_create();
        bst_add(bst, 4);
        bst_add(bst, 5);
        REQUIRE(bst->root->data == 4);
    }
}
