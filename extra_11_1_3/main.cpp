//The program implements the deletion of node in binary searh tree and modifies the traversal of the tree.

#include <iostream>
using namespace std;

struct Node {
    int value;  
    Node *left;
    Node *right;
};

Node* newNode(int key) {
    Node* temp = new Node;
    temp->value = key;
    temp->left = temp->right = NULL;
    return temp;
}

void inorderTraversal(Node* rootNum) {
    if (rootNum != NULL) {
        inorderTraversal(rootNum->left);
        printf("%d ", rootNum->value);
        inorderTraversal(rootNum->right);
    }
}

Node* insertItem(Node* head, int key) {
    if (head == NULL)
        return newNode(key);
    if (key < head->value)
        head->left = insertItem(head->left, key);
    else
        head->right = insertItem(head->right, key);
    return head;
}

Node* deleteNode(Node* rootNum, int m) {
    if (rootNum == NULL)
        return rootNum;
    if (rootNum->value > m) {
        rootNum->left = deleteNode(rootNum->left, m);
        return rootNum;
    }
    else if (rootNum->value < m) {
        rootNum->right = deleteNode(rootNum->right, m);
        return rootNum;
    }
    if (rootNum->left == NULL) {
        Node* temp = rootNum->right;
        delete rootNum;
        return temp;
    }
    else if (rootNum->right == NULL) {
        Node* temp = rootNum->left;
        delete rootNum;
        return temp;
    }
  
    else {
        Node* succParent = rootNum;
        Node* success = rootNum->right;
        while (success->left != NULL) {
            succParent = success;
            success = success->left;
        }
        if (succParent != rootNum)
            succParent->left = success->right;
        else
            succParent->right = success->right;
        rootNum->value = success->value;
  
        delete success;
        return rootNum;
    }
}

int main(){
  
    Node* rootNum = NULL;
    rootNum = insertItem(rootNum, 36);
    rootNum = insertItem(rootNum, 23);
    rootNum = insertItem(rootNum, 48);
    rootNum = insertItem(rootNum, 12);
    rootNum = insertItem(rootNum, 57);
    rootNum = insertItem(rootNum, 89);
    rootNum = insertItem(rootNum, 75);

    cout << "The inorder traversal" << endl; 
    inorderTraversal(rootNum);
    cout << endl;

    deleteNode(rootNum, 89);
    deleteNode(rootNum, 12);
    deleteNode(rootNum, 23);
    cout << "The inorder traversal after deletion" << endl;
    inorderTraversal(rootNum);

  return 0;
}