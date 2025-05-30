#ifndef BASE64_H
#define BASE64_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

const char *base64Encode(const char *input, size_t input_size);

const char *base64Decode(const char *input, size_t input_size);

#ifdef __cplusplus
}
#endif

#endif // BASE64_H
