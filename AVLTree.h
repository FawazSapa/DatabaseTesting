/*
Tanihsk Singh Bisht
Fawaz Sapa
*/
// AVLTree.h
#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

const int NUM = 250000;

typedef struct EmployeeInfo {
    int salary;
    int age;
    int emplNumber;
    int sin; // Search by social insurance number
} EmployeeInfo;

typedef struct node {
    EmployeeInfo empl;
    node* left;
    node* right;
    int height;
} node;

class AVL {
public:
    AVL();
    ~AVL();
    void insert(EmployeeInfo empl);
    void remove(int sin);
    void display();
    node* GetRoot();
    node* Find(node* node, int sin);

    void populateAVLTree(AVL& tree);
    

private:
    node* root;
    ofstream outfile;

    void makeEmpty(node* t);
    int max(int a, int b);
    int min(int a, int b);
    node* insert(EmployeeInfo empl, node* t);
    node* singleRightRotate(node*& t);
    node* singleLeftRotate(node*& t);
    node* doubleLeftRotate(node*& t);
    node* doubleRightRotate(node*& t);
    node* findMin(node* t);
    node* findMax(node* t);
    node* remove(int sin, node* t);
    int height(node* t);
    int getBalance(node* t);
    void inorder(node* t);
};