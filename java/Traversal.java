

public class Traversal
{
    private static void inorderTraversal(Node node)
    {
        if (node == null) {
            return;
        }

        inorderTraversal(node.left);
        System.out.println(node.value);
        inorderTraversal(node.right);
    }

    private static void preorderTraversal(Node node)
    {
        if (node == null) {
            return;
        }

        System.out.println(node.value);
        preorderTraversal(node.left);
        preorderTraversal(node.right);
    }

    private static void postorderTraversal(Node node)
    {
        if (node == null) {
            return;
        }

        postorderTraversal(node.left);
        postorderTraversal(node.right);
        System.out.println(node.value);
    }

    public static void main(String[] args) {
        Node root = new Node(0);

        Node innertRight = root.insertRight(2);
        innertRight.insertRight(4);

        Node innerLeft = root.insertLeft(3);
        innerLeft.insertLeft(5);

        System.out.println("----inorder traversal----");
        inorderTraversal(root);

        System.out.println("----preorder traversal----");
        preorderTraversal(root);

        System.out.println("----postorder traversal----");
        postorderTraversal(root);
    }
}