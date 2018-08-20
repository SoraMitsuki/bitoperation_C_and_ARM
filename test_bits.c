/* Testing Code */

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include "bits.h"

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

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

int test_bitAnd(int x, int y)
{
  return x&y;
}
int test_getByte(int x, int n)
{
    unsigned char byte;
    switch(n) {
    case 0:
      byte = x;
      break;
    case 1:
      byte = x >> 8;
      break;
    case 2:
      byte = x >> 16;
      break;
    default:
      byte = x >> 24;
      break;
    }
    return (int) (unsigned) byte;
}
int test_logicalShift(int x, int n) {
  unsigned u = (unsigned) x;
  unsigned shifted = u >> n;
  return (int) shifted;
}
int test_bitCount(int x) {
  int result = 0;
  int i;
  for (i = 0; i < 32; i++)
    result += (x >> i) & 0x1;
  return result;
}
int test_bang(int x)
{
  return !x;
}
int test_tmin(void) {
  return 0x80000000;
}
int test_fitsBits(int x, int n)
{
  int TMin_n = -(1 << (n-1));
  int TMax_n = (1 << (n-1)) - 1;
  return x >= TMin_n && x <= TMax_n;
}
int test_divpwr2(int x, int n)
{
    int p2n = 1<<n;
    return x/p2n;
}
int test_negate(int x) {
  return -x;
}
int test_isPositive(int x) {
  return x > 0;
}
int test_isLessOrEqual(int x, int y)
{
  return x <= y;
}
int test_ilog2(int x) {
  int mask, result;
  /* find the leftmost bit */
  result = 31;
  mask = 1 << result;
  while (!(x & mask)) {
    result--;
    mask = 1 << result;
  }
  return result;
}
unsigned test_float_neg(unsigned uf) {
    float f = u2f(uf);
    float nf = -f;
    if (isnan(f))
 return uf;
    else
 return f2u(nf);
}
unsigned test_float_i2f(int x) {
  float f = (float) x;
  return f2u(f);
}
unsigned test_float_twice(unsigned uf) {
  float f = u2f(uf);
  float tf = 2*f;
  if (isnan(f))
    return uf;
  else
    return f2u(tf);
}


int main(int argc, char *argv[]){

//Test Cases for bitAnd 

assert(bitAnd(7,8)==test_bitAnd(7,8)); 
assert(bitAnd(1,3)==test_bitAnd(1,3));
assert(bitAnd(9,8)==test_bitAnd(9,8));
assert(bitAnd(0,6)==test_bitAnd(0,6));
assert(bitAnd(255,254)==test_bitAnd(255,254));
printf("Passed Test Cases for bitAnd\n");

//Test case for get Byte
assert(getByte(0x12345678, 1) == test_getByte(0x12345678, 1));
assert(getByte(55, 2) == test_getByte(55, 2));
assert(getByte(-4, 1) == test_getByte(-4, 1));
printf("Passed Test Cases for getByte\n");

//Test case for logicalShift
assert(logicalShift(0x12345678, 4) == test_logicalShift(0x12345678, 4));
assert(logicalShift(88, 2) == test_logicalShift(88, 2));
assert(logicalShift(-3, 1) == test_logicalShift(-3, 1));
assert(logicalShift(-4, 1) == test_logicalShift(-4, 1));
assert(logicalShift(-5, 0) == test_logicalShift(-5, 0));
assert(logicalShift(22, 0) == test_logicalShift(22, 0));
printf("Passed Test Cases for logicalShift\n");

//Test case for Bang
assert(bang(0x12345678) == test_bang(0x12345678));
assert(bang(4) == test_bang(4));
assert(bang(0) == test_bang(0));
assert(bang(-1) == test_bang(-1));
assert(bang(2) == test_bang(2));
assert(bang(-1) == test_bang(-1));
assert(bang(-127) == test_bang(-127));
assert(bang(128) == test_bang(128));
assert(bang(-2) == test_bang(-2));
assert(bang(0) == test_bang(0));
printf("Passed Test Case for Bang\n");

//Test case for tmin
assert(tmin() == test_tmin());
printf("Passed Test Case for tmin\n");

//Test case for fitbits
assert(fitsBits(5,1) == test_fitsBits(5,1));
assert(fitsBits(-4,3) == test_fitsBits(-4,3));
printf("Passed Test Case for Fitbits\n");

//Test case for negate
assert(negate(0x3456) == test_negate(0x3456));
assert(negate(-5) == test_negate(-5));
printf("Pass Test Case for Negate\n");

//Test case for isPositive
assert(isPositive(-5) == test_isPositive(-5));
assert(isPositive(5) == test_isPositive(5));
assert(isPositive(0) == test_isPositive(0));
printf("Pass Test Case for isPositive\n");

//Test case for isLessOrEqual
assert(isLessOrEqual(5,8) == test_isLessOrEqual(5,8));
assert(isLessOrEqual(8,5) == test_isLessOrEqual(8,5));
assert(isLessOrEqual(-4,-4) == test_isLessOrEqual(-4,-4));
printf("Pass Test Case for isLessOrEqual\n");

//Test Case for divpwr2
assert(divpwr2(0, 0) == test_divpwr2(0, 0));
assert(divpwr2(5, 0) == test_divpwr2(5, 0));
assert(divpwr2(-3, 0) == test_divpwr2(-3, 0));
assert(divpwr2(0, 1) == test_divpwr2(0, 1));
assert(divpwr2(0, 2) == test_divpwr2(0, 2));
assert(divpwr2(0, 30) == test_divpwr2(0, 30));
assert(divpwr2(5, 1) == test_divpwr2(5, 1));
assert(divpwr2(5, 2) == test_divpwr2(5, 2));
assert(divpwr2(5, 30) == test_divpwr2(5, 30));
assert(divpwr2(-3, 1) == test_divpwr2(-3, 1));
assert(divpwr2(-3, 2) == test_divpwr2(-3, 2));
assert(divpwr2(-3, 30) == test_divpwr2(-3, 30));
printf("Pass Test Case for divpwr2\n");

//Test Case for BitCount
assert(bitCount(0x11111111) == test_bitCount(0x11111111));
assert(bitCount(0xFFFFFFFF) == test_bitCount(0xFFFFFFFF));
assert(bitCount(0) == test_bitCount(0));
printf("Pass Test Case for bitCount\n");

//Test Case for ilog2
assert(ilog2(143) == test_ilog2(143));
assert(ilog2(143) == test_ilog2(143));
assert(ilog2(0xFFFFFF) == test_ilog2(0xFFFFFF));
printf("Pass Test Case for ilog2\n");

//Test Case for float_neg
assert(float_neg(0x12345678) == test_float_neg(0x12345678));
assert(float_neg(0x7FC00000) == test_float_neg(0x7FC00000));
//assert(float_neg(0xFFFFFFFF) == test_float_neg(0xFFFFFFFF));
assert(float_neg(0x0) == test_float_neg(0x0));
printf("Pass Test Case for float_neg\n");
//Test Case for float_i2f
assert(float_i2f(0x12345678) == test_float_i2f(0x12345678));
assert(float_i2f(0x7FC00000) == test_float_i2f(0x7FC00000));
assert(float_i2f(0) == test_float_i2f(0));
printf("Pass Test Case for float_i2f\n");
//Test Case for float_twice
assert(float_twice(0x12345678) == test_float_twice(0x12345678));
assert(float_twice(0x7FC00000) == test_float_twice(0x7FC00000));
assert(float_twice(0x0) == test_float_twice(0x0));
printf("Pass Test Case for float_twice\n");

return 0;

}
