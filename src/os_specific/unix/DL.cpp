/**
 *  @file   DL.cpp
 *  @brief  Dynamic loader Unix implementation.
 *
 *  @author Piotr "asmie" Olszewski
 *
 *  @date   2021.03.04
 */

#include "DL.hpp"

#include <dlfcn.h>

void* DL::loadLibrary(const char *name, DL_FLAGS flags)
{
	void *instance = nullptr;

	instance = dlopen(name, flags.lazy ? RTLD_LAZY : RTLD_NOW);

	return (instance);
}

void* DL::getFuncAddr(void* libraryHandle, const char* functionName)
{
	void* addr = nullptr;

	addr = dlsym(libraryHandle, functionName);

	return (addr);
}
