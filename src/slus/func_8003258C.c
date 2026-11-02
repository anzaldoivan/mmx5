#include "types.h"

extern u8 D_80092090[];
extern s32 func_80032A0C(u8* arg0, u8* arg1);
extern s32 func_80033160(u8* arg0, u8* arg1);
extern s32 func_8002F150(void* arg0, void* arg1);

void func_8003258C(u8* arg0) {
    u8* p;
    s32* word;
    s32 mask;
    s32 save8;
    s32 saveC;
    s32 i;
    s32 idx;
    s32 base;
    u8 flags;

    i = 0;
    if (*(s32*)(arg0 + 0x68) != 0) {
        p = D_80092090;
        do {
            if (*(s8*)p != 0) {
                save8 = *(s32*)(p + 8);
                saveC = *(s32*)(p + 0xC);
                func_80032A0C(arg0, p);
                idx = (i >> 5) << 2;
                base = (s32)arg0 + 0x98;
                word = (s32*)(base + idx);
                mask = 1 << (i & 0x1F);
                if (*word & mask) {
                    func_80033160(arg0, p);
                }
                if (func_8002F150(arg0, p) == 8) {
                    *word |= mask;
                } else {
                    *word &= ~mask;
                    flags = p[0x70];
                    if ((flags & 0xC) == 0xC || (flags & 3) == 3) {
                        *(s32*)(p + 8) = save8;
                        *(s32*)(p + 0xC) = saveC;
                    }
                }
            }
            i++;
            p += 0x9C;
        } while (i < 0x30);
    }
}
