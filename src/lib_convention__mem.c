/*
 * This file is part of the EMBTOM project
 * Copyright (c) 2018-2019 Thomas Willetal 
 * (https://github.com/tom3333)
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

/* *******************************************************************
 * includes
 * ******************************************************************/

#ifdef CONFIG__FREERTOS_ALLOC
	#include <FreeRTOS.h>
#endif 

#ifdef CONFIG__UNIX_ALLOC
	#include <stdlib.h>
#endif

/* *******************************************************************
 * function definition
 * ******************************************************************/

#ifdef CONFIG__FREERTOS_ALLOC

void* alloc_memory(unsigned int _count, size_t _size)
{
	void *mem;
	mem = (void*)pvPortMalloc(_count * _size);
	if (mem) {
		memset(mem,0,_count * _size);
	}
	return mem;
}


void free_memory(void* _mem) 
{
	if(_mem == NULL) {
		return;
	}
	vPortFree(_mem);
}

#elif defined(CONFIG__UNIX_ALLOC)

void* alloc_memory(unsigned int _count, size_t _size)
{
	void *mem = calloc(_count,_size);
	return mem;
}

void free_memory(void* _mem) 
{
	if(_mem == NULL) {
		return;
	}
	free(_mem);
}


#endif