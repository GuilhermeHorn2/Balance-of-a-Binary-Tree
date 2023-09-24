
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

void calc_balance(node &root, int n);

class node
{

public:
 int data;
 int height;
 int balance;
 std::vector<node *> adj;

 node(int d, int h, int b)
 {
  adj.push_back(nullptr);
  adj.push_back(nullptr);
  data = d;
  height = h;
  balance = b;
 }
 ~node() {}
};

int main()
{

 return 0;
}

void calc_balance(node &root, int n)
{
 // root : root node of a BTree and n : number of nodes of this BTree

 if (n == 0)
 {
  return;
 }
 if (n == 1)
 {
  root.height = 0;
  root.balance = 0;
  return;
 }
 std::vector<node *> tmp = root.adj;
 node *left = tmp[0];
 node *right = tmp[1];

 int hl = 0;
 int hr = 0;
 if (left != nullptr)
 {
  calc_balance(*left, n);
  hl = left->height;
 }
 if (right != nullptr)
 {
  calc_balance(*right, n);
  hr = right->height;
 }
 root.height = 1 + std::max(hl, hr);
 root.balance = hl - hr;
}
