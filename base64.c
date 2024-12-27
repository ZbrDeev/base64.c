#include "base64.h"
#include <math.h>
#include <stdio.h>
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

  for (int i = 0; i < strlen(input); ++i) {
    for (int j = 7; j >= 0; --j) {
      if (input[i] & (1 << j)) {
        *it = 1;
      }
      ++it;
    }
  }

  int roundedSize = round(size / 6) + (round(size / 6) - 4);
  char *byteBase64 = (char *)calloc(roundedSize + 1, sizeof(char));
  memset(byteBase64, '=', roundedSize);

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
      if (binary[index] == 1) {
        sumOfBit += pow(2, 6 - 1 - j);
      }
      ++index;
    }

    byteBase64[i] = baseAlphabet[sumOfBit];
  }

  free(binary);

  int padding = round((double)size / 6);

  if (padding <= 0) {
    return byteBase64;
  }

  for (int i = padding; i < strlen(byteBase64); ++i) {
    byteBase64[i] = '=';
  }

  return byteBase64;
}

const char *base64Decode(const char *input) {
  int len = 0;

  for (; len < strlen(input); ++len) {
    if (input[len] == '=') {
      break;
    }
  }

  char *resizedInput = (char *)calloc(len + 1, sizeof(char));
  int *binary = (int *)calloc(len * 6, sizeof(int));

  for (int i = 0; i < len; ++i) {
    resizedInput[i] = input[i];
  }

  int *binaryIt = binary;

  for (int i = 0; i < strlen(resizedInput); ++i) {
    int data = 0;
    if ('A' <= resizedInput[i] || resizedInput[i] <= 'Z') {
      data = resizedInput[i] - 0x41;
    } else if ('a' <= resizedInput[i] || resizedInput[i] <= 'z') {
      data = resizedInput[i] - 0x61 + 26;
    } else if ('0' <= resizedInput[i] || resizedInput[i] <= '9') {
      data = resizedInput[i] - 0x61 + 52;
    } else if (resizedInput[i] == '+') {
      data = 62;
    } else if (resizedInput[i] == '/') {
      data = 63;
    }

    for (int i = 0; i < 6; ++i) {
      int pow2 = (int)pow(2, 6 - 1 - i);
      if (data - pow2 >= 0) {
        data -= pow2;
        *binaryIt = 1;
      } else {
        *binaryIt = 0;
      }
      ++binaryIt;
    }
  }

  free(resizedInput);

  binaryIt = binary;

  int size = len * 6 % 8;
  char *result = (char *)calloc(size + 1, sizeof(char));

  for (int i = 0; i < size; ++i) {
    int calcResult = 0;

    for (int j = 0; j < 8; ++j) {
      if (*binaryIt == 1) {
        calcResult += pow(2, 8 - 1 - j);
      }
      ++binaryIt;
    }

    result[i] = (char)calcResult;
  }

  free(binary);

  return result;
}
