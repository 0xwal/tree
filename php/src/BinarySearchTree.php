<?php


namespace Tree;


class BinarySearchTree
{
    private ?Node $root = null;

    public function getRoot(): ?Node
    {
        return $this->root;
    }

    public function add($data)
    {
        if (!$this->root) {
            $this->root = new Node($data);
            return;
        }

        $this->innerAdd($this->root, $data);
    }

    private function innerAdd(Node $currentNode, $data)
    {
        if ($data > $currentNode->data) {
            if ($currentNode->right !== null) {
                $this->innerAdd($currentNode->right, $data);
                return;
            }
            $currentNode->right = new Node($data);
        } else {

            if ($currentNode->left !== null) {
                $this->innerAdd($currentNode->left, $data);
                return;
            }
            $currentNode->left = new Node($data);
        }
    }
}