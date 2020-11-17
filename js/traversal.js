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
}

function inorder_traversal(node)
{
    if (node === undefined) {
        return;
    }

    inorder_traversal(node.left);
    console.log(node.value);
    inorder_traversal(node.right);
}

function preorder_traversal(node)
{
    if (node === undefined) {
        return;
    }

    console.log(node.value);
    preorder_traversal(node.left);
    preorder_traversal(node.right);
}


function postorder_traversal(node)
{
    if (node === undefined) {
        return;
    }

    postorder_traversal(node.left);
    postorder_traversal(node.right);
    console.log(node.value);
}

const root = new Node(0);

const rightNode = root.insertRight(2);
rightNode.insertRight(4);

const leftNode = root.insertLeft(3);
leftNode.insertLeft(5);


console.log('----inorder traversal----');
inorder_traversal(root);

console.log('----preorder traversal----');
preorder_traversal(root);

console.log('----postorder traversal----');
postorder_traversal(root);
