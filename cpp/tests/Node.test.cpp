#include <catch2/catch.hpp>
#include <Node.hpp>

TEST_CASE("Node")
{

    SECTION("initialization")
    {
        Node node(0);
        SECTION("all fields should have default values")
        {
            REQUIRE(node.right == nullptr);
            REQUIRE(node.left == nullptr);
            REQUIRE(node.value == 0);
        }
    }

    SECTION("insertion")
    {
        Node node(1);
        SECTION("able to insert to right")
        {
            auto innerRightNode = node.insertRight(2);
            REQUIRE(node.right != nullptr);
            REQUIRE(node.right->value == 2);
        }

        SECTION("able to insert to left")
        {
            auto innerLeftNode = node.insertLeft(3);
            REQUIRE(node.left != nullptr);
            REQUIRE(node.left->value == 3);
        }
    }

    SECTION("traversal")
    {
        Node root(1);

        auto innerRight = root.insertRight(2);
        innerRight = innerRight->insertRight(3);
        innerRight->insertRight(9);
        innerRight->insertLeft(5);

        auto innerLeft = root.insertLeft(70);
        innerLeft = innerLeft->insertLeft(7);
        innerLeft->insertRight(8);


        /*
         *         1
         *      70    2
         *    7          3
         *       8     5  9
         *
         *
         */

        SECTION("preorder traversal")
        {
            const std::list<int>& list = root.preorderTraversal();
            const std::vector result(list.begin(), list.end());
            const std::vector<int> expected{
                    1, 70, 7, 8, 2, 3, 5, 9
            };

            REQUIRE_THAT(result, Catch::Matchers::Equals(expected));
        }

        SECTION("inorder traversal")
        {
            const std::list<int>& list = root.inorderTraversal();
            const std::vector result(list.begin(), list.end());
            const std::vector<int> expected{
                    7, 8, 70, 1, 2, 5, 3, 9
            };

            REQUIRE_THAT(result, Catch::Matchers::Equals(expected));
        }

        SECTION("postorder traversal")
        {
            const std::list<int>& list = root.postorderTraversal();
            const std::vector result(list.begin(), list.end());
            const std::vector<int> expected{
                    8, 7, 70, 5, 9, 3, 2, 1
            };

            REQUIRE_THAT(result, Catch::Matchers::Equals(expected));
        }
    }
}
