#include "Vector2.h"

#include <cassert>
#include <math.h>

#include "Utils\Numbers.h"

const JMath::Vector2 JMath::Vector2::Zero( 0.0f );
const JMath::Vector2 JMath::Vector2::One( 1.0f );
const JMath::Vector2 JMath::Vector2::UnitX( 1.0f, 0.0f );
const JMath::Vector2 JMath::Vector2::UnitY( 0.0f, 1.0f );

JMath::Vector2::Vector2() noexcept : x( 0.0f ), y( 0.0f )
{
}

JMath::Vector2::Vector2( float _x, float _y ) : x( _x ), y( _y )
{
}

JMath::Vector2::Vector2( const Vector2& other ) : x( other.x ), y( other.y )
{
}

JMath::Vector2::Vector2( float xy ) : x( xy ), y( xy )
{
}

JMath::Vector2& JMath::Vector2::Set( float _x, float _y )
{
  x = _x;
  y = _y;

  return *this;
}

float JMath::Vector2::Length() const
{
  return std::sqrt( LengthSquared() );
}

float JMath::Vector2::LengthSquared() const
{
  return (x * x) + (y * y);
}

JMath::Vector2& JMath::Vector2::Normalize()
{
  float length = Length();

  assert( length > EPSILON );

  x /= length;
  y /= length;

  return *this;
}

JMath::Vector2 JMath::Vector2::Normalized() const
{
  float length = Length();
  
  assert( length > EPSILON );

  return Vector2( x / length, y / length );
}

JMath::Vector2& JMath::Vector2::Rotate( float radians )
{
  float cos = std::cos( radians );
  float sin = std::sin( radians );

  x = ( x * cos ) - ( y * sin );
  y = ( x * sin ) + ( y * cos );

  return *this;
}

JMath::Vector2 JMath::Vector2::Rotated( float radians ) const
{
  float cos = std::cos( radians );
  float sin = std::sin( radians );

  return Vector2( (x * cos ) - ( y * sin ), ( x * sin ) - ( y * cos ) );
}

float JMath::Vector2::Angle() const
{
  return std::atan2( y, x );
}

float JMath::Vector2::Distance( const Vector2 & v ) const
{
  return std::sqrt( SquareDistance( v ) );
}

float JMath::Vector2::SquareDistance( const Vector2 & v ) const
{
  return ( x - v.x ) * ( x - v.x ) + ( y - v.y ) * ( y - v.y );
}

JMath::Vector2 JMath::Vector2::Midpoint( const Vector2 & v ) const
{
  return Vector2( ( x + v.x ) / 2.0f, ( y + v.y ) / 2.0f );
}

JMath::Vector2 JMath::Vector2::WeightedMidpoint( const Vector2 & v, float weight ) const
{
  return Vector2( ( x * ( 1.0f - weight ) + v.x * weight ) / 2.0f, ( y * ( 1.0f - weight ) + v.y * weight ) / 2.0f );
}

JMath::Vector2 JMath::Vector2::Normal() const
{
  return Vector2( -y, x );
}

JMath::Vector2 JMath::Vector2::Abs() const
{
  return Vector2( ( x > 0.0f ) ? x : -x, ( y > 0.0f ) ? x : -x );
}

JMath::Vector2& JMath::Vector2::operator=( const Vector2 & v )
{
  x = v.x;
  y = v.y;

  return *this;
}

JMath::Vector2& JMath::Vector2::operator=( float f )
{
  x = f;
  y = f;
  
  return *this;
}

JMath::Vector2& JMath::Vector2::operator+=( const Vector2 & v )
{
  x += v.x;
  y += v.y;

  return *this;
}

JMath::Vector2& JMath::Vector2::operator-=( const Vector2 & v )
{
  x -= v.x;
  y -= v.y;

  return *this;
}

JMath::Vector2& JMath::Vector2::operator+=( float f )
{
  x += f;
  y += f;

  return *this;
}

JMath::Vector2& JMath::Vector2::operator-=( float f )
{
  x -= f;
  y -= f;

  return *this;
}

JMath::Vector2& JMath::Vector2::operator*=( float f )
{
  x *= f;
  y *= f;

  return *this;
}

JMath::Vector2& JMath::Vector2::operator/=( float f )
{
  x /= f;
  y /= f;

  return *this;
}

JMath::Vector2 JMath::Vector2::operator+( const Vector2 & v ) const
{
  return Vector2( x + v.x, y + v.y );
}

JMath::Vector2 JMath::Vector2::operator-( const Vector2 & v ) const
{
  return Vector2( x - v.x, y - v.y );
}

float JMath::Vector2::operator*( const Vector2 & v ) const
{
  return x * v.x + y * v.y;
}

JMath::Vector2 JMath::Vector2::operator+( float f ) const
{
  return Vector2( x + f, y + f );
}

JMath::Vector2 JMath::Vector2::operator-( float f ) const
{
  return Vector2( x - f, y - f );
}

JMath::Vector2 JMath::Vector2::operator*( float f ) const
{
  return Vector2( x * f, y * f );
}

JMath::Vector2 JMath::Vector2::operator/( float f ) const
{
  return Vector2( x / f, y / f );
}

JMath::Vector2 JMath::Vector2::operator-() const
{
  return Vector2( -x, -y );
}

bool JMath::Vector2::operator==( const Vector2 & v ) const
{
  return x == v.x && y == v.y;
}

bool JMath::Vector2::operator!=( const Vector2 & v ) const
{
  return x != v.x || y != v.y;
}

float JMath::Vector2::Distance( const Vector2 & v1, const Vector2 & v2 )
{
  return v1.Distance( v2 );
}

float JMath::Vector2::SquareDistance( const Vector2 & v1, const Vector2 & v2 )
{
  return v1.SquareDistance( v2 );
}

JMath::Vector2 JMath::Vector2::Midpoint( const Vector2 & v1, const Vector2 & v2 )
{
  return v1.Midpoint( v2 );
}

JMath::Vector2 JMath::Vector2::WeightedMidpoint( const Vector2 & v1, const Vector2 & v2, float weight )
{
  return v1.WeightedMidpoint( v2, weight );
}

JMath::Vector2 JMath::Vector2::Towards( const Vector2 & v1, const Vector2 & v2 )
{
  return v2 - v1;
}

JMath::Vector2 JMath::Vector2::Towards( float x1, float y1, float x2, float y2 )
{
  return Vector2( x2 - x1, y2 - y1 );
}

float JMath::Vector2::AngleBetween( const Vector2 & v1, const Vector2 & v2 )
{
  return std::acos( v1.Normalized() * v2.Normalized() );
}

float JMath::Vector2::AngleDifference( const Vector2 & v1, const Vector2 & v2 )
{
  return v1.Angle() - v2.Angle();
}

std::ostream & JMath::operator<<( std::ostream & oStream, const Vector2 & v )
{
  oStream << "(" << v.x << ", " << v.y << ")";
  
  return oStream;
}

JMath::Vector2 JMath::operator+( float f, const Vector2 & v )
{
  return v + f;
}

JMath::Vector2 JMath::operator-( float f, const Vector2 & v )
{
  return v - f;
}

JMath::Vector2 JMath::operator*( float f, const Vector2 & v )
{
  return v * f;
}

JMath::Vector2 JMath::operator/( float f, const Vector2 & v )
{
  return v / f;
}
