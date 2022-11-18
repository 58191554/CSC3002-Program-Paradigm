#ifndef MORSECODE_H
#define MORSECODE_H
#include "map.h"
#include <iostream>
#include <string>
#include "error.h"
#include "map.h"
#include "simpio.h"
#include "strlib.h"
#include "console.h"
/* Function protoypes */

/*
 * Function: translateLettersToMorse
 * Usage: string morse = translateLettersToMorse(line);
 * ----------------------------------------------------
 * Translates a string of letters into Morse Code characters separated
 * by spaces.  Characters that don't appear in the table are simply ignored.
 */

std::string translateLettersToMorse(std::string line);

/*
 * Function: translateMorseToLetters
 * Usage: string letters = translateLettersToMorse(line);
 * ------------------------------------------------------
 * Translates a string in Morse Code into English letters.
 * Because word breaks are not represented in Morse code, the
 * letters in the output will be run together.  The characters
 * of the Morse Code input must be separated by a single space.
 * Any other character in the input is simply ignored.  If there
 * is no English equivalent for the Morse Code character, this
 * function indicates that fact by inserting a question mark (?).
 *
 * Implementation note: To eliminate the special case of the last
 * character in the line, this function begins by adding a space
 * to the end of the input string.
 */

std::string translateMorseToLetters(std::string line);

/*
 * Function: createMorseCodeMap
 * Usage: Map<string> map = createMorseCodeMap();
 * ----------------------------------------------
 * Returns a map in which each uppercase letter is mapped into its
 * Morse code equivalent.
 */

Map<std::string,std::string> createMorseCodeMap();


/*
 * Function: invertMap
 * Usage: Map<string> inverse = invertMap(map);
 * --------------------------------------------
 * Creates an inverted copy of the specified map in which the values
 * in the original become the keys of the new map and refer back to
 * their associated keys.  Thus, if "abc" is bound to "xyz" in the
 * original map, the inverted map will bind "xyz" to "abc".  If two
 * keys in the original map have the same value, this function will
 * signal an error condition.
 */

Map<std::string,std::string> invertMap(const Map<std::string,std::string> & map);

/*
 * Constant maps: LETTERS_TO_MORSE, MORSE_TO_LETTERS
 * -------------------------------------------------
 * These variables contain maps that convert in each direction between
 * uppercase letters and their Morse Code equivalent.  Because these
 * variables are initialized once and retain their values throughout
 * the lifetime of the program, they are best treated as constants
 * that are shared among the different functions instead of as variables
 * that are passed as parameters.
 */

const Map<std::string,std::string> LETTERS_TO_MORSE = createMorseCodeMap();
const Map<std::string,std::string> MORSE_TO_LETTERS = invertMap(LETTERS_TO_MORSE);



#endif // MORSECODE_H
