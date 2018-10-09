#ifndef __HEX2STRING_H__
#define __HEX2STRING_H__

#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

int hex2string(unsigned char *in, int inlen, char *out, int *outlen);

int string2hex(const char *in, unsigned char *out, int *outlen);

#ifdef __cplusplus
}
#endif

#endif
