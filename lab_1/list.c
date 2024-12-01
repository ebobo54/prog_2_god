// #include <stdlib.h>
// #include <stdio.h>

// struct item {
//   int data;
//   struct item *next;
// };

// void print_list(const struct item *lst)
// {
//   printf("list: ");
//   for(; lst; lst = lst->next)
//     printf("%d ", lst->data);
//   printf("\n");
// }

// struct item *array_to_list(int *arr, int size)
// {
//   struct item *tmp;
//   if(!size)
//     return NULL;
//   tmp = malloc(sizeof(struct item));
//   tmp->data = *arr;
//   tmp->next = array_to_list(arr + 1, size - 1);
//   return tmp;
// }


// void delete_element_list(struct item **pcur, int num)
// {
//   int counter = 1;
//   while(*pcur) {  
//     if(num == counter) {
//       struct item *tmp = *pcur; 
//       *pcur = (*pcur)->next;
//       free(tmp);
//       break;
//     } else {
//         pcur = &(*pcur)->next;
//         counter++;
//     }
//   }
// }

// int main()
// {
//   int arr[] = {1, -2, 3, -4, 5};
//   int size = sizeof(arr) / sizeof(*arr);
//   struct item *lst = array_to_list(arr, size);
  
//   print_list(lst);
  
//   delete_element_list(&lst, 1);
//   print_list(lst);
  
//   delete_element_list(&lst, 3);
//   print_list(lst);
  
//   return 0;
// }
// #include <stdlib.h>
// #include <stdio.h>

// struct node {
//     int val;
//     struct node *left, *right;
// };

// void bin_tree_print(struct node *root)
// {
//     if(!root)
//        return;
//      bin_tree_print(root->left);
//      printf("  %d   ", root->val);
//      bin_tree_print(root->right);    
// }    

// void bin_tree_add(struct node **root, int val)
// {
//     if(!*root) {
//         *root = malloc(sizeof(struct node));
//         (*root)->val = val;
//         (*root)->left = NULL;
//         (*root)->right = NULL;
//         return;
//     }
//     if((*root)->val == val)
//         return;
//     if(val < (*root)->val)
//         bin_tree_add(&(*root)->left, val);
//     else
//         bin_tree_add(&(*root)->right, val);
// }    

// int main()
// {  
//    struct node *root = NULL;
//    bin_tree_add(&root, 27);
//    bin_tree_print(root);
//    printf("\n");
//    bin_tree_add(&root, 18);
//    bin_tree_print(root);
//    printf("\n");   
//    bin_tree_add(&root, 34);
//    bin_tree_print(root);
//    printf("\n");   
//    bin_tree_add(&root, 4);
//    bin_tree_print(root);
//    printf("\n");   
//    bin_tree_add(&root, 21);
//    bin_tree_print(root);
//    printf("\n");   
//    bin_tree_add(&root, 29);
//    bin_tree_print(root);
//    printf("\n");   
//    bin_tree_add(&root, 39);
//    bin_tree_print(root);
//    printf("\n");
//    return 0;   
// }    

#include <stdlib.h>
#include <stdio.h>

struct item {
  int data;
  struct item *next;
};

void print_list(const struct item *lst)
{
  printf("list: ");
  for(; lst; lst = lst->next)
    printf("%d ", lst->data);
  printf("\n");
}

struct item *array_to_list(int *arr, int size)
{
  struct item *tmp;
  if(!size)
    return NULL;
  tmp = malloc(sizeof(struct item));
  tmp->data = *arr;
  tmp->next = array_to_list(arr + 1, size - 1);
  return tmp;
}


void delete_item_list(struct item **pcur, int num)
{
  int counter = 1;
  while(*pcur) {  
    if(num == counter) {
      struct item *tmp = *pcur;
      *pcur = (*pcur)->next;
      free(tmp);
      break;
    } else {
        pcur = &(*pcur)->next;
        counter++;
    }
  }
}

void insert_item_list(struct item **pcur, int index, int data)
{
  int counter = 1;

  while(*pcur) {  
    if(index == counter) {
      struct item *tmp = malloc(sizeof(struct item));
      tmp->data = data;
      tmp->next = *pcur;
      *pcur = tmp;
      break;
    } else {
        pcur = &(*pcur)->next;
        counter++;
    }
  }
}


int main()
{
  int arr[] = {1, 2, 3};
  int size = sizeof(arr) / sizeof(*arr);
  struct item *lst = array_to_list(arr, size); 
  print_list(lst);
  insert_item_list(&lst, 3, 9);
  print_list(lst);
  return 0;
}
