#pragma once

#include <ostream>

namespace JMath
{

class Vector2
{
public:

  static const Vector2 Zero;
  static const Vector2 One;
  static const Vector2 UnitX;
  static const Vector2 UnitY;

  Vector2() noexcept;
  Vector2( float _x, float _y );
  Vector2( const Vector2& other );
  Vector2( float xy );
  
  Vector2& Set( float _x, float _y );

  float Length() const;
  float LengthSquared() const;

  Vector2& Normalize();
  Vector2 Normalized() const;

  Vector2& Rotate( float radians );
  Vector2 Rotated( float radians ) const;

  float Angle() const;

  float Distance( const Vector2& v ) const;
  float SquareDistance( const Vector2& v ) const;

  Vector2 Midpoint( const Vector2& v ) const;
  Vector2 WeightedMidpoint( const Vector2& v, float weight ) const;

  Vector2 Normal() const;
  Vector2 Abs() const;

  Vector2& operator=( const Vector2& v );
  Vector2& operator=( float f );

  Vector2& operator+=( const Vector2& v );
  Vector2& operator-=( const Vector2& v );

  Vector2& operator+=( float f );
  Vector2& operator-=( float f );
  Vector2& operator*=( float f );
  Vector2& operator/=( float f );

  Vector2 operator+( const Vector2& v ) const;
  Vector2 operator-( const Vector2& v ) const;

  /* Dot Product */
  float operator*( const Vector2& v ) const;

  Vector2 operator+( float f ) const;
  Vector2 operator-( float f ) const;
  Vector2 operator*( float f ) const;
  Vector2 operator/( float f ) const;

  Vector2 operator-() const;

  bool operator==( const Vector2& v ) const;
  bool operator!=( const Vector2& v ) const;

  static float Distance( const Vector2& v1, const Vector2& v2 );
  static float SquareDistance( const Vector2& v1, const Vector2& v2 );

  static Vector2 Midpoint( const Vector2& v1, const Vector2& v2 );
  static Vector2 WeightedMidpoint( const Vector2& v1, const Vector2& v2, float weight );

  static Vector2 Towards( const Vector2& v1, const Vector2& v2 );
  static Vector2 Towards( float x1, float y1, float x2, float y2 );

  static float AngleBetween( const Vector2& v1, const Vector2& v2 );
  static float AngleDifference( const Vector2& v1, const Vector2& v2 );

  friend std::ostream& operator<<(std::ostream& oStream, const Vector2& v);

  union
  {
    struct
    {
      float x;
      float y;
    };

    float data[ 2 ];
  };

};

Vector2 operator+( float f, const Vector2& v );
Vector2 operator-( float f, const Vector2& v );
Vector2 operator*( float f, const Vector2& v );
Vector2 operator/( float f, const Vector2& v );

} // namespace JMath