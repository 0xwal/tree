<?php


namespace Tree;


class Node
{
    /*** @var mixed */
    public $value;
    public ?Node $right = null;
    public ?Node $left = null;

    public function __construct($value = null)
    {
        $this->value = $value;
    }

    public function insertRight($value): Node
    {
        return $this->right = new Node($value);
    }

    public function insertLeft($value): Node
    {
        return $this->left = new Node($value);
    }

    public function preorderTraversal(): array
    {
        $numbers = [$this->value];

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

        $numbers[] = $this->value;

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

        $numbers[] = $this->value;
        return $numbers;
    }
}