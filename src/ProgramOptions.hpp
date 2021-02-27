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

#include <unordered_map>
#include <vector>
#include <string>
#include <string_view>

typedef enum
{
	ShortOption = 0x1,
	LongOption = 0x2,
	HelpOption = 0x4,
	ParamRequired = 0x8,
	CanBeRepeated = 0x16,
	MandatoryOption = 0x32
} ProgramOptionFlag;

typedef struct {
	bool wasFound{false};
	bool hasError{false};
	bool argumentFound{false};
	bool argumentError{false};

	std::string_view argumentValue{};
} ProgramOptionResult;

typedef struct ProgramOptionStructure
{
	std::string_view option;
	std::string_view help;
	ProgramOptionFlag flags;
	std::string_view alternativeOption;

	bool operator==(const ProgramOptionStructure &rhs)
	{
		return (option.compare(rhs.option) == 0);
	}

	ProgramOptionResult result;
} ProgramOption;


class ProgramOptions
{
public:
	int registerOption(std::string_view  option, std::string_view help, ProgramOptionFlag flags, std::string_view altoption = std::string_view());
	int registerOption(ProgramOption option);
	int registerOptions(std::vector<ProgramOption> options);
	int unregisterOption(std::string_view option);
	int unregisterOption(ProgramOption option);

	int parseProgramOptions(unsigned int argc, const char **argv);

	std::string_view getLongOptionDelimeter() const
	{
		return (longOptionDelimeter_);
	}

	void setLongOptionDelimeter(std::string_view delimeter)
	{
		longOptionDelimeter_ = delimeter;
	}

	std::string_view getShortOptionDelimeter() const
	{
		return (shortOptionDelimeter_);
	}

	void setShortOptionDelimeter(std::string_view delimeter)
	{
		shortOptionDelimeter_ = delimeter;
	}

private:
	std::unordered_map <std::string_view, ProgramOption> options_;

	std::string_view longOptionDelimeter_;
	std::string_view shortOptionDelimeter_;
};


#endif /* PROGRAMOPTIONS_HPP_ */
