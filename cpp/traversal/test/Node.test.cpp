#include <catch2/catch.hpp>
#include <Node.hpp>

TEST_CASE("Node")
{
    Node node(0);

    SECTION("all fields should have default values")
    {
        REQUIRE(node.right == nullptr);
        REQUIRE(node.left == nullptr);
    }

    SECTION("insertRight")
    {
        Node* innerRightNode = node.insertRight(2);
        REQUIRE(node.right != nullptr);
        REQUIRE(node.right->value == 2);
        REQUIRE(innerRightNode == node.right);
    }

    SECTION("insertLeft")
    {
        Node* innerLeftNode = node.insertLeft(3);
        REQUIRE(node.left != nullptr);
        REQUIRE(node.left->value == 3);
        REQUIRE(innerLeftNode == node.left);
    }
}
