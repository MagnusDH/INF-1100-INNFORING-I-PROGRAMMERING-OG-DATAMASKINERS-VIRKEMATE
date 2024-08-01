#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
 * List implementation
 */

typedef struct listnode listnode_t;

struct listnode {
    listnode_t  *next;
    void        *item;
};

struct list {
    listnode_t *head;
    int numitems;
};

/*
 * Returns a newly created, empty list.
 */
list_t *list_create(void)
{
    /* Implement me */
    list_t *new_list = malloc(sizeof(list_t));
    if(new_list == NULL){
        return NULL;
    }

    new_list->head = NULL;
    new_list->numitems = 0;

    return new_list;
}

/*
 * Frees the list; list and nodes, but not the items it holds.
 */
void list_destroy(list_t *list)
{
    /* Implement me */
    listnode_t *current = list->head;
    listnode_t *tmp = NULL;

    while(current != NULL){
        tmp = current;
        current = current->next;
        free(tmp);
    }

    list->head = NULL;
    free(list);
}

/*
 * Adds an item first in the provided list.
 */
void list_addfirst(list_t *list, void *item)
{
    /* Implement me */
    listnode_t *node = malloc(sizeof(listnode_t));
    if(node == NULL){
        return;
    }

    node->item = item;
    node->next = list->head;
    list->head = node;
    list->numitems ++;
}

/*
 * Adds an item last in the provided list.
 */
void list_addlast(list_t *list, void *item)
{
    /* Implement me */
    listnode_t *current = list->head;

    listnode_t *last = malloc(sizeof(listnode_t));
    if(last == NULL){
        return;
    }

    if(list->numitems == 0){
        list_addfirst(list, item);
    }

    if((list->numitems == 1)){
        list->head->next = last;
        last->next = item;
        list->numitems++;
    }

    while(current != NULL){
        if(current->next == NULL){
            current->next = last;
            last->next = NULL;
            last->item = item;
            list->numitems++;
        }
        current = current->next;
    }
}

/*
 * Removes an item from the provided list, only freeing the node.
 */
void list_remove(list_t *list, void *item)
{
    /* Implement me */
    listnode_t *current = list->head;
    listnode_t *previous = NULL;

    while(current != NULL){
        if(current->item == item){
            if(previous != NULL){
                previous->next = current->next;
            }
            else{
                list->head = current->next;
            }
            break;
        }
        previous = current;
        current = current->next;
    }
    if(current != NULL){
        free(current);
        list->numitems--;
    }
}

/*
 * Return the number of items in the list.
 */
int list_size(list_t *list)
{
    /* Implement me */
    return list->numitems;
}



/*
 * Iterator implementation
 */
struct list_iterator {
    listnode_t *next;
    list_t *list;
};


/*
 * Return a newly created list iterator for the given list.
 */
list_iterator_t *list_createiterator(list_t *list)
{
    /* Implement me */
    list_iterator_t *iter = malloc(sizeof(list_iterator_t)); 
    if (iter == NULL){
        return NULL;
    }

    iter->next = list->head; 
    iter->list = list; 

    return iter;
}


/*
 * Free the memory for the given list iterator.
 */
void list_destroyiterator(list_iterator_t *iter)
{
    /* Implement me */
    free(iter);
}


/*
 * Move iterator to next item in list and return current.
 */
void *list_next(list_iterator_t *iter)
{
    /* Implement me */
    if(iter->next == NULL){ 
        return NULL;
    }

    void *item = iter->next->item; 
    iter->next = iter->next->next; 

    return item;
}


/*
 * Let iterator point to first item in list again.
 */
void list_resetiterator(list_iterator_t *iter)
{
    /* Implement me */
    iter->next = iter->list->head;
}
