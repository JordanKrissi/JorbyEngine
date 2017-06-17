#pragma once

namespace JMath
{

class Vector2
{
public:

  Vector2() noexcept;
  Vector2( float X, float Y ) noexcept;
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