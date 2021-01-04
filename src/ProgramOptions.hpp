  /**
 *  @file   ProgramOptions.hpp
 *  @brief  Handles program command-line arguments.
 *
 *  @author Piotr "asmie" Olszewski
 *
 *  @date   2021.01.04
 *
 *  Class that is responsible for parsing command-line options. Class is generic enough to use it in different
 *  applications - handles short options, long options, different delimeters etc.
 *
 *  Every option is considered to be string type - no matter if it's -3 or --help - either 3 and help is passed as string.
 *  Every argument that is passed to the option is also considered as string type - ProgramOptions does not make any
 *  conversions as it could be too complicated (eg. there can be params like --something param1,param2,param3 - in such case
 *  there will be only one option for the argument something and it'll be "param1,param2,param3").
 *  The upper program logic is responsible for parameters and options recognition and validation.
 *
 */

#ifndef PROGRAMOPTIONS_HPP_
#define PROGRAMOPTIONS_HPP_

#include <map>

typedef enum
{
	ShortOption = 0x1,
	LongOption = 0x2,
	HelpOption = 0x4,
	ParamRequired = 0x8,
	CanBeRepeated = 0x16
} ProgramOptionFlag;


class ProgramOptions
{
public:
	int registerOption(const char *option, const char *help, ProgramOptionFlag flags, const char *altoption = nullptr);
	int unregisterOption(const char *option);

	int parseProgramOptions(unsigned int argc, const char **argv);

	const char *getDelimeter() const;
	int setDelimeter(const char *delimeter);

private:

	std::map<const char*, const char*> parsedOptions;

	char *delimeter;
};




#endif /* PROGRAMOPTIONS_HPP_ */
