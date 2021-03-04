/**
 *  @file   DL.hpp
 *  @brief  Dynamic loader interface.
 *
 *  @author Piotr "asmie" Olszewski
 *
 *  @date   2021.03.04
 */

#ifndef SRC_DL_HPP_
#define SRC_DL_HPP_

typedef struct {
	bool lazy;
} DL_FLAGS;

/**
 * Class representing dynamic loader general interface. Interface is os and compiler agnostic allowing other tcall modules to use it the same way.
 */
class DL
{
public:
	/**
	 * Loads library with given name.
	 * @param name name of the library file
	 * @param flags flags used to open library
	 * @return Handle to loaded library or nullptr if library was not loaded due to an error.
	 */
	static void* loadLibrary(const char* name, DL_FLAGS flags);

	/**
	 * Gets function address from the library.
	 * @param libraryHandle handle to the library returned by loadLibrary function
	 * @param functionName name of the function
	 * @return Pointer to the function address or nullptr if function was not found or there was any other error.
	 */
	static void* getFuncAddr(void* libraryHandle, const char *functionName);

};


#endif /* SRC_DL_HPP_ */
