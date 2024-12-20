# lab_3
 
 ---
# Лабораторная работа №3
 ## Задание 
Реализовать операцию удаления узла из бинарного дерева поиска. Необходимо учесть три
возможных случая:
1. у удаляемого узла нет дочерних узлов,
2. у удаляемого узла есть только один дочерний узел,
3. у удаляемого узла два дочерних узла.
После выполнеия операции удаления узла бинарное дерево поиска должно сохранить свое
свойство: если x — узел бинарного дерева с ключом k, то все узлы в левом поддереве должны
иметь ключи, меньшие k, а в правом поддереве большие k. 

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {


        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }


        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

Node* insertNode(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("deleting a node from a binary tree:\n");
    inOrderTraversal(root);
    printf("\n");

    root = deleteNode(root, 20);
    printf("the node being deleted has no child nodes:\n");
    inOrderTraversal(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("a node that is being deleted has only one child node:\n");
    inOrderTraversal(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("the node being deleted has two child nodes:\n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
```

![](Q.png)

1. [Markdown Cheat Sheet](https://www.markdownguide.org/cheat-sheet/)
