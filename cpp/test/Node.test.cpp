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
        Node root(10);

        root.insertRight(20)
                ->insertRight(40);

        root.insertLeft(30)
                ->insertLeft(50);

        SECTION("preorder traversal")
        {
            const std::list<int>& list = root.preorderTraversal();
            const std::vector result(list.begin(), list.end());
            const std::vector<int> expected{
                    10, 30, 50, 20, 40
            };

            REQUIRE_THAT(result, Catch::Matchers::Equals(expected));
        }

        SECTION("inorder traversal")
        {
            const std::list<int>& list = root.inorderTraversal();
            const std::vector result(list.begin(), list.end());
            const std::vector<int> expected{
                    50, 30, 10, 20, 40
            };

            REQUIRE_THAT(result, Catch::Matchers::Equals(expected));
        }

        SECTION("postorder traversal")
        {
            const std::list<int>& list = root.postorderTraversal();
            const std::vector result(list.begin(), list.end());
            const std::vector<int> expected{
                    50, 30, 40, 20, 10
            };

            REQUIRE_THAT(result, Catch::Matchers::Equals(expected));
        }
    }
}
