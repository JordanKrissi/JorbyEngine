#include <cstdlib>

#include "Numbers.h"

int JUtils::Numbers::Rand( int Min, int Max ) noexcept
{
  return rand() % ( Max - Min ) + Min;
}
