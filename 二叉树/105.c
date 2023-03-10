// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//方法一：递归法
//1,前序遍历：根节点-左支-右支
//2,中序遍历：左支-根节点-右支
//3,从前序遍历数组中取得根节点,并计算左支节点数和右支节点数
//4,递归处理左支、右支
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    int     i           = 0;
    int     iRootval    = 0;
    int     iLeftNum    = 0;
    int     iRightNum   = 0;
    struct TreeNode*     pTreeNode  = NULL;

    //1,结束条件
    if((0 == preorderSize) || (0 == inorderSize)) return NULL;
    if((NULL == preorder) || (NULL == inorder)) return NULL;
    if(preorderSize != inorderSize) return NULL;

    //2,初始化
    pTreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    memset(pTreeNode, 0x00, sizeof(struct TreeNode));
    iRootval = preorder[0];

    //3,计算左支节点数，右支节点数
    for(i = 0; i < inorderSize; i++)
    {
        if(iRootval == inorder[i])
        {
            break;
        }
        iLeftNum += 1;
    }
    iRightNum = inorderSize - iLeftNum - 1;

    //4,递归处理左支、右支
    pTreeNode->val = iRootval;
    pTreeNode->left = buildTree(&preorder[1], iLeftNum, &inorder[0], iLeftNum);
    pTreeNode->right = buildTree(&preorder[1 + iLeftNum], iRightNum, &inorder[1 + iLeftNum], iRightNum);
    return pTreeNode;
}
