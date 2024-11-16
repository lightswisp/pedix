/*
 * Copyright (c) 2024 lightswisp
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#pragma once

#define MODE_32 32 
#define MODE_64 64

#if defined(__x86_64__) || defined(__i386__)
  #define SET_BREAKPOINT asm volatile("int3");
#endif
#define NOT_FOUND -1
#define MAX_OPERAND_STR_LEN 50 
#define MAX_PREFIXES 4
#define MAX_TEXT_LEN 100
#define MAX_PTR_TEXT_LEN 10
#define MAX_SEGMENT_TEXT_LEN 4 
#define MAX_INSTR_SIZE 0x0F
#define BYTE_LEN                                                                \
  0x01 // operand type b (byte, regardless of operand-size attribute)
#define THREE_BYTE_LEN 0x03 // 24-bit
#define WORD_LEN                                                                \
  0x02 // operand type w (word, regardless of operand-size attribute)
#define DOUBLEWORD_LEN                                                          \
  0x04 // operand type v (word or doubleword, depending on operand-size
       // attribute)
#define ADDR_48_LEN                                                             \
  0x06 // operand type p (32-bit or 48-bit pointer, depending on operand-size
       // attribute)
#define QUADWORD_LEN 0x08 // 64-bit

