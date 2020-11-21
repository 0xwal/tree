import org.junit.Assert;
import org.junit.Test;
import tree.BinarySearchTree;

import java.util.Arrays;
import java.util.List;

public class BinarySearchTreeTest
{
    @Test
    public void has_a_null_root_on_initialization()
    {
        BinarySearchTree bst = new BinarySearchTree();
        Assert.assertNull(bst.getRoot());
    }

    @Test
    public void the_first_added_root_should_be_assigned_to_root()
    {
        BinarySearchTree bst = new BinarySearchTree();
        bst.add(5);
        Assert.assertNotNull(bst.getRoot());
        Assert.assertEquals(5, bst.getRoot().getValue());
    }

    @Test
    public void root_should_not_be_changed_when_not_null()
    {
        BinarySearchTree bst = new BinarySearchTree();
        bst.add(5);
        bst.add(3);
        Assert.assertNotNull(bst.getRoot());
        Assert.assertEquals(5, bst.getRoot().getValue());
    }

    @Test
    public void larger_value_should_be_added_to_right()
    {
        BinarySearchTree bst = new BinarySearchTree();
        bst.add(5);
        bst.add(8);
        Assert.assertEquals(8, bst.getRoot().getRight().getValue());
    }

    @Test
    public void small_value_should_be_added_to_left()
    {
        BinarySearchTree bst = new BinarySearchTree();
        bst.add(5);
        bst.add(3);
        Assert.assertEquals(3, bst.getRoot().getLeft().getValue());
    }

    @Test
    public void multiple_values_should_be_added_in_correct_order()
    {
        /*
                      5
                  2        9
                1   3    7   10
              0        6   8
       */
        BinarySearchTree bst = new BinarySearchTree();
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
        List<Integer> expected = Arrays.asList(5, 2, 1, 0, 3, 9, 7, 6, 8, 10);
        Assert.assertEquals(expected, bst.getRoot().preorderTraversal());
    }
}
