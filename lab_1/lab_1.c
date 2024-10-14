#include <stdlib.h>
#include <stdio.h>

struct node {
    int val;
    struct node *left, *right;
};

void bin_tree_print(struct node *root)
{
    if(!root)
       return;
     bin_tree_print(root->left);
     printf("  %d   ", root->val);
     bin_tree_print(root->right);    
}    

void bin_tree_add(struct node **root, int val)
{
    if(!*root) {
        *root = malloc(sizeof(struct node));
        (*root)->val = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }
    if((*root)->val == val)
        return;
    if(val < (*root)->val)
        bin_tree_add(&(*root)->left, val);
    else
        bin_tree_add(&(*root)->right, val);
}    

int main()
{  
   struct node *root = NULL;
   bin_tree_add(&root, 27);
   bin_tree_print(root);
   printf("\n");
   bin_tree_add(&root, 18);
   bin_tree_print(root);
   printf("\n");   
   bin_tree_add(&root, 34);
   bin_tree_print(root);
   printf("\n");   
   bin_tree_add(&root, 4);
   bin_tree_print(root);
   printf("\n");   
   bin_tree_add(&root, 21);
   bin_tree_print(root);
   printf("\n");   
   bin_tree_add(&root, 29);
   bin_tree_print(root);
   printf("\n");   
   bin_tree_add(&root, 39);
   bin_tree_print(root);
   printf("\n");
   return 0;   
}    


 
