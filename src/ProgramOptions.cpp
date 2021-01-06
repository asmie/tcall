  /**
 *  @file   ProgramOptions.cpp
 *  @brief  Handles program command-line arguments.
 *
 *  @author Piotr "asmie" Olszewski
 *
 *  @date   2021.01.04
 *
 */

#include <algorithm>

#include "ProgramOptions.hpp"

int ProgramOptions::registerOption(std::string_view  option, std::string_view help, ProgramOptionFlag flags, std::string_view altoption)
{
	ProgramOption newOption = { .option = option, .help = help, .flags = flags, .alternativeOption = altoption};

	return (registerOption(newOption));
}

int ProgramOptions::registerOption(ProgramOption option)
{
	int retVal = 0;

	auto it = std::find(options_.begin(), options_.end(), option);

	if (it == options_.end() && !option.option.empty())
		options_.push_back(option);
	else
		retVal = -1;

	return (retVal);
}

int ProgramOptions::registerOptions(std::vector<ProgramOption> options)
{
	int retVal = 0;

	for (ProgramOption &i : options)
		retVal += registerOption(i);	// registerOption return negative when fail so we need to add it
										// otherwise we'd have minus and minus which can lead to positive number in case of errors.

	return (retVal);
}

int ProgramOptions::unregisterOption(std::string_view option)
{
	ProgramOption optionToDelete = { .option = option };

	return (unregisterOption(optionToDelete));
}

int ProgramOptions::unregisterOption(ProgramOption option)
{
	int retVal = 0;

	auto it = std::find(options_.begin(), options_.end(), option);

	if (it != options_.end())
		options_.erase(it);
	else
		retVal = -1;

	return (retVal);
}

int ProgramOptions::parseProgramOptions(unsigned int argc, const char **argv)
{
	int retVal = 0;

	for (unsigned int i = 1; i < argc; i++)
	{

	}

	return (retVal);
}


