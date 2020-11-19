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

        if ($data > $this->root->data) {
            $tmpNode = $this->root;
            while (true) {
                if ($tmpNode->right !== null) {
                    $tmpNode = $tmpNode->right;
                    continue;
                }
                $tmpNode->right = new Node($data);
                break;
            }
        } else {
            $tmpNode = $this->root;
            while (true) {
                if ($tmpNode->left !== null) {
                    $tmpNode = $tmpNode->left;
                    continue;
                }
                $tmpNode->left = new Node($data);
                break;
            }
        }
    }

}