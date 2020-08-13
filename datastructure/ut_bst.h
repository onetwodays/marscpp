//
// Created by zh on 2020/8/5.
//二叉树算法设计的总路线：把当前节点要做的事做好，其他的交给递归框架，不用当前节点操心
//如果当前节点会对下面的子节点有整体影响，可以通过辅助函数增长参数列表，借助参数传递信息
/*

root = [10,5,-3,3,2,null,11,3,-2,null,1],
sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
int pathSum(TreeNode root, int sum) {
    if (root == null) return 0;
    int pathImLeading = count(root, sum); // 自己为开头的路径数
    int leftPathSum = pathSum(root.left, sum); // 左边路径总数（相信他能算出来）
    int rightPathSum = pathSum(root.right, sum); // 右边路径总数（相信他能算出来）
    return leftPathSum + rightPathSum + pathImLeading;
}
int count(TreeNode node, int sum) {
    if (node == null) return 0;
    // 我自己能不能独当一面，作为一条单独的路径呢？
    int isMe = (node.val == sum) ? 1 : 0;
    // 左边的小老弟，你那边能凑几个 sum - node.val 呀？
    int leftBrother = count(node.left, sum - node.val);
    // 右边的小老弟，你那边能凑几个 sum - node.val 呀？
    int rightBrother = count(node.right, sum - node.val);
    return  isMe + leftBrother + rightBrother; // 我这能凑这么多个
}
 */

#ifndef MARSC___UT_BST_H
#define MARSC___UT_BST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct bst_node {
    int data;
    struct bst_node* left;
    struct bst_node* right;
} bst_node;

bst_node* bst_find(bst_node* root,int data);
bst_node* bst_find1(bst_node* root,int data);
bst_node* bst_find_min(bst_node* root);
bst_node* bst_find_min1(bst_node* root);
bst_node* bst_find_max(bst_node* root);
bst_node* bst_find_max1(bst_node* root);
bst_node* bst_insert(bst_node* root,int data);
bst_node* bst_inser1(bst_node* root,int data);
bst_node* bst_delete(bst_node* root,int data);
bst_node* bst_delete1(bst_node* root,int data);
bst_node* bst_find_lca(bst_node* root,bst_node* a, bst_node* b); //找a，b最近的共同祖先
void traverse(bst_node* root);
bool bst_is_valid(bst_node* root);
bst_node* find_LCA(bst_node* root,bst_node*a, bst_node* b);




#ifdef __cplusplus
}
#endif

#endif //MARSC___UT_BST_H
