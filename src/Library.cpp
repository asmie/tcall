/**
 *  @file   Library.cpp
 *  @brief  Libffi library class implementation for calling library routines and using dynamic loader.
 *
 *  @author Piotr "asmie" Olszewski
 *
 *  @date   2021.03.03
 */

#include "Library.hpp"

void Library::execute()
{
	ffi_arg rc;
	void *values[1];

	ffi_call(&cif, FFI_FN(test_fn), &rc, values);
}


