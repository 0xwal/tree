#include <catch2/catch.hpp>
#include <Traversal.hpp>
#include <Node.hpp>

TEST_CASE("Traversal")
{
    Traversal traversal;

    Node node(0);
    Node* innerRightNode = node.insertRight(2);
    innerRightNode = innerRightNode->insertRight(4);
    innerRightNode->insertRight(8);
    Node* innerLeftNode = node.insertLeft(3);
    innerLeftNode->insertLeft(5);

    SECTION("inorder traversal")
    {
        const std::vector<int>& nodes = traversal.inorder(&node);
        std::vector<int> expected{
                5, 3, 0, 2, 4, 8
        };
        REQUIRE_THAT(nodes, Catch::Matchers::Equals(expected));
    }


    SECTION("preorder traversal")
    {
        const std::vector<int>& nodes = traversal.preorder(&node);
        std::vector<int> expected{
                0, 5, 3, 2, 4, 8
        };
        REQUIRE_THAT(nodes, Catch::Matchers::Equals(expected));
    }

    SECTION("postorder traversal")
    {
        const std::vector<int>& nodes = traversal.postorder(&node);
        std::vector<int> expected{
                5, 3, 2, 4, 8, 0
        };
        REQUIRE_THAT(nodes, Catch::Matchers::Equals(expected));
    }
}
