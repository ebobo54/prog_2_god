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

struct item *insert_to_list (struct item*lst, int index)
{
struct item *tmp;
tmp = malloc(sizeof(struct item));
tmp->value = val;
tmp->next = head->next;

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

