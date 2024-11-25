# lab_1
 
 ---

 ## Задание
На языке С написать функцию вставки нового элемента в односвязный список по
индексу. Реализовать один из двух возможных вариантов вставки: вставка перед или после
текущего элемента, где текущий элемент определяется по заданным индексом.
```c
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


void delete_element_list(struct item **pcur, int num)
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

int main()
{
  int arr[] = {1, -2, 3, -4, 5};
  int size = sizeof(arr) / sizeof(*arr);
  struct item *lst = array_to_list(arr, size);
  
  print_list(lst);
  
  delete_element_list(&lst, 1);
  print_list(lst);
  
  delete_element_list(&lst, 3);
  print_list(lst);
  
  return 0;
}

```
![](Q.jpg)
1. [Markdown Cheat Sheet](https://www.markdownguide.org/cheat-sheet/)
