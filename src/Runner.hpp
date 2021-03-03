/**
 *  @file   Runner.hpp
 *  @brief  Execution unit (both hypervised and stand-alone).
 *
 *  @author Piotr "asmie" Olszewski
 *
 *  @date   2021.03.03
 */


#ifndef SRC_RUNNER_HPP_
#define SRC_RUNNER_HPP_

class Runner {
public:
	Runner();
	virtual ~Runner();


	void Execute();
};

#endif /* SRC_RUNNER_HPP_ */
