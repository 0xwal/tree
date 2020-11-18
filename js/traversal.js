class Node
{
    value;
    right;
    left;

    constructor(value)
    {
        this.value = value;
    }

    insertRight(value)
    {
        const node = new Node(value);
        this.right = node;
        return node;
    }

    insertLeft(value)
    {
        const node = new Node(value);
        this.left = node;
        return node;
    }

    inorderTraversal()
    {
        if (this.left) {
            this.left.inorderTraversal();
        }
        console.log(this.value);
        if (this.right) {
            this.right.inorderTraversal();
        }
    }

    preorderTraversal()
    {
        console.log(this.value);
        if (this.left) {
            this.left.preorderTraversal();
        }
        if (this.right) {
            this.right.preorderTraversal();
        }
    }

    postorderTraversal()
    {
        if (this.left) {
            this.left.postorderTraversal();
        }
        if (this.right) {
            this.right.postorderTraversal();
        }
        console.log(this.value);
    }
}


const root = new Node(0);

const rightNode = root.insertRight(2);
rightNode.insertRight(4);

const leftNode = root.insertLeft(3);
leftNode.insertLeft(5);


console.log('----inorder traversal----');
root.inorderTraversal();

console.log('----preorder traversal----');
root.preorderTraversal();

console.log('----postorder traversal----');
root.postorderTraversal();
