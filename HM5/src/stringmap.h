/*
 * File: stringmap.h
 * -----------------
 * This interface exports a simplified version of the Map class in which
 * the keys and values are always strings.
 */

#ifndef _stringmap_h
#define _stringmap_h

#include <string>

class StringMap {

public:

/*
 * Constructor: StringMap
 * Usage: StringMap map;
 * ---------------------
 * Initializes a new empty map that uses strings as both keys and values.
 */

   StringMap();

/*
 * Destructor: ~StringMap
 * ----------------------
 * Frees any heap storage associated with this map.
 */

   ~StringMap();

/*
 * Method: get
 * Usage: string value = map.get(key);
 * -----------------------------------
 * Returns the value for key or the empty string, if key is unbound.
 */

   std::string get(const std::string & key) const;

/*
 * Method: put
 * Usage: map.put(key, value);
 * ---------------------------
 * Associates key with value in this map.
 */

   void put(const std::string & key, const std::string & value);

/*
 * Method: size
 * Usage: int n = map.size();
 * --------------------------
 * Returns the number of key-value pairs in the map.
 */

   int size() const;

/*
 * Method: isEmpty
 * Usage: if (map.isEmpty()) . . .
 * -------------------------------
 * Returns true if the map is empty.
 */

   bool isEmpty() const;

/*
 * Method: containsKey
 * Usage: if (map.containsKey(key)) . . .
 * --------------------------------------
 * Returns true if the map contains the specified key.
 */

   bool containsKey(const std::string & key) const;

/*
 * Method: remove
 * Usage: map.remove(key);
 * -----------------------
 * Removes the key from the map, if it exists.
 */

   void remove(const std::string & key);

/*
 * Method: clear
 * Usage: map.clear(key);
 * ----------------------
 * Removes all key-value pairs from the map.
 */

   void clear();

/*
 * Method: getNBuckets
 * Usage: int n = map.getNBuckets();
 * ---------------------------------
 * Returns the number of buckets.
 */

   int getNBuckets();

/*
 * Method: rehash
 * Usage: map.rehash(nBuckets);
 * ----------------------------
 * Rehashes every key in the map into a new hash table with the specified
 * number of buckets.
 */

   void rehash(int nBuckets);

/* Private section */

/*
 * Notes on the representation
 * ---------------------------
 * This version of the StringMap class uses a hash table that keeps the
 * key-value pairs in an array of buckets using the open-addressing model.
 */

private:

/* Type definition for each key-value pair */

   struct KeyValuePair {
      bool occupied;
      std::string key;
      std::string value;
   };

/* Constant definitions */

   static const int INITIAL_BUCKET_COUNT;
   static const double REHASH_THRESHOLD;

/* Instance variables */

   KeyValuePair *buckets;       /* Dynamic array of buckets           */
   int nBuckets;                /* The number of buckets in the array */
   int count;                   /* The number of key-value pairs      */

/* Private methods */

   int findKey(const std::string & key) const;
   int insertKey(const std::string & key);

/* Make copying illegal */

   StringMap(const StringMap & src) { }
   StringMap & operator=(const StringMap & src) { return *this; }

};

/*
 * Free function: hashCode_
 * Usage: int code = hashCode_(key);
 * --------------------------------
 * Returns the hash code for key.
 */

int hashCode_(const std::string & key);

#endif
