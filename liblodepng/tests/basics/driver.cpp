#include <lodepng.h>

#include <vector>

#undef NDEBUG
#include <cassert>

int main ()
{
  // Verify a non-inline exported symbol is linked.
  //
  assert (LODEPNG_VERSION_STRING != nullptr);
  assert (LODEPNG_VERSION_STRING[0] != '\0');

  // Encode a 1x1 red RGBA pixel, then decode it back.
  //
  std::vector<unsigned char> image = {255, 0, 0, 255};
  std::vector<unsigned char> png;

  unsigned error = lodepng::encode (png, image, 1, 1);
  assert (error == 0);
  assert (!png.empty ());

  std::vector<unsigned char> decoded;
  unsigned w = 0;
  unsigned h = 0;
  error = lodepng::decode (decoded, w, h, png);
  assert (error == 0);
  assert (w == 1 && h == 1);
  assert (decoded.size () == 4);
  assert (decoded[0] == 255);
  assert (decoded[1] == 0);
  assert (decoded[2] == 0);
  assert (decoded[3] == 255);
}
