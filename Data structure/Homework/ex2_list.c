#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
   Print List
*/
/*
Los cambios realizados fueron el cambio de tipo de dato del apuntador *data y su asignaci�n de memoria din�mica
la funci�n imprime
y un par de asignaciones en ls �ltimas lineas
*/
static void print_list (const List *list) {
    ListNode *node;
    char *data;
    int i;

    fprintf(stdout, "List size is %d\n", list_size(list));

    i = 0;
    node = list_head(list);

    while (1) {
        data = list_data(node);
        fprintf(stdout, "list.node[%03d]='%c', %p -> %p \n", i, *data, node, node->next);

        i++;

        if (list_is_tail(node))
            break;
        else
            node = list_next(node);
    }

    return;
}

int main (int argc, char **argv) {
    List list;
    ListNode *node;
    char *data;
    int i;

    list_init(&list, free);

    // Insertar las 27 letras del alfabeto ingl�s (A-Z y espacio)
    for (i = 0; i < 27; i++) {
        if ((data = (char *)malloc(sizeof(char))) == NULL)
            return 1;

        *data = (i < 26) ? ('A' + i) : ' ';  // �ltimo car�cter es espacio

        if (list_ins_next(&list, NULL, data) != 0)
            return 1;
    }

    print_list(&list);

    node = list_head(&list);
    for (i = 0; i < 7; ++i)
        node = list_next(node);

    data = list_data(node);
    fprintf(stdout, "\nRemoving a node after the one containing '%c'\n", *data);

    if (list_rem_next(&list, node, (void**)&data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nInserting 'X' at the tail of the list\n");
    *data = 'X';
    if (list_ins_next(&list, list_tail(&list), data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nRemoving a node after the first node\n");
    if (list_rem_next(&list, list_head(&list), (void**)&data) != 0)
        return 1;
    print_list(&list);

    fprintf(stdout, "\nRemoving a node at the head of the list\n");
    if (list_rem_next(&list, NULL, (void**)&data) != 0)
        return 1;
    print_list(&list);    

    fprintf(stdout, "\nInsert 'Z' at the head of the list\n");
    *data = 'Z';
    if (list_ins_next(&list, NULL, data) != 0)
        return 1;
    print_list(&list);    

    fprintf(stdout, "\nIterating and removing the fourth node\n");
    node = list_head(&list);
    node = list_next(node);
    node = list_next(node);

    if (list_rem_next(&list, node, (void **)&data) != 0)
        return 1;

    print_list(&list);

    fprintf(stdout, "\nInserting 'A' after the first node\n");
    *data = 'A';
    if (list_ins_next(&list, list_head(&list), data) != 0)
        return 1;
    print_list(&list);

    i = list_is_head(&list, list_head(&list));
    fprintf(stdout, "\nTesting list_is_head... value=%d (1=OK)\n", i);
    i = list_is_head(&list, list_tail(&list));
    fprintf(stdout, "Testing list_is_head... value=%d (1=OK)\n", i);
    i = list_is_tail(list_tail(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);
    i = list_is_tail(list_head(&list));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);

    fprintf(stdout, "\nDestroying the list\n");
    list_destroy(&list);

    return 1;
}

