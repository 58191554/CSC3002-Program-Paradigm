/*
 * File: pqueue.h
 * --------------
 * This file exports the PriorityQueue class, a collection in which values
 * are processed in priority order.
 */

#ifndef _pqueue_h
#define _pqueue_h

#include "vector.h"
#include "error.h"
using namespace std;

/*
 * Class: PriorityQueue<ValueType>
 * -------------------------------
 * This class models a structure called a priority queue in which values
 * are processed in order of priority.  As in conventional English usage,
 * lower priority numbers correspond to higher effective priorities, 
 * so that a priority 1 item takes precedence over a priority 2 item.
 */

template <typename ValueType>
class PriorityQueue {

public:

/*
 * Constructor: PriorityQueue
 * Usage: PriorityQueue<ValueType> pq;
 * -----------------------------------
 * Initializes a new priority queue, which is initially empty.
 */

   PriorityQueue();

/*
 * Destructor: ~PriorityQueue
 * --------------------------
 * Frees any heap storage associated with this priority queue.
 */

   virtual ~PriorityQueue();


/*
 * Method: size
 * Usage: int n = pq.size();
 * -------------------------
 * Returns the number of values in the priority queue.
 */

   int size() const;

/*
 * Method: isEmpty
 * Usage: if (pq.isEmpty()) ...
 * ----------------------------
 * Returns true if the priority queue contains no elements.
 */

   bool isEmpty() const;

/*
 * Method: clear
 * Usage: pq.clear();
 * ------------------
 * Removes all elements from the priority queue.
 */

   void clear();

/*
 * Method: enqueue
 * Usage: pq.enqueue(value, priority);
 * -----------------------------------
 * Adds value to the queue with the specified priority.  
 * Lower priority numbers correspond to higher priorities, 
 * which means that all 
 * priority 1 elements are dequeued before any priority 2 elements.
 */

   void enqueue(ValueType value, double priority);

/*
 * Method: dequeue
 * Usage: ValueType first = pq.dequeue();
 * --------------------------------------
 * Removes and returns the highest priority value.  
 * If multiple entries in
 * the queue have the same priority, 
 * those values are dequeued in the same
 * order in which they were enqueued.
 */

   ValueType dequeue();

/*
 * Method: peek
 * Usage: ValueType first = pq.peek();
 * -----------------------------------
 * Returns the value of highest priority in the queue, without removing it.
 */

   ValueType peek() const;

/*
 * Method: peekPriority
 * Usage: double priority = pq.peekPriority();
 * -------------------------------------------
 * Returns the priority of the first element in the queue, 
 * without removing it.
 */

   double peekPriority() const;

/*
 * Method: toString
 * Usage: string str = pq.toString();
 * ----------------------------------
 * Converts the queue to a printable string representation.
 */

   std::string toString();

/* Private section */

/**********************************************************************/
/* Note: Everything below this point in the file is logically part    */
/* of the implementation and should not be of interest to clients.    */
/**********************************************************************/

/*
 * Implementation notes: PriorityQueue data structure
 * --------------------------------------------------
 * The PriorityQueue class is implemented using a data structure called a
 * heap.
 */

private:

/* Type used for each heap entry */

   struct HeapEntry {
      ValueType value;

      double priority;

      long sequence; 
      /* order of enqueue, which used for recording the order of which the elements are inserted, 
       * i.e.: when two elements are of the same priority,
       * it depends on the order of the sequence that
       * the first inserted element should be dequeued first
       */ 

   };

/* Instance variables */

   Vector<HeapEntry> heap;
   long enqueueCount; // to record the sequence
   int count;         // to record the number of elements in the PriorityQueue
   int capacity;      // capacity of the heap

/* Private function prototypes */

   void enqueueHeap(ValueType & value, double priority); 
   ValueType dequeueHeap();
   bool takesPriority(int i1, int i2);
   void swapHeapEntries(int i1, int i2);

};

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue() {
   clear();
}

/*
 * Implementation notes: ~PriorityQueue destructor
 * -----------------------------------------------
 * All of the dynamic memory is allocated in the Vector class, so no work
 * is required at this level.
 */

template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue() {
   /* Empty */
}

template <typename ValueType>
int PriorityQueue<ValueType>::size() const {
    return count;
}

template <typename ValueType>
bool PriorityQueue<ValueType>::isEmpty() const {
    return (count == 0);
}

template <typename ValueType>
void PriorityQueue<ValueType>::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename ValueType>
bool PriorityQueue<ValueType>::takesPriority(int i1, int i2) {
   /* compare the priority of two elements，
    * when their priorities are equal, comparing based on the sequence */
   /* TODO */

    if (heap[i1].priority < heap[i2].priority) {
        return true;
    }
    //if the priority are equal, then compare the sequence
    if (heap[i1].priority == heap[i2].priority && heap[i1].sequence < heap[i2].sequence) {
        return true;
    }
    else {
        return false;
    }
}

