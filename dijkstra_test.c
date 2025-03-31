#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#include "dijkstra.h"

#define TESTNODES 8
#define INFINITY UINT_MAX

EDGE_T *add(EDGE_T **list, NODE_T *node, int weight) 
{
    EDGE_T *edge = (EDGE_T *)malloc(sizeof(EDGE_T));
    assert(edge);
    edge->weight = weight;
    edge->node = node;

    if (*list == NULL) {
        *list = edge;  
    }
    else {
        edge->next = *list;
        *list = edge;
    }
    return edge;
}

void setup_testenv(NODE_T testenv[TESTNODES])
{
    char name[] = "A";
    int i;
    for (i = 0; i < TESTNODES; i++) {
        strcpy(testenv[i].id, name);
        testenv[i].edges = NULL;
        testenv[i].label.sum_weight = INFINITY;
        testenv[i].label.next_hop = NULL;
        testenv[i].label.status = UNDEFINED;
        name[0]++;
    }
    add(&testenv[0].edges, &testenv[2], 2);
    add(&testenv[0].edges, &testenv[1], 1);    

    add(&testenv[1].edges, &testenv[5], 4);    
    add(&testenv[1].edges, &testenv[4], 3);    
    add(&testenv[1].edges, &testenv[3], 2);    
    add(&testenv[1].edges, &testenv[0], 1);    
    
    add(&testenv[2].edges, &testenv[4], 1);    
    add(&testenv[2].edges, &testenv[0], 2);    

    add(&testenv[3].edges, &testenv[7], 2);    
    add(&testenv[3].edges, &testenv[1], 2);    

    add(&testenv[4].edges, &testenv[7], 1);    
    add(&testenv[4].edges, &testenv[2], 1);    
    add(&testenv[4].edges, &testenv[1], 3);    

    add(&testenv[5].edges, &testenv[7], 4);    
    add(&testenv[5].edges, &testenv[6], 2);    
    add(&testenv[5].edges, &testenv[1], 4);    

    add(&testenv[6].edges, &testenv[7], 2);    
    add(&testenv[6].edges, &testenv[5], 2);    

    add(&testenv[7].edges, &testenv[6], 2);    
    add(&testenv[7].edges, &testenv[4], 1);    
    add(&testenv[7].edges, &testenv[3], 2);    
}


void print_nodes(NODE_T testenv[TESTNODES])
{
    EDGE_T *it;
    int i;
    for (i = 0; i < TESTNODES; i++) {
        printf("%s: ", testenv[i].id);
        it = testenv[i].edges;
        while(it) {
            printf("%s", it->node->id);
            printf("(%u) ", it->weight);
            it = it->next;
        }
        printf("\n");
    }
}

int main(void) 
{
    NODE_T testenv[TESTNODES];
    setup_testenv(testenv);
    print_nodes(testenv);
    printf("\e[0;32mTest OK!\e[0;37m\n");
    return EXIT_SUCCESS;
}
