#include<iostream>
#include"console.h"
#include"P1PriorityQueue.h"
#include"P2Traverse.h"

using namespace std;

//int TraverseTest() {
//   SimpleGraph airline;
//   ifstream infile("AirlineGraph.txt");
//   readGraph(airline, infile);
//   dfs(airline.nodeMap.get("Portland"));
//   bfs(airline.nodeMap.get("Portland"));
//   return 0;
//}

int PriorityQueueTest() {
   PriorityQueue<string> pq;
   cout<<(pq.size()==0)<<endl;
   cout<<(pq.isEmpty())<<endl;
   pq.enqueue("A",1);
   cout<<(pq.isEmpty())<<endl;
   cout<<(pq.peek()=="A")<<endl;
   pq.enqueue("D", 3);
   pq.enqueue("C", 2);
   pq.enqueue("B", 1);
   cout<<(pq.peek()=="A")<<endl;
   cout<<(pq.size()==4)<<endl;
   cout<<pq.toString()<<endl;
   cout<<(pq.dequeue()=="A")<<endl;
   cout<<(pq.peek()=="B")<<endl;
   cout<<(pq.dequeue()=="B")<<endl;
   cout<<(pq.dequeue()=="C")<<endl;
   cout<<(pq.dequeue()=="D")<<endl;
   cout<<(pq.isEmpty())<<endl;
   return 0;
}

int main(){
    cout<<"Problem1:"<<endl;
    PriorityQueueTest();
    cout<<"Problem2:"<<endl;
    TraverseTest();
    return 0;
}
