<?php


use Tree\BinarySearchTree;

describe('BinarySearchTree', function ()
{
    beforeEach(function ()
    {
        $this->instance = new BinarySearchTree();
    });

    describe('initialization', function ()
    {
        it('should be exits', function ()
        {
            expect($this->instance)
                ->toBeAnInstanceOf(BinarySearchTree::class);
        });

        it('should has a null root on initializing ', function ()
        {
            expect($this->instance->getRoot())->toBeNull();
        });
    });

    describe('insertion', function ()
    {
        it('should assign the given node to the root', function ()
        {
            $this->instance->add(5);
            expect($this->instance->getRoot())->not->toBeNull();
        });

        it('should not change the root when its already filled', function ()
        {
            $this->instance->add(0);
            $this->instance->add(2);
            expect($this->instance->getRoot()->value)->toEqual(0);
        });

        it('should add larger value to the right', function ()
        {
            $this->instance->add(0);
            $this->instance->add(2);
            expect($this->instance->getRoot()->right->value)->toEqual(2);
        });

        it('should add smaller value to the left', function ()
        {
            $this->instance->add(2);
            $this->instance->add(0);
            expect($this->instance->getRoot()->left->value)->toEqual(0);
        });

        it('should add elements to the right in order', function ()
        {
            /*
             * Expected Tree
             *
             *    1
             *     2
             *      3
             *       4
             *        5
             *
             * */

            /** @var BinarySearchTree $binarySearchTree */
            $binarySearchTree = $this->instance;
            $binarySearchTree->add(1);
            $binarySearchTree->add(2);
            $binarySearchTree->add(3);
            $binarySearchTree->add(4);
            $binarySearchTree->add(5);
            $rootNode = $binarySearchTree->getRoot();
            expect($rootNode->preorderTraversal())->toEqual([1, 2, 3, 4, 5]);
        });

        it('should add elements to the left in order', function ()
        {
            /*
             *  Expected Tree
             *
             *      5
             *     4
             *    3
             *   2
             *  1
             *
             * */

            /** @var BinarySearchTree $binarySearchTree */
            $binarySearchTree = $this->instance;
            $binarySearchTree->add(5);
            $binarySearchTree->add(4);
            $binarySearchTree->add(3);
            $binarySearchTree->add(2);
            $binarySearchTree->add(1);
            $rootNode = $binarySearchTree->getRoot();
            expect($rootNode->preorderTraversal())->toEqual([5, 4, 3, 2, 1]);
        });

        it('should add mixed values', function ()
        {
            /*
             *  Expected Tree
             *
             *         5
             *      4     8
             *    3     6
             *
             * */

            /** @var BinarySearchTree $binarySearchTree */
            $binarySearchTree = $this->instance;
            $binarySearchTree->add(5);
            $binarySearchTree->add(8);
            $binarySearchTree->add(4);
            $binarySearchTree->add(6);
            $binarySearchTree->add(3);
            $rootNode = $binarySearchTree->getRoot();
            expect($rootNode->preorderTraversal())->toEqual([5, 4, 3, 8, 6]);
        });
    });

    describe('retrieve', function ()
    {
        beforeEach(function ()
        {
            /*
            *  Expected Tree
            *
            *          8
            *     6        10
            *  3    7    9    11
            *
            * */

            /** @var BinarySearchTree $binarySearchTree */
            $binarySearchTree = $this->instance;
            $binarySearchTree->add(8);
            $binarySearchTree->add(10);
            $binarySearchTree->add(9);
            $binarySearchTree->add(11);
            $binarySearchTree->add(6);
            $binarySearchTree->add(7);
            $binarySearchTree->add(3);
        });

        it('should find existent value and return iteration count', function ()
        {
            /** @var BinarySearchTree $binarySearchTree */
            $binarySearchTree = $this->instance;
            expect($binarySearchTree->find(8))->toEqual(0);
            expect($binarySearchTree->find(10))->toEqual(1);
            expect($binarySearchTree->find(6))->toEqual(1);
            expect($binarySearchTree->find(11))->toEqual(2);
            expect($binarySearchTree->find(9))->toEqual(2);
            expect($binarySearchTree->find(7))->toEqual(2);
            expect($binarySearchTree->find(3))->toEqual(2);
        });

        it('should return -1 when value is not exist', function ()
        {
            /** @var BinarySearchTree $binarySearchTree */
            $binarySearchTree = $this->instance;
            expect($binarySearchTree->find(100))->toEqual(-1);
        });

        it('should return -1 when tree is empty', function ()
        {
            $bst = new BinarySearchTree();
            expect($bst->find(20))->toEqual(-1);
        });
    });
});