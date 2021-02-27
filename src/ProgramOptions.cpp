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
#include <string_view>

#include "ProgramOptions.hpp"

int ProgramOptions::registerOption(std::string_view  option, std::string_view help, ProgramOptionFlag flags, std::string_view altoption)
{
	ProgramOption newOption = { .option = option, .help = help, .flags = flags, .alternativeOption = altoption, .result = {false, false, false, false, ""} };

	return (registerOption(newOption));
}

int ProgramOptions::registerOption(ProgramOption option)
{
	int retVal = 0;

	auto it = options_.find(option.option);

	if (it == options_.end() && !option.option.empty())
		options_[option.option] = option;
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
	ProgramOption optionToDelete{};

	optionToDelete.option = option;

	return (unregisterOption(optionToDelete));
}

int ProgramOptions::unregisterOption(ProgramOption option)
{
	int retVal = 0;

	auto it = options_.find(option.option);

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
		auto it = options_.find(argv[i]);
		if (it != options_.end())
		{

		}
	}

	return (retVal);
}


