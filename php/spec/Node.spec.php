<?php

use Tree\Node;


describe('Node', function ()
{

    beforeEach(fn() => $this->rootNode = new Node(0));

    describe('insertion', function ()
    {
        it('should able to add a node to the right', function ()
        {
            expect($this->rootNode->right)->toBeNull();
            $node = $this->rootNode->insertRight(5);
            expect($this->rootNode->right)->not->toBeNull();
            expect($node)->toBeAnInstanceOf(Node::class);
            expect($node->data)->toEqual(5);
        });


        it('should able to add a node to the left', function ()
        {
            expect($this->rootNode->left)->toBeNull();
            $node = $this->rootNode->insertLeft(5);
            expect($this->rootNode->left)->not->toBeNull();
            expect($node)->toBeAnInstanceOf(Node::class);
            expect($node->data)->toEqual(5);
        });
    });


    describe('traversal', function ()
    {
        beforeEach(function ()
        {
            $innerRight = $this->rootNode->insertRight(2);
            $innerRight->insertRight(4);

            $innerLeft = $this->rootNode->insertLeft(3);
            $innerLeft->insertLeft(5);
        });

        it('should traverse as preorder', function ()
        {
            $result = $this->rootNode->preorderTraversal();
            expect($result)->toEqual([0, 3, 5, 2, 4]);
        });

        it('should traverse as inorder', function ()
        {
            $result = $this->rootNode->inorderTraversal();
            expect($result)->toEqual([5, 3, 0, 2, 4]);
        });

        it('should traverse as postorder', function ()
        {
            $result = $this->rootNode->postorderTraversal();
            expect($result)->toEqual( [5, 3, 4, 2, 0]);
        });

    });

});