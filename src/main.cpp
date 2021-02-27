  /**
 *  @file   main.cpp
 *  @brief  File with entry point.
 *
 *  @author Piotr "asmie" Olszewski
 *
 *  @date   2019.12.20
 */

#include "ProgramOptions.hpp"

int main(int argc, const char **argv)
{
	ProgramOptions appOptions;

	if (appOptions.parseProgramOptions(argc, argv) < 0)
	{

	}

	return (0);
}
