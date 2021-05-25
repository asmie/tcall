/**
 *  @file   main_tests.cpp
 *  @brief  Main testing file.
 *
 *  @author Piotr Olszewski     piotr.olszewski@transbit.com.pl
 *
 *  @date   2021.05.25
 *
 * Main testing file.
 *
 */

#include <limits.h>
#include "gtest/gtest.h"

int main(int argc, char **argv)
{

  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}


