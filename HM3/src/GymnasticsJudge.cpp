/*
 * File: GymJudge.cpp
 * ------------------
 * This program averages a set of gymnastic scores after eliminating
 * the lowest and highest scores.
 */

#include "GymnasticsJudge.h"





/*
 * Function: readScores
 * Usage: int nJudges = readScores(scores, max);
 * ---------------------------------------------
 * This function reads in scores for each of the judges.  The array
 * scores must be declared by the caller and must have an allocated
 * size of max.  The return value is the number of scores.  From the
 * user's perspective, the numbering of the judges begins with 1
 * because that style of numbering is more familiar; internally,
 * the array index values begin with 0.
 */
int readScores(double scores[], int max) {
   cout << "Enter a score for each judge in the range " << MIN_SCORE;
   cout << " to " << MAX_SCORE << "." << endl;
   cout << "Enter a blank line to signal the end of the list." << endl;
   int n = 0;
   while (n < max) {
      string line = getLine("Judge #" + integerToString(n + 1) + ": ");
      if (line == "") {
          return n;
      }
      double score = stringToReal(line);
      if (MIN_SCORE <= score && score <= MAX_SCORE) {
         scores[n++] = score;
      } else {
         cout << "That score is out of range." << endl;
      }
   }
   return max;
}

double sumArray(double array[], int n){
    double score_sum = 0;
    for(int i = 0 ;i<n;i++){

        double score = array[i];
        score_sum += score;
    }

    return score_sum;
}
double findLargest(double scores[], int n){
    double largest = 0.0;
    for(int i = 0;i<n;i++){
        if (largest < scores[i])
            largest = scores[i];
    }
    return largest;

}
double findSmallest(double scores[], int n){
    double smallest = 10;
    for(int i=0;i<n;i++){
        if(smallest > scores[i])
            smallest = scores[i];
    }
    return smallest;
}

