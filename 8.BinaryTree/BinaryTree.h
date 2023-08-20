#pragma once
#include<iostream>
#include "TreeNode.h"
#include"BinaryTree.h"
using namespace std;


class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insertRecursive(TreeNode* currentNode, int value) {
        //якщо поточний елемент наступний, ми створюємо вузол 
        if (currentNode == nullptr) {
            return new TreeNode(value);// створили вузол із значенням, при цьому left and right = nullptr

        }
        //виклик метода рекрусійно
        //якщо вхідні дані value < менше значення , яке є поточним (знаходиться у вузлі дерева
        if (value < currentNode->data) {
            currentNode->left = insertRecursive(currentNode->left, value);//ми ідемо в ліву гілку
        }
        else {
            currentNode->right = insertRecursive(currentNode->right, value);//якщо значення більшого поточного - ідемо в праву гілку
        }

        return currentNode;//вертаємо поточний елемент
    }

    TreeNode* searchRecursive(TreeNode* currentNode, int value) {
        //якщо поточний елемент наступний, ми створюємо вузол 
        if (currentNode == nullptr) {
            return new TreeNode(value);// створили вузол із значенням, при цьому left and right = nullptr

        }
        //виклик метода рекрусійно
        //якщо вхідні дані value < менше значення , яке є поточним (знаходиться у вузлі дерева
        if (value < currentNode->data) {
            currentNode->left = searchRecursive(currentNode->left, value);//ми ідемо в ліву гілку
        }
        if (value == currentNode.data)
        {
            return currentNode;
        }
        else {
            currentNode->right = searchRecursive(currentNode->right, value);//якщо значення більшого поточного - ідемо в праву гілку
        }

        return currentNode;//вертаємо поточний елемент
    }
public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);//інсерт в дерево
    }

    void inorderTraversal(TreeNode* currentNode)
    {

        if (currentNode == nullptr)
        {
            std::cout << "Current Value = " << "----NULL----\n";
            return;
        }
        //std::cout << "----Go to left branch----\n";
        inorderTraversal(currentNode->left);
        std::cout << currentNode->data << " ";
        std::cout << "----Go to right branch----\n";
        inorderTraversal(currentNode->right);
    }

    void inorder() {
        inorderTraversal(root);
    }
    TreeNode search(int data)
    {
        TreeNode * item = searchRecursive(root, data);
        return item;
    }
};
