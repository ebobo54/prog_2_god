
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
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertBefore(Node** head, int index, int newData) {
    if (index < 0) {
        printf("Индекс должен быть >= 0\n");
        return;
    }

    Node* newNode = createNode(newData);

    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    Node* prev = NULL;
    int currentIndex = 0;

    while (current != NULL && currentIndex < index) {
        prev = current;
        current = current->next;
        currentIndex++;
    }

    if (currentIndex != index) {
        printf("Индекс вне границ списка\n");
        free(newNode);
        return;
    }

    prev->next = newNode;
    newNode->next = current;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("list: ");
    printList(head);

    insertBefore(&head, 1, 15);
    printf("15 before index 1: ");
    printList(head);

    insertBefore(&head, 0, 5);
    printf("5 before index 0: ");
    printList(head);
    return 0;
}
