/*
 * Copyright © 2016 Ikey Doherty
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>

const char a[] = { 0x41, 0x72, 0x65, 0x20, 0x79, 0x6f, 0x75, 0x20, 0x61,
                   0x20, 0x6c, 0x69, 0x61, 0x72, 0x3f, 0x20, 0x0 };

struct b {
        short c;
        const void *d;
};

static struct b f[] =
    { { 0x79,
        (const char[]){
            0x45, 0x78, 0x61, 0x63, 0x74, 0x6c, 0x79, 0x2e, 0x0d, 0x0a, 0x0 } },
      { 0x6E, (const char[]){ 0x4c, 0x69, 0x61, 0x72, 0x2e, 0x0d, 0x0a, 0x0 } },
      {
          0x0, (const char[]){ 0x44, 0x65, 0x6e, 0x69, 0x61, 0x6c, 0x20, 0x69, 0x73, 0x6e,
                               0x27, 0x74, 0x20, 0x73, 0x6f, 0x20, 0x64, 0x69, 0x66, 0x66,
                               0x65, 0x72, 0x65, 0x6e, 0x74, 0x20, 0x66, 0x72, 0x6f, 0x6d,
                               0x20, 0x6c, 0x79, 0x69, 0x6e, 0x67, 0x0d, 0x0a, 0x0 },
      } };

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
        fputs(a, stdout);
        char c = getchar();

        for (size_t i = 0; i < sizeof(f) / sizeof(struct b); i++) {
                if (!f[i].c) {
                        fputs(f[i].d, stdout);
                        return 0;
                }
                if (c == f[i].c || (f[i].c & -33) == c) {
                        fputs(f[i].d, stdout);
                        return 0;
                }
        }
        return 0;
}
