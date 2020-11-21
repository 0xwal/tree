import org.junit.Assert;
import org.junit.Test;
import tree.Node;
import java.util.ArrayList;
import java.util.List;

public class NodeTest
{
    @Test
    public void right_and_left_should_be_null()
    {
        Node node = new Node(5);
        Assert.assertNull(node.getRight());
        Assert.assertNull(node.getLeft());
    }

    @Test
    public void value_cannot_be_null()
    {
        Node node = new Node(5);
        Assert.assertEquals(5, node.getValue());
    }

    @Test
    public void able_to_add_node_to_the_right()
    {
        Node node = new Node(5);
        Assert.assertNull(node.getRight());
        node.setRightNode(3);
        Assert.assertNotNull(node.getRight());
        Assert.assertEquals(3, node.getRight().getValue());
    }

    @Test
    public void able_to_add_node_to_the_left()
    {
        Node node = new Node(5);
        Assert.assertNull(node.getLeft());
        node.setLeftNode(3);
        Assert.assertNotNull(node.getLeft());
        Assert.assertEquals(3, node.getLeft().getValue());
    }

    @Test
    public void able_to_preorder_traversal()
    {
        Node node = new Node(5);
        Node innerRightNode = node.setRightNode(3);
        innerRightNode.setLeftNode(2);
        innerRightNode.setRightNode(4);
        List<Integer> expected = new ArrayList<>();
        expected.add(5);
        expected.add(3);
        expected.add(2);
        expected.add(4);
        Assert.assertEquals(expected, node.preorderTraversal());
    }

    @Test
    public void able_to_inorder_traversal()
    {
        Node node = new Node(5);
        Node innerRightNode = node.setRightNode(3);
        innerRightNode.setLeftNode(2);
        innerRightNode.setRightNode(4);
        List<Integer> expected = new ArrayList<>();
        expected.add(5);
        expected.add(2);
        expected.add(3);
        expected.add(4);
        Assert.assertEquals(expected, node.inorderTraversal());
    }

    @Test
    public void able_to_postorder_traversal()
    {
        Node node = new Node(5);
        Node innerRightNode = node.setRightNode(3);
        innerRightNode.setLeftNode(2);
        innerRightNode.setRightNode(4);
        List<Integer> expected = new ArrayList<>();
        expected.add(2);
        expected.add(4);
        expected.add(3);
        expected.add(5);
        Assert.assertEquals(expected, node.postorderTraversal());
    }
}
