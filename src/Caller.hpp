  /**
 *  @file   Caller.cpp
 *  @brief  Caller abstract class.
 *
 *  @author Piotr "asmie" Olszewski
 *
 *  @date   2021.01.03
 *
 *  Caller abstraction for mapping library and executables call.
 *  There is possibility to call different objects (other binaries etc) using other derviates of this class.
 *
 */

#ifndef CALLER_HPP_
#define CALLER_HPP_

class Caller
{
public:
	void prepare() = 0;

	void call() = 0;
};



#endif /* CALLER_HPP_ */
