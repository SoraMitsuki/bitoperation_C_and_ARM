/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * Name: Jiaqi Fan
 * PID: A12584051
 * UserID: SoraMitsuki
 *
 * Name: Xuanru Zhu
 * PID: A91064234
 * UserID: Aaron12138 
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
  3. Use the gradescope autograder and your own tester to check your functions for correctness.
  4. Use the dlc program to check if your functions meet the constraints on the
     maximum number of ops and permissible operators.
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
 *   2. Use the gradescope autograder to check for logical correctness 
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
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
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /* reverse x and y and use | operator */
  return ~(~x | ~y);
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
 /* first change the n byte into bits, then right shift n bits apply the last bits */ 
  return (x >> (n << 3)) & 0xFF;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  /* to aviod the sign of negative number we need to complete a mask */
  /* need a mask that take out the unnecessary bits */
  int mask = 0x01 << 31;
  return (x >> n) & ~((mask >> n) << 1);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int mask;
  int result;
  int temp;
  int mask2;
  mask = 0x55 | (0x55 << 8);
  mask = mask | (mask << 16);//make a mask that is 0101
  result = x & mask; //apply the mask to x and obtain the 2 bits
  result += (x >> 1) & mask; //shift the number and add another 2 bits
  temp = 0x33 | 0x33 << 8;
  temp = temp | temp << 16; //make a mask that is 0011
  mask2 = ~(0x3 << 30); // make a mask that is 0011111111
  // repeat shift and add the 2 bits
  result = (result & temp) + (((result >> 2)&mask2) & temp);
  result += (result >> 16);
  temp = 0xF | (0xF << 8); //make a temp 11110000111
  result = (result & temp) + ((result >> 4) & temp);
  return (result + (result >> 8)) & 0xFF;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  /* use OR to change all the 1's in the number */
  int xMask = x >> 31;
  int opMask =(~x + 1) >> 31;
  return (~(xMask | opMask)) & 1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /* the minimum number for two's complement is -128 */
  int x = 0x01;
  return x << 31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  /* find difference of x with max and min and then shift it to n +1 */
  /* to the left and opposite it */
  int mask = x >> 31;
  int getMax = ~x & mask;
  int getMin = x & ~mask;
  int difference = getMax + getMin;
  int mask2 = 0xFF | (0xFF << 8);
  mask2 = mask2 | (mask2 << 16);
  return !(difference  >> (n + mask2));
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  // When x is a negative number that cannot be exactly divided by 2^n,
  // the result (x >> n) will be less than the correct result by 1.
  // To handle this case, we need to add some number to x without affecting
  // any other cases. In this case, 2^n-1 works exactly as desired.
  int pwr2, mask;
  pwr2 = 1 << n;
  pwr2 = pwr2 + ~0; // 2^n - 1
  mask = x >> 31; // 0x0000 if positive, 0xFFFF if negative
  pwr2 &= mask;
  return (x + pwr2) >> n;
}
/* 
 * negate - return -x 
 * You may handle results that fall out of signed int range in any way that you
 * like
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /* use ~ to flip and add 1 to obtain fliped sign value */
  return ~x + 0x01;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  /* take the x and -1 to avoid 0 */
  int change = x + (~1 + 0x01);
  /* shift the new x & with 1 to get the sign and opposite it */
  return !((change >> 31) & 0x01);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /* subtract both number and use isPositive to determine */
  int diff = x + (~y + 0x01);
  int change = diff + (~1 + 0x01);
  return (change >> 31) & 0x01;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  int log, mask1, mask2, mask3, mask4;
  log = 0; // target output is a 5 bit number with range [0,30]
  log |= !!((x>>16)<<16) << 4; // set 5th bit with high-order 16 bits
  mask1 = 0xFF << 16; // mask to get high-order 8 bits
  // shift mask by current log value (0 or 16) will bring the mask
  // to desired position
  log |= !!(x & (mask1 << log)) << 3; // determine 4th bit
  mask2 = 0xF0; // mask to get high-order 4 bits
  log |= !!(x & (mask2 << log)) << 2; // determine 3rd bit
  mask3 = 0xC; // mask to get high-order 2 bits
  log |= !!(x & (mask3 << log)) << 1; // determine 2nd bit
  mask4 = 0x2; // mask to get high-order 1 bit
  log |= !!(x & (mask4 << log)); // determine 1st bit
  return log;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  int mask = 0x1 << 31;
  if ( uf == 0x7FC00000) // check for NaN
    return uf;
  return uf + mask; //change the sign of the first bit
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  int exp = 158; //split exp, sign and decimal from x
  int sign = x & (0x1 << 31);
  int decimal;
  if (x == (0x1 << 31)) //check x is negative -128 or 0
    return 0x1 << 31 | (158 << 23); 
  if(!x) //if x = 0 return 0
    return x;
  if(sign) //if x is negative flip x into positive
    x = ~x + 1;
  while(!(x & (1 << 31))){ //count the number of exp in x
    x <<= 1;
    exp--;
  }
  decimal = (x & (~(0x1 << 31))) >> 8; //decimal is the number that produced by
  //bitwist x by ~0x80000000 and right shift 8 bits because the exp and sign
  if((x & 0x80 && (x & 0x7F)) > 0 || decimal & 1) //check the decimal for overflow
  //if there is overflow then decimal + 1
    decimal = decimal + 1;
  // return the combination of the sign, exp left shift 23
  //because from 31 t0 23 bits 8 bits number and the decimal
  return sign | (exp << 23) | decimal;

}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  unsigned sign = uf & (0x1 << 31); //get the sign bit
  unsigned exp = (uf >> 23) & 0xFF; //get the exponential 8 bits
  unsigned decimal = uf & 0x007FFFFF; // get decimal 23 bits

  if(exp == 255 || (exp == 0 && decimal == 0)){ // check for Nan
    return uf;
    }
  if(decimal == 0x7FFFFF){ //if the decimal is biggest 23 bit number
    exp += 1; //then exponential +1 and decimal -1
    decimal -= 1;
  }
  else if (exp >  0){ // if the exponitial is greather than 0
    exp += 1;
  }
  else{ // expontial is 0
    decimal = decimal << 1; //just shift the decimal to the left 1 bits to double the value
  }
  return (sign) | (exp << 23) | (decimal);
}

