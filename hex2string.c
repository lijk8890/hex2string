#include "hex2string.h"

int hex2string(unsigned char *in, int inlen, char *out, int *outlen)
{
    int i = 0;
    char *pos = out;

    if(outlen == NULL || *outlen < 2*inlen + 1)
        return -1;

    for(i = 0; i < inlen; i += 1)
        pos += sprintf(pos, "%02hhx", in[i]);

    *outlen = pos - out + 1;
    return 0;
}

int string2hex(const char *in, unsigned char *out, int *outlen)
{
    int i = 0;
    int j = 0;
    int inlen = strlen(in);
    unsigned char hex[2] = {0};

    if(outlen == NULL || *outlen < inlen/2)
        return -1;

    for(*outlen = 0, i = 0; i < inlen; *outlen += 1, i += 2)
    {
        for(j = 0; j < 2; j += 1)
        {
            if(in[i+j] >= '0' && in[i+j] <= '9')        hex[j] = in[i+j] - '0';
            else if(in[i+j] >= 'a' && in[i+j] <= 'f')   hex[j] = in[i+j] - 'a' + 10;
            else if(in[i+j] >= 'A' && in[i+j] <= 'F')   hex[j] = in[i+j] - 'A' + 10;
            else return -1;
        }
        out[*outlen] = hex[0] << 4 | hex[1];
    }

    return 0;
}
