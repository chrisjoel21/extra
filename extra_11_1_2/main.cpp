//The program implements the insertion of node in binary search tree
#include <iostream>
using namespace std;

class BinaryST {
    int data;
    BinaryST *left; 
    BinaryST *right;
 
public:
    BinaryST();
    BinaryST(int);
    BinaryST* Insert(BinaryST*, int);
    void Inorder(BinaryST*);
};

BinaryST::BinaryST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}

BinaryST::BinaryST(int num) {
    data = num;
    left = right = NULL;
}

BinaryST* BinaryST ::Insert(BinaryST* rootValue, int num)
{
    if (!rootValue) {
        return new BinaryST(num);
    }
    if (num > rootValue->data) {
        rootValue->right = Insert(rootValue->right, num);
    }
    else if (num < rootValue->data){
        rootValue->left = Insert(rootValue->left, num);
    }
  
    return rootValue;
}

void BinaryST::Inorder(BinaryST* rootValue) {
    if (!rootValue) {
        return;
    }
    Inorder(rootValue->left);
    cout << rootValue->data << endl;
    Inorder(rootValue->right);
}

int main() {
    BinaryST b, *rootValue = NULL;
    rootValue = b.Insert(rootValue, 50);
    b.Insert(rootValue, 55);
    b.Insert(rootValue, 39);
    b.Insert(rootValue, 77);
    b.Insert(rootValue, 23);
    b.Insert(rootValue, 49);
    b.Insert(rootValue, 14);
 
    b.Inorder(rootValue);
  
    return 0;
}
