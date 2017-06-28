#pragma once

namespace JMath
{

class Vector2
{
public:

  Vector2() noexcept;

  // TODO (JK): Make these lower-case arguments
  Vector2( float X, float Y ) noexcept;

  // TODO (JK): Make these lower-case arguments
  Vector2( const Vector2& Other ) noexcept;

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

} // namespace JMath