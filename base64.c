#include "base64.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

static const char baseAlphabet[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

const char *base64Encode(const char *input) {
  const unsigned int size = strlen(input) * 8;
  int *binary = (int *)calloc(size, sizeof(int));

  int *it = binary;
  const char *inputIt = input;

  while (*inputIt != '\0') {
    for (int i = 7; i >= 0; --i) {
      if (*inputIt & (1 << i)) {
        *it = 1;
      }
      ++it;
    }
    ++inputIt;
  }

  int roundedSize = round(size / 6) + (round(size / 6) - 4);
  char *byteBase64 = (char *)malloc(roundedSize + 1);
  memset(byteBase64, '=', roundedSize);
  byteBase64[roundedSize + 1] = '\0';

  it = binary;
  char *base64 = byteBase64;
  int index = 0;

  while (*base64 != '\0') {
    if (index == size) {
      break;
    }
    int sumOfBit = 0;

    for (int i = 0; i < 6; ++i) {
      if (*it == 1) {
        sumOfBit += pow(2, 6 - 1 - i);
      }
      ++index;
      ++it;
    }

    *base64 = baseAlphabet[sumOfBit];
    ++base64;
  }

  free(it);
  free(binary);

  int padding = round((double)size / 6);

  if (padding <= 0) {
    return byteBase64;
  }

  base64 = byteBase64;
  base64 += padding;
  while (*base64 != '\0') {
    *base64 = '=';
    ++base64;
  }

  free(base64);

  return byteBase64;
}
