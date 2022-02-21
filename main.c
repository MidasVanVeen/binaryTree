#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));

  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
};

void invert(struct Node* node) {
  if (node == NULL)
    return;

  invert(node->left);
  invert(node->right);

  struct Node* temp;
  temp = node->left;
  node->left = node->right;
  node->right = temp;
}

void printTree(struct Node* node) {
  if (node == NULL)
    return;

  printTree(node->left);
  printf("%d ", node->data);
  printTree(node->right);
}

int main(void) {
  struct Node* root = newNode(1);

  root->left = newNode(2);
  root->left->left = newNode(3);
  root->left->right = newNode(4);

  root->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);

  printTree(root);
  printf("\n");
  invert(root);
  printTree(root);
  printf("\n");

  return 0;
}
