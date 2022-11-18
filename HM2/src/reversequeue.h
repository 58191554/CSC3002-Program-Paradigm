#ifndef REVERSEQUEUE_H
#define REVERSEQUEUE_H
#include "queue.h"
#include <string>
/* Function prototypes */

/*
 * Function: reverseQueue
 * Usage: reverseQueue(queue);
 * ---------------------------
 * Reverses the order of the elements in a queue.  This
 * implementation does so by using a stack to hold the
 * values as they are being reversed.
 */

void reverseQueue(Queue<std::string> & queue);

/*
 * Function: listQueue
 * Usage: listQueue(queue);
 * ------------------------
 * Lists the contents of the queue on the standard output stream.
 */

void listQueue(Queue<std::string> & queue);

#endif // REVERSEQUEUE_H
