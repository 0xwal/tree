

#include <catch2/catch.hpp>
#include <binary-search-tree.h>
#include <traversal.h>

#define COMPARE_NODES(clistPointer, values...) \
    int expectedValues[] = values;         \
    int expectedSize = sizeof(expectedValues) / 4; \
    REQUIRE(expectedSize == clistPointer->size); \
    for (int i = 0; i < expectedSize; ++i) \
    {                                        \
        REQUIRE(clistPointer->data[i] == expectedValues[i]);\
    }

TEST_CASE("binary search tree")
{
    SECTION("initialization")
    {
        binary_search_tree_s* bst = bst_create();
        REQUIRE(bst->root == NULL);
    }

    SECTION("addition")
    {
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
            bst_add(bst, 6);
            REQUIRE(bst->root->right->right == NULL);
            REQUIRE(bst->root->right->left == NULL);
        }

        SECTION("when adding for second or more time we should not change the root node")
        {
            binary_search_tree_s* bst = bst_create();
            bst_add(bst, 4);
            bst_add(bst, 5);
            REQUIRE(bst->root->data == 4);
            REQUIRE(bst->root->right != nullptr);
            REQUIRE(bst->root->right->data == 5);
        }


        SECTION("should add a larger value of the current node to right")
        {
            binary_search_tree_s* bst = bst_create();
            bst_add(bst, 4);
            bst_add(bst, 5);
            bst_add(bst, 6);
            clist_s* list = clist_init(16);
            preorder_traversal(bst->root, list);
            COMPARE_NODES(list, { 4, 5, 6 });
        }

        SECTION("should add a smaller value than the current node to left")
        {
            binary_search_tree_s* bst = bst_create();
            bst_add(bst, 6);
            bst_add(bst, 5);
            bst_add(bst, 4);
            clist_s* list = clist_init(16);
            preorder_traversal(bst->root, list);
            COMPARE_NODES(list, { 6, 5, 4 });
        }

        SECTION("mixed with larger and smaller")
        {
            binary_search_tree_s* bst = bst_create();
            bst_add(bst, 6);
            bst_add(bst, 8);
            bst_add(bst, 5);
            bst_add(bst, 3);
            bst_add(bst, 4);
            clist_s* list = clist_init(16);
            preorder_traversal(bst->root, list);
            COMPARE_NODES(list, { 6, 5, 3, 4, 8 });
        }
    }
}