template <typename ValueType>
void PriorityQueue<ValueType>::swapHeapEntries(int i1, int i2) {
   /* TODO */

    //the temporary entry to store entry 1
    HeapEntry temp = heap[i1];
    heap[i1] = heap[i2];
    heap[i2] = temp;
}


template <typename ValueType>
void PriorityQueue<ValueType>::enqueue(ValueType value, double priority) {

    //set up a new entry
    HeapEntry Hentry;
    Hentry.value = value;
    Hentry.priority = priority;
    enqueueCount++;
    Hentry.sequence = enqueueCount;
    heap.add(Hentry);
    count++;

    //if the queue is empty
    if (count - 1 == 0) {
        return;
    //if the queue is not empty
    } else {
        //from bottom to top
        int index = heap.size() - 1;
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            //if the priority of parent is higher than children
            if (takesPriority(parentIndex, index)) {
                break;
            //if the priority of parent is lower than children
            } else {
                swapHeapEntries(parentIndex, index);
                //the parent becomes children and enters the new loop
                index = parentIndex;
            }
        }
    }
}

template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue() {
   /* TODO */

    //if the queue is empty
    if (count == 0) {
        error("dequeue error: the queue is empty");
    }

    //delete the root and replace it with the last entry
    ValueType result = heap[0].value;
    if (heap.size() >= 1) {
        heap[0] = heap[heap.size() - 1];
        heap.remove(heap.size() - 1);
    }
    count--;

    //if after deleting there is only one entry, no need to swap
    if (heap.size() == 1) {
        return result;
    }
    //if after deleting there are two entries
    if (heap.size() == 2) {
        //if the priority of parent is higher than children
        if (takesPriority(0, 1)) {
            return result;
        //if the priority of parent is lower than children
        } else {
            swapHeapEntries(0, 1);
            return result;
        }
    }

    //if after deleting there are more than three entries
    int idx = 0;
    int leftChildIndex = 2 * idx + 1;
    int rightChlidIndex = 2 * idx + 2;
    //the entry is before parent of the last children
    while (idx <= (heap.size() - 1 - 1) / 2) {

        //if the parent of the last children has only left child
        if (rightChlidIndex > heap.size() - 1) {
            if (takesPriority(idx, leftChildIndex)) {
                break;
            } else {
                swapHeapEntries(idx, leftChildIndex);
                break;
            }
        }

        //the priority of left child is higher
        if (takesPriority(leftChildIndex, rightChlidIndex)) {
            if (takesPriority(idx, leftChildIndex)) {
                break;
            }
            else {
                swapHeapEntries(idx, leftChildIndex);
                //the children becomes the parent and enters the new loop
                idx = leftChildIndex;
                leftChildIndex = 2 * idx + 1;
                rightChlidIndex = 2 * idx + 2;
                continue;
            }
        }

        //the priority of right child is higher
        if (takesPriority(rightChlidIndex, leftChildIndex)) {
            if (takesPriority(idx, rightChlidIndex)) {
                break;
            }
            else {
                swapHeapEntries(idx, rightChlidIndex);
                //the children becomes the parent and enters the new loop
                idx = rightChlidIndex;
                leftChildIndex = 2 * idx + 1;
                rightChlidIndex = 2 * idx + 2;
                continue;
            }
        }
    }

    return result;
}
template <typename ValueType>
ValueType PriorityQueue<ValueType>::peek() const {
  /* TODO */

    //if the queue is empty
    if (count == 0) {
        error("peek error: the queue is empty");
    } else {
        return heap[0].value;
    }
}

template <typename ValueType>
double PriorityQueue<ValueType>::peekPriority() const {
   /* TODO */

    //if the queue is empty
    if (count == 0) {
        error("peekPriority error: the queue is empty");
    } else {
        return heap[0].priority;
    }

}


template <typename ValueType>
std::string PriorityQueue<ValueType>::toString() {
  /* convert the PriorityQueue into a printable String */
  /* TODO */

    //use a temporary heap to generate the string without changing the current queue
    PriorityQueue temp;
    for (int i = 0; i != heap.size(); i++) {
        temp.heap.add(heap[i]);
    }
    temp.count = count;

    string result;
    while (!temp.isEmpty()) {
        result += temp.dequeue();
    }
    return result;
}


template <typename ValueType>
std::ostream & operator<<(std::ostream & os,const PriorityQueue<ValueType> & pq) {

    //use the toString() method and print out the pq
    string result = pq.toString();
    return os << result;
}

#endif





