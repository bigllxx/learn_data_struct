// 结点之间的路径：只能从上往下走
// 结点的度：该结点的子结点（分支）数量。 叶子结点的度=0
// 树的度：该树中所有结点的 max{度}
// 有序树：各结点顺序是有次序的，不能互换
// 无序树：各结点顺序是无次序的，可以互换
// 森林：m棵 互不相交 的树的集合；；  树和森林的转换
// 操作：遍历化、线索化、最优化、转换化

// 考点1：结点数 = 总度数 + 1
// 考点2：度为 m的树、m叉树的区别；   3叉树：任一结点最多只能有3个子结点
// 考点3：度为 m的树 && m叉树，第 i层最多有 m^(i-1) 个结点
// 考点4：高度为 h的 m叉树，最多有(m^h - 1)/(m-1) 个结点； 等比数列求和
// 考点5：高度为 h的 m叉树，至少有 h个结点； 高度为 h，度为 m的树，至少有 h+m-1个结点
// 考点6：具有 n个结点的 m叉树，最小高度为 logm [n(m-1)+1]


# include <iostream>
# include <stddef.h> 
typedef int ElemType;
# define MaxSize 10

// 顺序存储  对于顺序存储，按下标来区分元素在树中的位置，因此会浪费很多存储空间
struct TreeNode{
    ElemType value;  // 数据域
    bool isEmpty;  // 结点是否为空
};
// 初始化
int InitTreeNode(){
    TreeNode t[MaxSize];  // 定义一个长度为MaxSize的数组t，按照从上至下，从左至右的顺序一次存储完全二叉树中的各结点
    for(int i=0; i<MaxSize; i++){
        t[i].isEmpty=true;  // 初始化的，所有结点标记为 空
    }
    return 0;
}


// 链式存储
typedef struct BiTNode{
    char data; // 数据域
    struct BiTNode *lchild, *rchild;  // 左右孩子指针
}BiTNode, *BiTree;

// 初始化
int InitBiTNode(BiTree &root){
    // BiTree root=NULL;  // 定义一颗空树

    // 插入根结点
    root = new BiTNode;  // 申请一个结点root
    root->data = 1;  // root的数据域赋值为 1
    root->lchild = NULL;  // root的左孩子指针为NULL
    root->rchild = NULL;  // root的右孩子指针为NULL
    return 0;
}


// 遍历，产生一个关于结点的线性序列，每个节点访问且只访问一次
// 7种次序：先序DLR、中序LDR、后序LRD、逆先序DRL、逆中序RDL、逆后序RLD、按层遍历。前三个是重点


