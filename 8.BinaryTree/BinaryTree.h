#pragma once
#include<iostream>
#include "TreeNode.h"
#include"BinaryTree.h"
using namespace std;


class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insertRecursive(TreeNode* currentNode, int value) {
        //���� �������� ������� ���������, �� ��������� ����� 
        if (currentNode == nullptr) {
            return new TreeNode(value);// �������� ����� �� ���������, ��� ����� left and right = nullptr

        }
        //������ ������ ���������
        //���� ������ ���� value < ����� �������� , ��� � �������� (����������� � ���� ������
        if (value < currentNode->data) {
            currentNode->left = insertRecursive(currentNode->left, value);//�� ����� � ��� ����
        }
        else {
            currentNode->right = insertRecursive(currentNode->right, value);//���� �������� ������� ��������� - ����� � ����� ����
        }

        return currentNode;//������� �������� �������
    }

    TreeNode* searchRecursive(TreeNode* currentNode, int value) {
        //���� �������� ������� ���������, �� ��������� ����� 
        if (currentNode == nullptr) {
            return new TreeNode(value);// �������� ����� �� ���������, ��� ����� left and right = nullptr

        }
        //������ ������ ���������
        //���� ������ ���� value < ����� �������� , ��� � �������� (����������� � ���� ������
        if (value < currentNode->data) {
            currentNode->left = searchRecursive(currentNode->left, value);//�� ����� � ��� ����
        }
        if (value == currentNode.data)
        {
            return currentNode;
        }
        else {
            currentNode->right = searchRecursive(currentNode->right, value);//���� �������� ������� ��������� - ����� � ����� ����
        }

        return currentNode;//������� �������� �������
    }
public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);//������ � ������
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
