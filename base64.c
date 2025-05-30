#include "base64.h"
#include <stdbool.h>
#include <stdlib.h>

static const char base_alphabet[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

const char *base64Encode(const char *input, size_t input_size) {
  int rounded_size = 4 * ((input_size + 2) / 3);

  char *byte_base64 = (char *)malloc(rounded_size + 1);
  byte_base64[rounded_size] = '\0';

  char *it = (char *)input;
  char result = 0;
  char result_it = 0;
  size_t base64_it = 0;

  for (size_t i = 0; i <= input_size * 8; ++i) {
    bool bit = (*it >> (7 - (i % 8))) & 1;

    result |= bit << (5 - result_it);

    if (++result_it == 6) {
      result_it = 0;
      byte_base64[base64_it++] = base_alphabet[(size_t)result];
      result = 0;
    }

    if (i != 0 && !(i % 8)) {
      ++it;
    }
  }

  if (result > 0) {
    byte_base64[base64_it++] = base_alphabet[(size_t)result];
  }

  for (; base64_it < rounded_size; ++base64_it) {
    byte_base64[base64_it] = '=';
  }

  return byte_base64;
}

const char *base64Decode(const char *input, size_t input_size) {
  while (input[input_size - 1] != '=') {
    --input_size;
  }

  size_t result_len = input_size * 6 / 8;
  char *result = (char *)malloc(result_len + 1);
  result[result_len] = '\0';

  size_t base64_it = 0;
  size_t it_count = 0;
  char result_it = 0;

  for (size_t i = 0; i <= input_size; ++i) {
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

    for (int j = 5; j >= 0; --j) {
      bool bit = (data >> j) & 1;

      result_it |= bit << (7 - it_count);

      if (++it_count == 8) {
        it_count = 0;
        result[base64_it++] = (char)result_it;
        result_it = 0;
      }
    }
  }

  return result;
}