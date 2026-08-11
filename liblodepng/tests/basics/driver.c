#include <lodepng.h>

#include <stdlib.h>
#include <string.h>

#undef NDEBUG
#include <assert.h>

int main (void)
{
  unsigned char image[4] = {255, 0, 0, 255};
  unsigned char* png = NULL;
  size_t pngsize = 0;
  unsigned error;

  assert (LODEPNG_VERSION_STRING != NULL);
  assert (LODEPNG_VERSION_STRING[0] != '\0');

  error = lodepng_encode32 (&png, &pngsize, image, 1, 1);
  assert (error == 0);
  assert (png != NULL);
  assert (pngsize != 0);

  {
    unsigned char* decoded = NULL;
    unsigned w = 0;
    unsigned h = 0;

    error = lodepng_decode32 (&decoded, &w, &h, png, pngsize);
    assert (error == 0);
    assert (w == 1 && h == 1);
    assert (decoded != NULL);
    assert (decoded[0] == 255);
    assert (decoded[1] == 0);
    assert (decoded[2] == 0);
    assert (decoded[3] == 255);

    free (decoded);
  }

  free (png);
  return 0;
}
