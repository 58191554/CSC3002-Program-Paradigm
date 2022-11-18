#include<iostream>
#include"console.h"
#include"assignment5.h"
using namespace std;


int main(){
    cout<<"Problem1:"<<endl;
    PriorityQueueUnitTest();
    cout<<"Problem2:"<<endl;
    BigIntTest();
    cout<<"Problem3,4:"<<endl;
    StringMapTest();
    return 0;
}


/* pqueue test program */

int PriorityQueueUnitTest() {
   PriorityQueue<string> pq;
   assert(pq.size() == 0);
   assert(pq.isEmpty());
   pq.enqueue("A", 1);
   assert(!pq.isEmpty());
   assert(pq.peek() == "A");
   pq.enqueue("D", 3);
   pq.enqueue("C", 2);
   pq.enqueue("B", 1);
   assert(pq.peek() == "A");
   assert(pq.size() == 4);
   assert(pq.dequeue() == "A");
   assert(pq.peek() == "B");
   assert(pq.dequeue() == "B");
   assert(pq.dequeue() == "C");
   assert(pq.dequeue() == "D");
   assert(pq.isEmpty());
   cout << "Priority queue test succeeded" << endl;
   return 0;
}


/*
 * BigIntTest
 * --------------------
 * This file calculates a table of factorials.
 */
BigInt fact(int n) {
   BigInt result("1");
   for (int i = 1; i <= n; i++) {
      result = result * BigInt(integerToString(i));
   }
   return result;
}

int BigIntTest() {
   for (int i = 0; i <= 52; i++) {
      if (i < 10) cout << " ";
      cout << i << "! = " << fact(i).toString() << endl;
   }
    return 0;
}


/*
 * StringMapTest
 * -----------------------
 * This program implements an interactive test of the Map class that
 * supports the following commands:
 *
 *     size         -- Prints the size of the map
 *     isEmpty      -- Prints whether the map is empty
 *     clear        -- Clears the map
 *     get key      -- Returns the value associated with key
 *     set key str  -- Sets the entry for key to str
 *     contains key -- Indicates whether the map contains key
 *     remove key   -- Removes the key from the table
 *     rehash n     -- Rehashes so that the table has n buckets
 *     buckets      -- Prints the number of buckets
 *     help         -- List these commands
 *     quit         -- Quits the program
 */
/* Function prototypes */

void executeCommand(TokenScanner & scanner, StringMap & map);
void helpCommand();

/* Main program */
/*
 * Test notes
 * -------------------------
 * The program will be tested by a serials of commands, so please
 * use the following command excutor to ensure the correctness of
 * your code.
 */
int StringMapTest() {
   StringMap map;
   TokenScanner scanner;
   scanner.ignoreWhitespace();
   scanner.scanNumbers();
   scanner.scanStrings();
   while (true) {
      scanner.setInput(getLine("> "));
      executeCommand(scanner, map);
   }
   return 0;
}


void executeCommand(TokenScanner & scanner, StringMap & map) {
   string cmd = scanner.nextToken();
   if (cmd == "size") {
      cout << map.size() << endl;
   } else if (cmd == "isEmpty") {
      cout << ((map.isEmpty()) ? "true" : "false") << endl;
   } else if (cmd == "clear") {
      map.clear();
   } else if (cmd == "get") {
      string key = scanner.getStringValue(scanner.nextToken());
      cout << map.get(key) << endl;
   } else if (cmd == "set") {
      string key = scanner.getStringValue(scanner.nextToken());
      map.put(key, scanner.getStringValue(scanner.nextToken()));
   } else if (cmd == "contains") {
      string key = scanner.getStringValue(scanner.nextToken());
      cout << ((map.containsKey(key)) ? "true" : "false") << endl;
   } else if (cmd == "remove") {
      string key = scanner.getStringValue(scanner.nextToken());
      map.remove(key);
   } else if (cmd == "buckets") {
      cout << map.getNBuckets() << endl;
   } else if (cmd == "rehash") {
      int n = stringToInteger(scanner.nextToken());
      map.rehash(n);
   } else if (cmd == "help") {
      helpCommand();
   } else if (cmd == "quit") {
      exit(0);
   } else if (cmd != "") {
      cout << "Unrecognized command: " << cmd << endl;
   }
}

/*
 * Function: helpCommand
 * Usage: helpCommand();
 * ---------------------
 * Lists the available commands.
 */

void helpCommand() {
   cout << "Available commands:" << endl;
   cout << "  size         -- Prints the size of the map" << endl;
   cout << "  isEmpty      -- Prints whether the map is empty" << endl;
   cout << "  get key      -- Returns the value associated with key" << endl;
   cout << "  set key str  -- Sets the entry for key to str" << endl;
   cout << "  contains key -- Indicates whether the map contains key" << endl;
   cout << "  remove key   -- Removes the key from the table" << endl;
   cout << "  clear        -- Clears the map" << endl;
   cout << "  buckets      -- Prints the number of buckets" << endl;
   cout << "  rehash       -- Rehashes the map to have n buckets" << endl;
   cout << "  help         -- List these commands" << endl;
   cout << "  quit         -- Quits the program" << endl;
}
