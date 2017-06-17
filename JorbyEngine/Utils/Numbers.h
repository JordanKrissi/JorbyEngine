#pragma once

namespace JUtils
{

class Numbers
{
public:
 
  /// <summary>
  /// Gives a random number between the minimum and maximum value.
  /// </summary>
  /// <param name="min">The minimum, inclusive.</param>
  /// <param name="max">The maximum, exclusive.</param>
  /// <returns>A random number between the minimum and maximum value.</returns>
  static int Rand( int min, int max ) noexcept;
};

} // namespace JUtils