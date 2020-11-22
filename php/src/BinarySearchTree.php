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
        if (! $this->root)
        {
            $this->root = new Node($data);
            return;
        }

        $this->innerAdd($this->root, $data);
    }

    private function innerAdd(Node $currentNode, $value)
    {
        if ($value > $currentNode->value)
        {
            if ($currentNode->right !== null)
            {
                $this->innerAdd($currentNode->right, $value);
                return;
            }
            $currentNode->right = new Node($value);
        }
        else
        {

            if ($currentNode->left !== null)
            {
                $this->innerAdd($currentNode->left, $value);
                return;
            }
            $currentNode->left = new Node($value);
        }
    }

    public function find(int $value): int
    {
        $node = $this->root;
        if (! $node)
        {
            return -1;
        }
        $iteration = 0;
        while (true)
        {
            if ($value === $node->value)
            {
                return $iteration;
            }
            if ($value > $node->value && $node->right)
            {
                $node = $node->right;
                $iteration++;
                continue;
            }
            else
            {
                if ($node->left !== null)
                {
                    $node = $node->left;
                    $iteration++;
                    continue;
                }
            }

            if (! $node->left && ! $node->right)
            {
                break;
            }
        }
        return -1;
    }
}