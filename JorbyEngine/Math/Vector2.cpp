#include "Vector2.h"

JMath::Vector2::Vector2() noexcept : x( 0.0f ), y( 0.0f )
{
}

JMath::Vector2::Vector2( float X, float Y ) noexcept : x( X ), y( Y )
{
}

JMath::Vector2::Vector2( const Vector2& Other ) noexcept : x( Other.x ), y( Other.y )
{
}
