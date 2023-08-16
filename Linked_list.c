#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
 
typedef struct Node
{
    uint8_t value;
    struct Node *ptrnext;
    
} My_node;


My_node *createnode(uint8_t value){
    My_node *ptr = (My_node*)malloc(sizeof(My_node));
    ptr->ptrnext = NULL;
    ptr->value = value;
    return ptr;
}

// Return the value of the first element in the list
uint8_t front(My_node *array){
    if (array->ptrnext == NULL){
        printf("Linked list is empty!");
    }else{
        return array->value;
    }
}

// Return the value of the last element in the list
uint8_t back(My_node *array){
    if(array == NULL){
        printf("Linked list is empty!\n");
        return array->value = 0;
    }else{
        while (array->ptrnext != NULL){
            array = array->ptrnext;
        }
        return array->value;
    }
}

// add a new element in the begining of the list
void push_front(My_node **array, uint8_t value){
    if (*array == NULL){
        *array = createnode(value);
    }else{
        My_node *temp = createnode(value);
        temp->ptrnext = *array;
        *array = temp;
    }
}

// add a new element in the end of the list
void push_back(My_node **array, uint8_t value){
    if (*array == NULL){
        *array = createnode(value);
    }else{
        My_node *ptp = *array;
        while (ptp->ptrnext != NULL)
        {
            ptp = ptp->ptrnext;
        }
        ptp->ptrnext = createnode(value);
        
    }
}

// Remove the first element of the list and reduce the size of the list by 1
void pop_font(My_node **array){
    My_node *ptr = *array;
    *array = (*array)->ptrnext;
    free(ptr);
}

// Remove the last element of the list and reduce the size of the list by 1
void pop_back(My_node **array){
    if (*array == NULL){
        printf("Linked list is empty!");
    }else{
        My_node *ptp = *array;
        while (ptp->ptrnext != NULL)
        {
            if (ptp->ptrnext->ptrnext == NULL){
                free(ptp->ptrnext);
                ptp->ptrnext = NULL;
                return;                 //why put return here
            }
            ptp = ptp->ptrnext;
        }
    }
}

// Remove the last element at specified position of the list and reduce the size of the list by 1
void eraser(My_node **array, uint8_t index){
    if(*array == NULL){
        printf("Linked list is empty!\n");
    }else if (index == 1)
    {
        pop_font(&(*array));
    }else{
        My_node *ptp = *array;
        uint8_t count = 0;
        while (ptp->ptrnext != NULL && count != (index - 2))
        {
            ptp = ptp->ptrnext;
            count++;
        }
        My_node *ptpp = ptp->ptrnext;
        ptp->ptrnext = ptp->ptrnext->ptrnext;
        free(ptpp);

    }
}

// Return the number of elements in the list
uint8_t size(My_node *array){
    uint8_t size = 0;
    if (array == NULL){
        size = 0;
    }else{
        while (array->ptrnext != NULL)
        {
            size++;
            array = array->ptrnext;
        }
        size++;
    }
    return size;
}

//Insert new element in the list before the element at specified position
void insert(My_node **array, uint8_t value, uint8_t index){
    if(*array == NULL || index == 1){
        push_front(&(*array), value);
    }else{
        My_node *temp = createnode(value);
        My_node *ptp = *array;
        uint8_t count = 0;
        while (ptp->ptrnext != NULL && count != (index-2))
        {
            ptp = ptp->ptrnext;
            count++;
        }
        temp->ptrnext = ptp->ptrnext;
        ptp->ptrnext = temp;
        
    }
}

// Return value of all elements in the list
void print_all(My_node *array){
    if(array == NULL){
        printf("Linked list is empty!\n");
    }else{
    while (array->ptrnext != NULL){
        printf("%d\n", array->value);
        array = array->ptrnext;
    }
    printf("%d\n", array->value);
    }
}

// Function return an iterator pointing to the first element of the list
My_node *begin(){}

// Function return an iterator pointing to the theoreticaal last element of the list
My_node *end(My_node *array){
    if (array == NULL){
        return 0;
    }else{
        while (array->ptrnext != NULL)
        {
            array = array->ptrnext;
        }
        return array;
    }
}

// Return the value of the element at specified position
uint8_t get(My_node *array, uint8_t index){
    if (array == NULL){
        return array->value = 0;
    }else{
        uint8_t count = 0;
        while (array != NULL && count != (index - 1))
        {
            array = array->ptrnext;
            count++;
        }
        return array->value;
    }
}

int main(int argc, char const *argv[])
{
    uint8_t var_node = 0;
    My_node *array = NULL;
    push_back(&array, 1);
    push_back(&array, 2);
    push_back(&array, 3);
    push_back(&array, 4);
    push_back(&array, 5);
    push_back(&array, 6);
    push_back(&array, 7);
    print_all(array);
    printf("\n");
    eraser(&array, 1);
    print_all(array);

    

    return 0;
}

