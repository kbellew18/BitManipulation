/* 
 * CS:APP Data Lab 
 * 
 * <Kieran Bellew kbellew18>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 9.0.0.  Version 9.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, fourth edition, plus
   Amd. 1  and Amd. 2 and 273 characters from forthcoming  10646, fifth edition.
   (Amd. 2 was published 2016-05-01,
   see https://www.iso.org/obp/ui/#iso:std:iso-iec:10646:ed-4:v1:amd:2:v1:en) */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
       // ~x | ~y gives an inverse of & operation, so then flip bits to get result
       int result =  ~(~x | ~y);
       return result;
}
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  /*flipping bits of x and Y and then &ing them gives inverse, so then flip again*/
  int result;
  result = ~( ~x & ~y);
  return result;
}
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  /* using the base of the bitOR operation above, I just got rid of the ~ op */
  int result;
  result = (~x & ~y);
  return result;
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /*Like the bitOr above, but to make it exclusive, we must and different 
   *combinations of x & y
   */
  int result;
  result = ~(~(~x & y) & ~(x & ~y));
  return result;
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  /*85 represents the first 8 even bits, so just shift that 3 times to fill the whole word up */
  int result;
  int evenEight ;
  evenEight = 85;
  result = evenEight << 8;
  result = result + (evenEight << 16);
  result = result + (evenEight << 24);
  result = result + evenEight;
  return result;
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  /*assigning 0 gives 32 bits that are 0s, so flipping all of those to 1 will give -1 */
  int result;
  result = 0;
  result = ~result;
  return result;
}
/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) {
  /* if n = 0 set most significant bit to 0, otherwise set to 1 by double inverting n
   * then shift that by n - 1, resulting in that many upper bits being set to 1
   */
  int result;
  int shift;
  shift = (n + ~0); // n - 1
  result = !!n << 31;
  result = result >> shift;
  return result;
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
  /* using a constant to set first 8 bits to 01001001, then sift appropriately
   */
  int lsb;
  int result;
  int constant = 73; // 73 is 01001001 - first 8 LSB set correctly
  result = constant << 9; // shifts left 9
  result = result + constant; // first 16 bits set correctly
  lsb = result; // store in another variable so it can be added after one shift
  result = (lsb << 18) + lsb; // 18 bits are still 0s so set those correctly
  
  return result;
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  /* create a mask with all odd bits - same code as evenBits function above 
   * but with different constant
   */
  int result;
  int mask;

  int oddEight = 170;
  mask = oddEight << 8;
  mask = mask + (oddEight << 16);
  mask = mask + (oddEight << 24);
  mask = mask + oddEight;

  result = mask | x; // ORing masking and x to check if all even, will become 1s if even
  result = ~result; // makes all the 1s, 0s if they were even

  return !result;
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
  /* using similar concept as allEvenBits, this will OR a mask with x and 
   * then set bits correctly
   */

  int result;
  int mask;

  // mask with all odd bits
  int oddEight = 170;
  mask = oddEight << 8;
  mask = mask + (oddEight << 16);
  mask = mask + (oddEight << 24);
  mask = mask + oddEight;

  result = mask & x; // ANDing mask and x together, so if there is an odd bit there will be a 1 in the string
  result = !(!result); // if non-zero, ! makes it 1, and vice-versa - so if odd bit exists, turns to 0, then to 1
  return result;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /* shift x to the tight by n*8, then AND a mask with the shifted version of x to get the byte
   */
  int result;
  int mask; 
  int shift;

  mask = 255;
  // shift x to the right by n*8
  shift = n << 3; // shifting by 3 is the same as multiplying by 8 because 2^3 is 8
  result = x >> shift;

  // AND a mask with the shifted version of x - mask will be 11111111
  result = result & mask;

  return result;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
  /* get the byte section to swap, then put them in the correct swapping position,
   * then subtract those values from x, so they can be replaced correctly
   * then shift the bytes into their correct new positions and add them with the result
   */
  int result;
  int mask;
  int nShift;
  int mShift;
  int nByte, mByte;
  int nCopy, mCopy;

  mask = 255;
  nShift = n << 3;
  mShift = m << 3;

  nByte =(x >> nShift) & mask; // get the byte section to swap
  mByte =(x >> mShift) & mask;
  nCopy = nByte;
  mCopy = mByte;
  
  // put them in correct swapping position
  nByte = nByte << nShift; // should be all 0s except for the byte section
  mByte = mByte << mShift;

  //subtract them from x, so that they can be replaced correctly
  result = x + (~nByte + 1);
  result = result + (~mByte + 1);

  //shift bytes into correct position and add them with result
  nCopy = nCopy << mShift;
  mCopy = mCopy << nShift;
  result = result + nCopy + mCopy;

  return result;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /* use 2's complement to negate
   */
  int result;
  result = (~x) + 1;

  return result;
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  /* Make all the bits above the highbit and below the lowbit 1's, and then XOR to make
   * the bits between the high and lowbit 1's. There is also a special case for when 
   * lowbit is freater than the highbit
   */
  int result = 0;
  int lowMask;
  int highMask;
  int highShift;
  int lowShift;

  // make all bits above the highbit 1s
  highShift = highbit;
  highMask =( ~0 << highbit) << 1;
  
  // do the same for the bits below the lowbit
  lowShift = lowbit;
  lowMask = ~0 << lowShift;
  
  // xor them together, to make the bits between lowbit and highbit 1s
  result = highMask ^ lowMask;

  // special case for when lowbit is greater than the highbit
  result = result & lowMask;

  return result;
  
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /* Do if x, then y, else then z. Convert x into a boolean, then mask with 1's or 0's.
   * Then create masked for the true and false values from y and z. Then OR with the conditional
   */

  // if x, then y, else then z
  int result;
  int trueX;
  int falseX;
  int conditional; 
  
  // convert x into boolean form, then mask it with all 1s or 0s
  // this establishes if zero or non-zero
  conditional = !!x;
  conditional = ~conditional + 1;
  
  // create masks for the true and false values which come from y and z.
  trueX = y & conditional;
  falseX = z & ~conditional;

  // result comes from an OR operation of the true and false values
  result = trueX | falseX;

  return result;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
  /* Seems to be more like a rotateLeft by n. But shift x by 32 - n, and then OR that
   * that with x that has been shifted by n to the right and ANDed with a mask. 
   */

  int result;
  int shift;
  int mask;
  
  // mask of 1's except for the msb
  mask = ~(1 << 31);

  // subtract n from 32 for appopriate shift
  // shift = 32 + (~n + 1);
  //shift x to the left by that many bits, eg 28, which sets the highbit correctly

  // shift x by 32 - n, then OR with x shifted by n to the right which is 
  // ANDed with a shifted mask
  result = (x << (32 + (~n + 1))) | ((x >> n) & (mask >> (n + ~0))); 

  return result;
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
  /* Compare the signs of x, y, and the result of the subtraction. 
   */
  int xyResult;
  int xySign;
  int resultSign;
  int result;

  //subtract y from x to get result
  xyResult = x + (~y + 1);

  // check the sign of result with the sign of x
  resultSign = xyResult ^ x;

  // check the sign of x and y
  xySign = x ^ y;

  // signs must be the same for no overflow, so AND them
  result = xySign & resultSign;

  // set the result to 0 or 1 respectively, because of XOR need to make 0 -> 1 and vice versa 
  result = !(result >> 31);
  
  return result;
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  /* If x is positive, keep positive and return, or return positive if x is negative.
   * To check sign bit, shift by 31.
   */
  int result;

  // if x is positive, keep positive and return, or resturn positive if x is negative
  // to check sign bit, shift by 31
  result = x >> 31; // if negative, will be -1, if positive, 0, so all 0s or all 1s
  result = (~result & x) | (result & (~x + 1));

  return result;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /* Count the number of ones in each byte, setting the number in that same byte.  
   * Then count up those values in the result variable. To find the number of 1's
   * in each word, use a mask of 0000001000000100000010000001 AND with x and shift appropriately
   */
  int result;
  int mask;
  int count = 0;
  
  // set mask of all 1s
  /* mask = 255; // first 8 bytes set */
  /* mask = mask + (255 << 8); */
  /* mask = mask + (255 << 16); */
  /* mask = mask + (255 << 24); */

  mask = 1 | (1 << 8);
  mask = mask | (1 << 16);
  mask = mask | (1 << 24); // mask set as 0000001000000100000010000001

  count = count + (x & mask);
  count = count + ((x >> 1) & mask);
  count = count + ((x >> 2) & mask);
  count = count + ((x >> 3) & mask);
  count = count + ((x >> 4) & mask);
  count = count + ((x >> 5) & mask);
  count = count + ((x >> 6) & mask);
  count = count + ((x >> 7) & mask);

  result = (count & 255);
  result = result + ((count >> 8) & 255);
  result = result + ((count >> 16) & 255);
  result = result + ((count >> 24) & 255);
  
  return result;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  /* Just continue to XOR two halves of x to get a number that represents the parity.
   * AND that with 1 to see the final parity.
   */
  int result;

  // just continue to XOR two halves of the result, giving a number representing bit parity
  result = (x >> 16) ^ x;
  result = (result >> 8) ^ result;
  result = (result >> 4) ^ result;
  result = (result >> 2) ^ result;
  result = (result >> 1) ^ result;

  // AND result with 1 to see final bit parity
  result = result & 1;

  return result;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
  /* Using the same concept as subOK(), this uses the sign of each variable and the result
   * to get the overflow. With the overflow, return the minimum value if overflow is negative, 
   * and the maximum value if the overflow is positive.
   */

  // use same concept as subOK, use the signs of each variable and the results to get overflow
  int xyResult;
  int resultSign;
  int xSign, ySign;
  int result;
  int overflow;
  int negOverflow, posOverflow;
  int min = 1 << 31;
  int max = ~min;

  //add x and y
  xyResult = x + y;

  // get signs of x and y, and the result
  xSign = x >> 31;
  ySign = y >> 31;
  resultSign = xyResult >> 31;

  // get the overflow by checking the signs
  overflow = (~(xSign ^ ySign)) & (xSign ^ resultSign);

  negOverflow = ~(overflow & (~(xSign ^ 0)));
  posOverflow = (overflow & (~(xSign ^ 0)));

  // return min if negative overflow, max if positive overflow, or result if no overflow
  result = (~overflow & xyResult) | (overflow & ((negOverflow & min) | (posOverflow & max)));
  
  return result;
}

/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
  /* OR a mask that holds the sign of x with a negated version of x and the sign.
   */

  int result;
  int sign;
  int mask;
  int min = 1 << 31;

  // gets sign of x 
  sign = x >> 31;
  // mask of x or 0s depending on if x is signed - 0s with no sign, x if 1s
  mask = ~sign & x;

  // OR the mask and a negated version of x & the sign
  result = mask | (((x & min) + (~x + 1)) & sign);

  return result;
}
