#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dijkstra.h"

void ordered_add(NODE_T **tentatives, NODE_T *node)
{
    NODE_T *tmp = *tentatives;
    
    if (tmp == NULL) {
        *tentatives = node;
    }
}

void sprint_shortest_path(char buffer[BUFSIZ], NODE_T *start, NODE_T *end)
{
    NODE_T *current, *tentatives, *iter;
    EDGE_T *edge;
    int sum;
    char smbuf[16];

    end->label.sum_weight = 0;
    end->label.status = PERMANENT;

    current = end;

    while (1) {
        if (current ==  start)
            break;
        
        for (edge = current->edges; edge; edge = edge->next) {
            if (edge->node->label.status == PERMANENT)
                continue;

            sum = current->label.sum_weight + edge->weight;

            if (edge->node->label.status == TENTATIVE) {
                if (sum < edge->node->label.sum_weight) {
                    edge->node->label.next_hop = current;
                    edge->node->label.sum_weight = sum;
                    edge->node->label.status = TENTATIVE;


                }
            }

        } 
    }
    
    sprintf(buffer, "Shortest path from %s to %s: %s", start->id, end->id, start->id);

    for (iter = current->label.next_hop; iter; iter = iter->label.next_hop) {
        sprintf(smbuf, "->%s", iter->id);
        strcat(buffer, smbuf);
    }
}
