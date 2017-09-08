#include <iostream>
using namespace std;

class BinaryTree{
private:
    class TreeNode{
        friend class BinaryTree;
        int value;
        TreeNode *llink;
        TreeNode *rlink;
        TreeNode(int v,TreeNode *l = NULL, TreeNode *r = NULL){
            value = v;
            llink = l;
            rlink = r;
        }
    };
    TreeNode *root;

    void insert(TreeNode *&tree, int num);
    void destorySubtree(TreeNode*);
    void remove(TreeNode *&, int);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode*);
    void displayPreOrder(TreeNode*);
    void displayPostOrder(TreeNode*);

public:
    BinaryTree(){
        root = NULL;
    }
    ~BinaryTree(){
        destorySubtree(root);
    }
    void insert(int num){
        insert(root,num);
    }
    void remove(int num){
        remove(root, num);
    }
    void ShowInOrder(void){
        displayInOrder(root);
    }
    void ShowPreOrder(void){
        displayPreOrder(root);
    }
    void ShowPostOrder(void){
        displayPostOrder(root);
    }
    bool search(int);

};

void BinaryTree::insert(TreeNode* &tree, int num){
    //case1: 空樹，新增節點
    if(tree == NULL){
        tree = new TreeNode(num);
        return;
    }
    //case2: num已經存在BT中
    if(tree->value == num){
        return;
    }
    //case3: 非空樹，插入到左子樹或右子樹 (遞迴呼叫)
    if(num < tree->value){ //比root小，往左子樹
        insert(tree->llink, num);
    }
    else { //比root大，往右子樹
        insert(tree->rlink, num);
    }
}

void BinaryTree::remove(TreeNode* &tree, int num){
    //caae1: 空樹
    if(tree == NULL){
        return;
    }
    //case2: 比樹根小或大，往子樹找(遞迴呼叫)
    if(num < tree->value){
        remove(tree->llink, num);
    }
    else if(num > tree->value){
        remove(tree->rlink, num);
    }
    //非case1、case2，即已找到
    else{
        makeDeletion(tree);
    }
}

void BinaryTree::makeDeletion(TreeNode* &tree){ //刪除tree(子樹的樹根)
    TreeNode* nodeToDelete = tree;
    //刪1-degree節點
    if(tree->rlink == NULL){
        tree = tree->llink;
    }
    else if(tree->llink == NULL){
        tree = tree->rlink;
    }
    //刪2-degree節點
    else{ //找tree的右子樹最小節點，並將該節點llink指向tree的左子樹
        TreeNode* attachPoint;

        attachPoint = tree->rlink;
        while(attachPoint->llink != NULL){
            attachPoint        = attachPoint->llink; //attachPoint指向tree的最小右子樹節點
            attachPoint->llink = tree->llink;        //並將該節點的左子點設為tree的左子樹樹根
            tree               = tree->rlink;
        }
    }
    delete nodeToDelete;
}

void BinaryTree::destorySubtree(TreeNode* tree){
    if(tree == NULL) return;
    destorySubtree(tree->llink);
    destorySubtree(tree->rlink);
    delete tree;
}

void BinaryTree::displayInOrder(TreeNode* tree){
    if(tree!=NULL){
        displayInOrder(tree->llink);
        cout << tree->value << " ";
        displayInOrder(tree->rlink);
    }
}

void BinaryTree::displayPreOrder(TreeNode* tree){
    if(tree!=NULL){
        cout << tree->value << " ";
        displayPreOrder(tree->llink);
        displayPreOrder(tree->rlink);
    }
}

void BinaryTree::displayPostOrder(TreeNode* tree){
    if(tree!=NULL){
        displayPostOrder(tree->llink);
        displayPostOrder(tree->rlink);
        cout << tree->value << " ";
    }
}

bool BinaryTree::search(int num){
    TreeNode* t = root;

    while(t!=NULL){
        if(t->value == num)
            return true;
        else if(num < t->value)
            t = t->llink;
        else
            t = t->rlink;
    }
    return false;
}

int main(){
    BinaryTree t1;
    t1.insert(5);
    t1.insert(8);
    t1.insert(3);
    t1.insert(12);
    t1.insert(9);

    t1.ShowInOrder();
    cout << endl;
    t1.remove(8);
    t1.ShowInOrder();

    return 0;
}
