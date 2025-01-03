#include "base64.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

static const char baseAlphabet[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

const char *base64Encode(const char *input) {
  int inputSize = strlen(input);
  int roundedSize = 4 * ((inputSize + 2) / 3);
  char *byteBase64 = (char *)calloc(roundedSize + 1, sizeof(char));
  memset(byteBase64, '=', roundedSize);

  const unsigned int size = inputSize * 8;
  char *binary = (char *)calloc(size, sizeof(char));
  memset(binary, '0', size * sizeof(char));

  char *it = binary;

  for (int i = 0; i < inputSize; ++i) {
    for (int j = 7; j >= 0; --j) {
      if (input[i] & (1 << j)) {
        *it = '1';
      }
      ++it;
    }
  }

  int index = 0;

  for (int i = 0; i < strlen(byteBase64); ++i) {
    if (index >= size) {
      break;
    }

    int sumOfBit = 0;

    for (int j = 0; j < 6; ++j) {
      if (index == size) {
        break;
      }
      if (binary[index] == '1') {
        sumOfBit += pow(2, 5 - j);
      }
      ++index;
    }

    byteBase64[i] = baseAlphabet[sumOfBit];
  }

  free(binary);

  return byteBase64;
}

const char *base64Decode(const char *input) {
  int len = strlen(input);

  for (; len > 0; --len) {
    if (input[len] != '=') {
      break;
    }
  }

  char *binary = (char *)calloc(len * 6, sizeof(char));
  memset(binary, '0', len * 6 * sizeof(char));

  int index = 0;

  for (int i = 0; i < len; ++i) {
    int data = 0;
    if ('A' <= input[i] && input[i] <= 'Z') {
      data = input[i] - 0x41;
    } else if ('a' <= input[i] && input[i] <= 'z') {
      data = input[i] - 0x61 + 26;
    } else if ('0' <= input[i] && input[i] <= '9') {
      data = input[i] - 0x30 + 52;
    } else if (input[i] == '+') {
      data = 62;
    } else if (input[i] == '/') {
      data = 63;
    }

    for (int i = 0; i < 6; ++i) {
      int pow2 = (int)pow(2, 5 - i);
      if (data - pow2 >= 0) {
        data -= pow2;
        binary[index] = '1';
      }
      ++index;
    }
  }

  index = 0;

  int size = len * 6 / 8;
  char *result = (char *)calloc(size + 1, sizeof(char));

  for (int i = 0; i < size; ++i) {
    char sumOfBit[8];

    for (int j = 0; j < 8; ++j) {
      sumOfBit[j] = binary[index];
      ++index;
    }

    result[i] = strtol(sumOfBit, 0, 2);
  }

  free(binary);

  return result;
}

#ifdef __cplusplus
}
#endif
