public class Node {
    public int value;
    public Node right;
    public Node left;

    public Node(int value) {
        this.value = value;
        this.right = null;
        this.left = null;
    }

    public Node insertRight(int value) {
        Node node = new Node(value);
        this.right = node;
        return node;
    }

    public Node insertLeft(int value) {
        Node node = new Node(value);
        this.left = node;
        return node;
    }
}