//316584960 Liz Aharonian
#include "ex1.h"

/**
 * is_little_endian function.
 * @return 1 if little endian, 0 otherwise
 */
int is_little_endian() {
    long int n = 1;
    //check if first bit equals 1
    return (*(char *) &n == 1);
}

/**
 * merge_bytes function.
 * @param x - the number we remove it's LSB
 * @param y - the number we take the LSB from
 * @return combination of x without it's LSB and y's LSB
 */
unsigned long merge_bytes(unsigned long x, unsigned long int y) {
    //create pointers to first address bit of x and y (char* represents pointer to one byte)
    unsigned char *addressY = (unsigned char *) &y;
    unsigned char *addressX = (unsigned char *) &x;
    if (is_little_endian()) {
        //LSB is on the smallest address - therefore we should take it from there
        addressX[0] = addressY[0];
        return x;

    } else {
        //LSB is on the biggest address - therefore we should take it from there
        int size = sizeof(y);
        addressX[size - 1] = addressY[size - 1];
        return x;
    }
}

/**
 * put_byte function.
 * @param x number to change its byte
 * @param b the new byte
 * @param i place (count from LSB) of the new byte
 * @return x with b at number i byte
 */
unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    //create pointers to first address bit of x (char* represents pointer to one byte)
    unsigned char *addressX = (unsigned char *) &x;
    if (is_little_endian()) {
        //the smallest address points the LSB so we can count from there
        addressX[i] = b;
        return x;
    } else {
        //tne smallest address points the MSB - therefore we should count from the end(!)
        int size = sizeof(x);
        addressX[size-1-i] = b;
    }
}