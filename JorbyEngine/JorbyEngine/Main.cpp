#include <iostream>
#include <cassert>
#include <time.h>
#include <cstdlib>

#include "Math\JMath.h"
#include "Utils\JUtils.h"

int main()
{
  time_t seconds;

  srand( static_cast< unsigned int >( time( &seconds ) ) );

  for( int i = 0; i < 100000000; ++i )
  {
    JMath::Vector2 v;
    
    v.x = static_cast< float >( JUtils::Numbers::Rand( 0, 100000 ) );
    v.y = static_cast< float >( JUtils::Numbers::Rand( 0, 100000 ) );

    assert( v.x == v.data[ 0 ] );
    assert( v.y == v.data[ 1 ] );
  }

  return 0;
}