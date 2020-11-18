<?php


namespace Tree;


class Node
{
    /*** @var mixed */
    public $data;
    public ?Node $right = null;
    public ?Node $left = null;

    public function __construct($data = null)
    {
        $this->data = $data;
    }

    public function insertRight($data): Node
    {
        return $this->right = new Node($data);
    }

    public function insertLeft($data): Node
    {
        return $this->left = new Node($data);
    }

    public function preorderTraversal(): array
    {
        $numbers = [$this->data];

        if ($this->left !== null) {
            $numbers = array_merge($numbers, $this->left->preorderTraversal());
        }

        if ($this->right !== null) {
            $numbers = array_merge($numbers, $this->right->preorderTraversal());
        }

        return $numbers;
    }

    public function inorderTraversal(): array
    {
        $numbers = [];

        if ($this->left !== null) {
            $numbers = array_merge($numbers, $this->left->inorderTraversal());
        }

        $numbers[] = $this->data;

        if ($this->right !== null) {
            $numbers = array_merge($numbers, $this->right->inorderTraversal());
        }

        return $numbers;
    }

    public function postorderTraversal(): array
    {
        $numbers = [];

        if ($this->left !== null) {
            $numbers = array_merge($numbers, $this->left->postorderTraversal());
        }

        if ($this->right !== null) {
            $numbers = array_merge($numbers, $this->right->postorderTraversal());
        }

        $numbers[] = $this->data;
        return $numbers;
    }
}