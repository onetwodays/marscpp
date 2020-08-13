//
// Created by zh on 2020/8/5.
//
#include <stdlib.h>
#include <stdbool.h>

//BST的节点数据域都是不一样的

#include "ut_bst.h"
/*
  void plusOne(TreeNode root) {
    if (root == null) return;
    root.val += 1;

    plusOne(root.left);
    plusOne(root.right);
}

 boolean isSameTree(TreeNode root1, TreeNode root2) {
    // 都为空的话，显然相同
    if (root1 == null && root2 == null) return true;
    // 一个为空，一个非空，显然不同
    if (root1 == null || root2 == null) return false;
    // 两个都非空，但 val 不一样也不行
    if (root1.val != root2.val) return false;

    // root1 和 root2 该比的都比完了
    return isSameTree(root1.left, root2.left)
        && isSameTree(root1.right, root2.right);
}

 */
void traverse(bst_node* root){
    //root需要做什么？在这做
    traverse(root->left);
    traverse(root->right);
}
// BST 的定义，root 需要做的不只是和左右子节点比较，而是要整个左子树和右子树所有节点比较
bool bst_is_valid(bst_node* root){
    if(root==NULL) return true;
    if(root->left && !(bst_find_max(root->left)->data<root->data))   return false;
    if(root->right && !(root->data<bst_find_min(root->right)->data)) return false;
    return bst_is_valid(root->left) && bst_is_valid(root->right);
}
bst_node* bst_find(bst_node* root,int data){
    if(root){
        if(data==root->data){
            return root;
        }else if(data<root->data){
            return bst_find(root->left,data);

        }else if(data>root->data){
            return  bst_find(root->right,data);
        }
    }else{
        return NULL;
    }
}
bst_node* bst_find1(bst_node* root,int data){

    while (root){
        if(data==root->data) return root;
        else if (data<root->data){
            root = root->left;
        }else if(data>root->data){
            root = root->right;
        }
    }
    return NULL;


}
bst_node* bst_find_min(bst_node* root){
    if(!root){
        return NULL;
    }
    if(root->left==NULL){
        return root;
    }
    return bst_find_min(root->left);

}
bst_node* bst_find_min1(bst_node* root){
    if(!root) return NULL;

    while ( root->left){
        root=root->left;
    }
    return root;

}
bst_node* bst_find_max(bst_node* root){
    if(!root) return NULL;
    if (root->right==NULL){
        return root;
    }
    return bst_find_max(root->right);

}
bst_node* bst_find_max1(bst_node* root){
    if(root==NULL) return NULL;
    while (root->right!=NULL){
        root=root->right;
    }
    return root;

}
//一定插到叶子节点
bst_node* bst_insert(bst_node* root,int data){

    if(!root){
        bst_node* new_node = (bst_node*)malloc(sizeof(bst_node));
        if(new_node==NULL){
            return NULL;
        }
        new_node->data = data;
        new_node->left=new_node->right=NULL;
        root=new_node;
    }else if (data<root->data) {
        root->left= bst_insert(root->left,data);//太妙了啊，把该节点返回给上一层都得到更新
    }else if(data>root->data){
        root->right= bst_insert(root->right,data);
    }
    return root;

}

bst_node* bst_inser1(bst_node* root,int data) {

    bst_node *new_node = (bst_node *) malloc(sizeof(bst_node));
    if (new_node == NULL) {
        return NULL;
    }

    if (!root) {

        new_node->data = data;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    bool flag_left = true;

    while (root) {
        if (data == root->data) {
            free(new_node);
            return root;
        } else if (data < root->data) {
            if (root->left == NULL) {
                break;
            } else {
                root = root->left;
            }


        } else if (data > root->data) {
            if (root->right == NULL) {
                flag_left = false;
            } else {
                root = root->right;
            }
        }

    }
    if(flag_left){
        root->left=new_node;
    } else{
        root->right = new_node;
    }
}



bst_node* bst_delete(bst_node* root,int data){
    if(!root) return NULL;
    else if (data<root->data){
        root->left=bst_delete(root->left,data);
    } else if (data>root->data){
        root->right=bst_delete(root->right,data);
    }else{
        if(root->left && root->right){ //要删除的节点有2个字节点，必须找到左子树中最大的节点或者右子树中最小的那个节点来接替自己
            bst_node* temp = bst_find_max(root->left);
            root->data=temp->data;
            root->left =bst_delete(root->left,root->data);
        }else{
            bst_node* temp=root;
            if(root->left==NULL){
                root=root->right;
            }else if(root->right==NULL){
                root = root->left;
            }
            free(temp);
        }
    }
    return root;

}

bst_node* bst_delete1(bst_node* root,int data){
    if(root==NULL) return NULL;
    bst_node* parent = NULL;
    bool is_left = true;
    while (root){

        if(data<root->data){
            parent=root;
            root=root->left;
        }else if(data>root->data){
            parent=root;
            root=root->right;
            is_left=false;
        }else{
            break;
        }
    }
    if(root==NULL) return NULL;
    if(root->left==NULL && root->right==NULL){ //是叶子节点
        if(is_left){ parent->left=NULL;}else{ parent->right=NULL;}
        return root;
    }
    //有一个叶子节点
    if(root->left!=NULL && root->right==NULL){
        parent->left = root->left;
        return root;
    }else if(root->left==NULL && root->right!=NULL){
        parent->right=root->right;
        return root;
    }

    //有2个叶子节点
    bst_node* temp= root;

    bst_node* temp_parent=NULL;
    while (temp->right!=NULL){
        temp_parent=temp;
        temp=temp->right;
    }
    //temp 是左子树的最大值
    root->data=temp->data;
    //现在转变成删除temp了,temp 是叶子节点，有一个左叶子节点
    if(temp->right==NULL&& temp->left==NULL){
        temp_parent->left=temp_parent->right==NULL;

    }

    if(temp->right==NULL && temp->left!=NULL){
        temp_parent->left=temp->left;
    }
    return temp;

}

bst_node* bst_find_lca(bst_node* root,bst_node* a, bst_node* b){
    //a.data<=root.data<<b.data
    while (1){
        if((a->data<=root->data && root->data>=b->data) || (a->data>=root->data && root->data<=b->data)){
            return root;
        }
        if(a->data<root->data){
            root=root->left;
        }
        if(b->data>root->data){
            root=root->right;
        }

    }
}

bst_node* find_LCA(bst_node* root,bst_node*a, bst_node* b){
    if(root==NULL) return root;
    if(a==root) return b;
    if(b==root) return a;
    bst_node* left_lac = find_LCA(root->left,a,b);
    bst_node* right_lac= find_LCA(root->right,a,b);
    if(left_lac && right_lac){
        return root;
    }
    return left_lac?left_lac:right_lac;

}