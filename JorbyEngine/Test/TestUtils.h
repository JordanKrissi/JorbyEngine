#pragma once

#include <cassert>
#include <vector>
#include <string>
#include <tuple>

namespace JTest
{

enum class TestResultType
{
  Success = 0,
  Fail = 1
};

struct TestResult
{
  TestResultType result;
};

typedef TestResult (*Test)();

class TestGroup
{
public:
  // TODO (JK): Give ability to add tests

  void ExecuteAll() const;
  void FormatOutput( std::string testName, Test test ) const;
private:
  std::vector< std::pair< std::string, Test > > m_tests;
  bool m_verboseOutput;
};

} // namespace JTest