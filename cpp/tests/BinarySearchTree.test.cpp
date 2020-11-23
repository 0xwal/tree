#include <catch2/catch.hpp>
#include <BinarySearchTree.hpp>
#include <iostream>

TEST_CASE("BinarySearchTree")
{
    SECTION("initialization")
    {
        SECTION("root should be nullptr")
        {
            BinarySearchTree bst;
            REQUIRE(bst.root() == nullptr);
        }
    }

    SECTION("insertion")
    {
        SECTION("root should be the first added node")
        {
            BinarySearchTree bst;
            bst.add(2);
            REQUIRE(bst.root()->value == 2);
        }

        SECTION("root should point to the first added node when adding a second node")
        {
            BinarySearchTree bst;
            bst.add(2);
            bst.add(3);
            REQUIRE(bst.root()->value == 2);
        }

        SECTION("larger value should be added to the right")
        {
            BinarySearchTree bst;
            bst.add(2);
            bst.add(3);
            REQUIRE(bst.root()->right->value == 3);
        }

        SECTION("smaller value should be added to the left")
        {
            BinarySearchTree bst;
            bst.add(2);
            bst.add(1);
            REQUIRE(bst.root()->left->value == 1);
        }

        SECTION("able to add multiple values in correct order")
        {
            /*
                      5
                  2        9
                1   3    7   10
              0        6   8

             */

            BinarySearchTree bst;
            bst.add(5);
            bst.add(2);
            bst.add(1);
            bst.add(3);
            bst.add(9);
            bst.add(10);
            bst.add(7);
            bst.add(6);
            bst.add(8);
            bst.add(0);

            const std::list<int>& list = bst.root()->preorderTraversal();

            const std::vector<int> result(list.begin(), list.end());

            const std::vector<int> expected {
                    5, 2, 1, 0, 3, 9, 7, 6, 8, 10
            };

            REQUIRE_THAT(result, Catch::Matchers::Equals(expected));
        }
    }

    SECTION("retrieve")
    {
        SECTION("find existent value and return iteration count")
        {
            /*
                     5
                 2        9
               1   3    7   10
             0        6   8

            */

            BinarySearchTree bst;
            bst.add(5);
            bst.add(2);
            bst.add(1);
            bst.add(3);
            bst.add(9);
            bst.add(10);
            bst.add(7);
            bst.add(6);
            bst.add(8);
            bst.add(0);

            REQUIRE(bst.find(5) == 0);
            REQUIRE(bst.find(2) == 1);
            REQUIRE(bst.find(9) == 1);
            REQUIRE(bst.find(1) == 2);
            REQUIRE(bst.find(3) == 2);
            REQUIRE(bst.find(0) == 3);
            REQUIRE(bst.find(7) == 2);
            REQUIRE(bst.find(10) == 2);
            REQUIRE(bst.find(6) == 3);
            REQUIRE(bst.find(8) == 3);
        }

        SECTION("should return -1 when trying to find a non existent value")
        {
            BinarySearchTree bst;
            bst.add(5);
            bst.add(5);
            REQUIRE(bst.find(100) == -1);
        }

        SECTION("should return -1 when tree is empty")
        {
            BinarySearchTree bst;
            REQUIRE(bst.find(100) == -1);
        }
    }
}
