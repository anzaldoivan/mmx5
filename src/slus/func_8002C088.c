#include "types.h"
#include "addr.h"

extern u32* D_800730AC[];
extern s8 D_800D1C00[];
extern u16 D_8009A790[];
extern u8 D_800C9310;

void func_8002C088(u32 arg0, u32 arg1) {
    u32* tbl;
    u16* src;
    u16* dst;
    u32 bits;
    u16 c;
    s32 r, g, b;
    s32 i;
    u32 n;

    tbl = D_800730AC[D_800D1C00[0xC] * 2 + D_800D1C00[0xD]];
    if (tbl != 0) {
        src = (u16*)D_1F800028;
        dst = D_8009A790;
        for (n = arg0; n < arg1; n++) {
            if ((n & 0x1F) == 0) {
                bits = *tbl++;
            }
            if (bits & 1) {
                for (i = 0; i < 16; i++) {
                    c = *src++;
                    r = (0x1F - (c & 0x1F)) & 0x1F;
                    g = (0x3E0 - (c & 0x3E0)) & 0x3E0;
                    b = (0x7C00 - (c & 0x7C00)) & 0x7C00;
                    if (c == 0) {
                        *dst++ = 0;
                    } else if (r + g + b == 0) {
                        *dst++ = 0x8000;
                    } else {
                        *dst++ = r | g | b | (c & 0x8000);
                    }
                }
            } else {
                for (i = 0; i < 16; i++) {
                    *dst++ = *src++;
                }
            }
            bits >>= 1;
        }
        D_800C9310 = 2;
    }
}
