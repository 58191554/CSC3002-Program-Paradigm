/*
 * File: TraverseTest.cpp
 * ------------------
 * This program reimplements the depth-first search algorithm using an
 * explicit stack
 * or
 * reimplements the breadth-first search algorithm using an
 * explicit queue.
 */

#include "P2Traverse.h"

using namespace std;

void dfs(Node *start);
void bfs(Node *start);
void visit(Node *node);


int TraverseTest() {
   SimpleGraph airline;
   ifstream infile("AirlineGraph.txt");
   readGraph(airline, infile);
   dfs(airline.nodeMap.get("Portland"));
   bfs(airline.nodeMap.get("Portland"));
   return 0;
}

void dfs(Node *start) {
   /* TODO */
   /* make sure that your implemantation is based on an explicit Stack */
    cout << "***dfs***" << endl;
    //the set that stores the visited nodes
    Set<Node *> visitedNode;
    //the stack that stores the unexplored nodes
    Stack<Node *> stack;
    //at the beginning of the algorithm, simply push the starting node on the stack
    stack.push(start);

    while (!stack.isEmpty()) {
        //1. pop the topmost node from the stack
        Node *node = stack.pop();
        //if the node is not visited
        if(!visitedNode.contains(node)) {
            //2. visit that node
            visit(node);
            visitedNode.add(node);
        }
        // 3. push its neighbors on the stack
        foreach (Arc *arc in node->arcs) {
            //if the neighbor is not visited
            if (!visitedNode.contains(arc->finish)) {
                stack.push(arc->finish);
            }
        }
    }
}

void bfs(Node *start) {
    /* TODO */
   /* make sure that your implemantation is based on an explicit Queue */
    cout << "***bfs***" << endl;

    //the set that stores the visited nodes
    Set<Node *> visitedNode;
    //the queue that stores the unexplored nodes
    Queue<Node *> queue;
    //at the beginning of the algorithm, simply enqueue the starting node in the queue
    queue.enqueue(start);

    while (!queue.isEmpty()) {
        //1. dequeue the first node in the queue
        Node *node = queue.dequeue();
        //if the node is not visited
        if (!visitedNode.contains(node)) {
            //2. visit that node
            visit(node);
            visitedNode.add(node);
        }
        // 3. enqueue its neighbors in the queue
        foreach (Arc *arc in node->arcs) {
            //if the neighbor is not visited
            if (!visitedNode.contains(arc->finish)) {
                queue.enqueue(arc->finish);
           }
        }
    }
}

void visit(Node *node) {
    //print the name of the node
    cout << node->name << endl;
}

