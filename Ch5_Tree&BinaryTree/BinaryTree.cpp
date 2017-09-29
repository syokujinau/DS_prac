#include <iostream>
using namespace std;

class BinaryTree{
private:
    /*定義二元樹節點型態*/
    class TreeNode{
        friend class BinaryTree;
        int value;
        TreeNode *llink;//左子點指標
        TreeNode *rlink;//右子點指標
        //建構子
        TreeNode(int v,TreeNode *l = NULL, TreeNode *r = NULL){
            value = v;
            llink = l;
            rlink = r;
        }
    };
    /*宣告節點指標，指向root*/
    TreeNode *root;
    
    void insert(TreeNode*& tree, int num); //插入新節點 
    void destorySubtree(TreeNode*); //刪除子樹 
    void remove(TreeNode*& tree, int num); //刪除指定鍵值
    void makeDeletion(TreeNode*& tree); //remove的副函式
    void displayInOrder(TreeNode* tree); 
    void displayPreOrder(TreeNode* tree);
    void displayPostOrder(TreeNode* tree);

public:
    BinaryTree(){ //建構子
        root = NULL;
    }
    ~BinaryTree(){ //解構子
        destorySubtree(root);
    }
    void insert(int num){
        insert(root,num);
    }
    void remove(int num){
        cout << "Removing "<< num <<"...\n"; 
        remove(root, num);
    }
    void ShowInOrder(void){
        cout << "Inorder :\n";
        displayInOrder(root);
        cout << endl;
    }
    void ShowPreOrder(void){
        cout << "Preorder :\n";
        displayPreOrder(root);
        cout << endl;
    }
    void ShowPostOrder(void){
        cout << "Postorder :\n";
        displayPostOrder(root);
        cout << endl;
    }
    bool search(int num); //判斷是否num存在

};

void BinaryTree::insert(TreeNode* &tree, int num){
    //case1: 空樹
    //配置TreeNode型態記憶體空間並讓傳入的TreeNode指標指著
    if(tree == NULL){ 
        tree = new TreeNode(num);
        return; //結束本函式
    }
    
    //在搜尋適當位置的過程中發現已存在該鍵值則結束
    if(tree->value == num){
        return;//結束本函式
    }
    //case2: 非空樹，插入到適當位置 (遞迴呼叫)
    if(num < tree->value){ //比root小，往左子樹
        insert(tree->llink, num);
    }
    else { //比root大，往右子樹
        insert(tree->rlink, num);
    }
}

void BinaryTree::remove(TreeNode* &tree, int num){//從樹根開始搜尋指定鍵值並刪除
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
    //case3: num == tree->value 找到指定鍵值
    else{
        makeDeletion(tree);
    }
}

void BinaryTree::makeDeletion(TreeNode* &tree){ 
    TreeNode* nodeToDelete = tree;
    //case1: 該點沒有右子點
    if(tree->rlink == NULL){ 
        tree = tree->llink; //傳入的指標參照指向左子樹
    }
    //case2: 該點沒有左子點
    else if(tree->llink == NULL){ 
        tree = tree->rlink; //傳入的指標參照指向右子樹
    }
    //case3: 該點的左右子點都存在  (圖示:https://goo.gl/qtFyFr)
    else{ //找右子樹最小值(也可以採用左子樹最大值)
        TreeNode* attachPoint = tree->rlink;
        while(attachPoint->llink != NULL){ //一直往左走到底
            attachPoint = attachPoint->llink;
        }//while迴圈結束，此時attachPoint會指向右子樹最小值
        attachPoint->llink = tree->llink;       
        tree               = tree->rlink; //指向新樹根
    }
    //若該點為樹葉，以上條件判斷皆不成立
    
    delete nodeToDelete;  
}

void BinaryTree::destorySubtree(TreeNode* tree){//刪除子樹，傳入該子樹之root指標
    if(tree == NULL){ 
      return;
    }else{
      destorySubtree(tree->llink);
      destorySubtree(tree->rlink);
    }
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
    int data[]={36,25,39,50,40,65,60,62};
    for(int i = 0; i < sizeof(data)/sizeof(int); i++){
      t1.insert(data[i]);
    }
  
    t1.ShowPreOrder();
    t1.ShowInOrder();
    t1.remove(50);
    t1.ShowPreOrder();
    t1.ShowInOrder();
    
    if(t1.search(12)){
      cout << "12 存在\n";
    }else{
      cout << "12 不存在\n";
    }
    if(t1.search(60)){
      cout << "60 存在\n";
    }else{
      cout << "60 不存在\n";
    }

    return 0;
}
