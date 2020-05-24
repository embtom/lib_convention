/*
 * This file is part of the EMBTOM project
 * Copyright (c) 2018-2020 Thomas Willetal 
 * (https://github.com/embtom)
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef LIB_CONVENTION__MACRO_H_
#define LIB_CONVENTION__MACRO_H_

/* *******************************************************************
 * includes
 * ******************************************************************/
/* c-runtime */
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
/* system */

/* own libs */

/* project */

/* *******************************************************************
 * defines
 * ******************************************************************/

/* ************************************************************************//**
 * \brief  Set alignment to the powers of 2
 *
 * \parm  _size		: unaligned size
 * \parm  _boundary	: boundary size to align
 *
 * 	The (_boundary_mask) value is added to the (_size) so it is at least as
 * 	large as the smallest multiple of the alignment. Then the value is bitwise
 * 	reduced with the assistance of the 1er Compliment to that multiple of the alignment.
 *
 * 	_size 		= 7 (0000 0111)
 * 	_boundary	= 4 -> _boundary_mask 3 (0011)
 *
 * 	(_size + _boundary_mask) & ~(_boundary_mask) 	7 + 3 = 10 (1010) & (1100) =  1000 -> 8
 *
 * * ****************************************************************************/
#define ALIGN(_size, _boundary)     		__ALIGN_MASK(_size, _boundary-1)
#define __ALIGN_MASK(_size,_boundary_mask)  ((_size + _boundary_mask)&~(_boundary_mask))


/* ************************************************************************//**
 * \brief  Set of a bit mask
 *
 * \parm  n	:   Length of bitmask.
 * * ****************************************************************************/
#define BITMASK(n) (((n) < sizeof(1ULL) * CHAR_BIT ? (1ULL << (n)) : 0) - 1ULL)

// set bits [k+1, n] to 1, rest to 0
/* ************************************************************************//**
 * \brief  Set of an bit field mask
 *
 *  Creation of a bit field mask, depending if of the bitnumber
 *  long as 0 <= n < 31 and 0 <= k < 31
 *
 * \parm  n	:   Set of the upper start bit of mask.
 * \parm  k	:   Set of the lower end bit of the mask.
 * * ****************************************************************************/
#define BIT_FIELD_MASK(n, k) ((BITMASK(n+1) >> k) << k)  //BIT_FIELD_MASK

/* ************************************************************************//**
 * \brief  Cast a member of a structure out to the containing structure
 *
 * Routine is derived form the "container_of" macro from the linux kernel
 * http://lxr.free-electrons.com/source/include/linux/kernel.h?v=2.6.31
 *
 * \parm  ptr	:   the pointer to the member.
 * \parm  type	:   the type of the container struct this is embedded in.
 * \parm  member:   the name of the member within the struct.
 *
 * \return  pointer to the parent structure
 * * ****************************************************************************/
#define GET_CONTAINER_OF(ptr, type, member) (void *)( ((char *)(ptr)) - offsetof(type,member) )

/* ************************************************************************//**
 * \brief Set Bit at an specific position
 *
 * \parm  _val	:   register to modify
 * \parm  _bit	:   the type of the container struct this is embedded in.
 * * ****************************************************************************/
#define SET_BITVAL(_val, _bit)		((_val) |= (1 << (_bit)))

/* ************************************************************************//**
 * \brief Clear Bit at an specific position
 *
 * \parm  _val	:   register to modify
 * \parm  _bit	:   the type of the container struct this is embedded in.
 * * ****************************************************************************/
#define CLEAR_BITVAL(_val, _bit) 	((_val) &= ~(1 << (_bit)))

/* ************************************************************************//**
 * \brief Toggle Bit at an specific position
 *
 * \parm  _val	:   register to modify
 * \parm  _bit	:   the type of the container struct this is embedded in.
 * * ****************************************************************************/
#define TOGGLE_BITVAL(_val, _bit) 	((_val) ^= (1 << (_bit)))

/* ************************************************************************//**
 * \brief Bit Position form the first bit that is found
 *
 *	!!!!! Attention it have to be SECURED that "_val > 0" is ensured
 * \parm  _val		:   register to investigate for active bit
 * \parm  _startbit	:   bit number to start investigation
 * \parm  _ret		:   the found bit number is stored at passed to _ret
 * * ****************************************************************************/
#define BIT_POS(_val, _startbit, _ret){		\
		uint32_t bit_pos__value = _val >> _startbit;        \
		_ret = _startbit;										\
		while ((bit_pos__value & 0x1) == 0) 	{				\
			_ret++;												\
			bit_pos__value = (bit_pos__value >> 1);				\
		}														\
}



#endif /* LIB_CONVENTION__MACRO_H_ */
