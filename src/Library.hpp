/**
 *  @file   Library.hpp
 *  @brief  Library handling class interface.
 *
 *  @author Piotr "asmie" Olszewski
 *
 *  @date   2021.03.03
 *
 *  Implementation is os and compiler-dependent as it uses libffi.
 */

#ifndef SRC_LIBRARY_HPP_
#define SRC_LIBRARY_HPP_

#include <ffi.h>

class Library
{
public:

	void execute();
private:
	ffi_cif cif;
	void *test_fn;
};


#endif /* SRC_LIBRARY_HPP_ */
