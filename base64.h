#ifndef BASE64_H
#define BASE64_H

#ifdef __cplusplus
extern "C" {
#endif

const char *base64Encode(const char *input);

const char *base64Decode(const char *input);

#endif // BASE64_H

#ifdef __cplusplus
}
#endif
