#include "TestUtils.h"

#include <cstdio>
#include <ctime>

void JTest::TestGroup::ExecuteAll() const
{
  for( std::pair< std::string, Test > test : m_tests )
  {
    FormatOutput( test.first, test.second );
  }
}

void JTest::TestGroup::FormatOutput( std::string testName, Test test ) const
{
  clock_t start = clock();
  TestResult testResult = test();
  clock_t end = clock();

  printf( "%s: \t\t %s \t\t in %f milliseconds.\n", 
          testName.c_str(), 
          testResult.result == TestResultType::Success ? "Succeeded" : "Failed",
          ( end - start ) / CLOCKS_PER_SEC * 1000.0 );
}
