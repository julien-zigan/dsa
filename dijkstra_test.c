#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#include "dijkstra.h"
#include "jz_unit.h"

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


void sprint_nodes(char buff[BUFSIZ], NODE_T testenv[TESTNODES])
{
    char item[64];
    EDGE_T *it;
    int i;
    for (i = 0; i < TESTNODES; i++) {
        sprintf(item, "%s: ", testenv[i].id);
        strcat(buff, item);
        it = testenv[i].edges;
        while(it) {
            sprintf(item,"%s", it->node->id);
            strcat(buff, item);
            sprintf(item,"(%u) ", it->weight);
            strcat(buff, item);
            it = it->next;
        }
        strcat(buff, "\n");
    }
}

void test_printnodes(NODE_T testenv[TESTNODES])
{   
    init_test(__FUNCTION__);
    char buff[BUFSIZ];
    char expected[] = 
        "A: B(1) C(2) \n"
        "B: A(1) D(2) E(3) F(4) \n"
        "C: A(2) E(1) \n"
        "D: B(2) H(2) \n"
        "E: B(3) C(1) H(1) \n"
        "F: B(4) G(2) H(4) \n"
        "G: F(2) H(2) \n"
        "H: D(2) E(1) G(2) \n";
                    
    sprint_nodes(buff, testenv);
    assert_output_equals(expected, buff);
}

void test_test()
{
    init_test(__FUNCTION__);
    assert_output_equals("abc", "abc");
}

int main(void) 
{
    init_testsuite();
    NODE_T testenv[TESTNODES];
    setup_testenv(testenv);
    test_printnodes(testenv);
    test_test();
    print_test_stat();
    return EXIT_SUCCESS;
}
