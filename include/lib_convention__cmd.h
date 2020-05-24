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

#ifndef GEN_LIB_CONVENTION__CMD_H_
#define GEN_LIB_CONVENTION__CMD_H_

/* *******************************************************************
 * includes
 * ******************************************************************/

/* *******************************************************************
 * defines
 * ******************************************************************/

/* ************************************************************************//**
 * \brief	Macros which define the number of bits for each bit-region
 * ****************************************************************************/
#define M_CONV__CMD__BITS_NR		8
#define M_CONV__CMD__BITS_TYPE		8
#define M_CONV__CMD__BITS_SIZE		14
#define M_CONV__CMD__BITS_DIR		2

/* ************************************************************************//**
 * \brief	Macros which defines a mask that helps to figure out the value
 * 			of certain bit-ranges
 * ****************************************************************************/
#define M_CONV__CMD__MASK_NR		((1 << M_CONV__CMD__BITS_NR) - 1)
#define M_CONV__CMD__MASK_TYPE		((1 << M_CONV__CMD__BITS_TYPE) - 1)
#define M_CONV__CMD__MASK_SIZE		((1 << M_CONV__CMD__BITS_SIZE) - 1)
#define M_CONV__CMD__MASK_DIR		((1 << M_CONV__CMD__BITS_DIR) - 1)

/* ************************************************************************//**
 * \brief	Macros which define the bit-shifts of the bit-regions that structure
 * 			the command
 * ****************************************************************************/
#define M_CONV__CMD__SHIFT_NR		0
#define M_CONV__CMD__SHIFT_TYPE		(M_CONV__CMD__SHIFT_NR 		+ M_CONV__CMD__BITS_NR)
#define M_CONV__CMD__SHIFT_SIZE		(M_CONV__CMD__BITS_TYPE 	+ M_CONV__CMD__SHIFT_TYPE)
#define M_CONV__CMD__SHIFT_DIR		(M_CONV__CMD__BITS_SIZE 	+ M_CONV__CMD__SHIFT_SIZE)

/* ************************************************************************//**
 * \brief	Macro which helps to define a command for storage-ioctl
 * 			functions
 * ****************************************************************************/
#define M_CONV__CMD__CREATE_CMD(_dir, _type, _nr, _size) 	(	(	(_dir)  << M_CONV__CMD__SHIFT_DIR)	| \
																(	(_type) << M_CONV__CMD__SHIFT_TYPE)	| \
																(	(_nr)   << M_CONV__CMD__SHIFT_NR)	| \
																(	(_size) << M_CONV__CMD__SHIFT_SIZE) \
															)

/* ************************************************************************//**
 * \brief	Macro which specify the bit-value that is used in the type field
 * 			for a particular command
 * ****************************************************************************/
#define M_CONV__CMD__TYPE_NONE		0U
#define M_CONV__CMD__TYPE_WRITE		1U
#define M_CONV__CMD__TYPE_READ		2U

/* ************************************************************************//**
 * \brief	Macro which helps to define the actual commands for a storage-device
 * \param	type 		type of command
 * \param	nr			number
 * \param	size		give the structure
 * ****************************************************************************/
#define M_CONV__CMD__CREATE_CMD_NR(_type, _nr)				\
			M_CONV__CMD__CREATE_CMD(M_CONV__CMD__TYPE_NONE, (_type), (_nr), 0)

#define M_CONV__CMD__CREATE_CMD_READ(_type, _nr, _size)		\
			M_CONV__CMD__CREATE_CMD(M_CONV__CMD__TYPE_READ, (_type), (_nr), sizeof(_size))

#define M_CONV__CMD__CREATE_CMD_WRITE(_type, _nr, _size)		\
			M_CONV__CMD__CREATE_CMD(M_CONV__CMD__TYPE_WRITE,(_type), (_nr), sizeof(_size))

#define M_CONV__CMD__CREATE_CMD_READWRITE(_type, _nr, _size)	\
			M_CONV__CMD__CREATE_CMD(M_CONV__CMD__TYPE_READ | M_CONV__CMD__TYPE_WRITE, (_type), (_nr), sizeof(_size))

/* ************************************************************************//**
 * \brief	Macro which helps to extract the required bits from a command
 * 			that is given to a driver -> note that the command will be shifted
 * 			within this macro, hence, you can compare right away
 * ****************************************************************************/
#define M_CONV__CMD__NR(_cmd)		(((_cmd) >> M_CONV__CMD__SHIFT_NR) 		& M_CONV__CMD__MASK_NR)
#define M_CONV__CMD__DIR(_cmd)		(((_cmd) >> M_CONV__CMD__SHIFT_DIR) 	& M_CONV__CMD__MASK_DIR)
#define M_CONV__CMD__TYPE(_cmd)		(((_cmd) >> M_CONV__CMD__SHIFT_TYPE) 	& M_CONV__CMD__MASK_TYPE)
#define M_CONV__CMD__SIZE(_cmd)		(((_cmd) >> M_CONV__CMD__SHIFT_SIZE)	& M_CONV__CMD__MASK_SIZE)


/* *******************************************************************
 * custom data types (e.g. enumerations, structures, unions)
 * ******************************************************************/


/* *******************************************************************
 * (static) variables declarations
 * ******************************************************************/


/* *******************************************************************
 * static function declarations
 * ******************************************************************/

#endif /* GEN_LIB_CONVENTION__CMD_H_ */
