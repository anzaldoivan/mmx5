#include "types.h"

extern u8* func_8003D3A8(s32, s32, s32, u8*);
extern s32 func_8002DF78(void);
extern void func_8002E058(void*, s32);
extern u8 D_80077084[][5];
extern u8 D_80077080[];

void func_80047E3C(u8* o) {
    u8* p;

    if (--o[0x8D] == 0) {
        goto done; // !FAKE: goto kept for the matching branch layout
    }
    if (*(s8*)(o + 0x98) != 0) {
        if (++o[0x8E] >= 3) {
        done: // !FAKE: shared exit label
            o[4] = 2;
            return;
        }
    }
    if (o[0x90] < 3) {
        if (--o[0x8F] == 0) {
            p = func_8003D3A8(1, *(s8*)(o + 1), 1, o);
            if (p != 0) {
                func_8002E058(p, D_80077084[o[0x8C]][func_8002DF78() % 5]);
                *(u16*)(p + 0xA) = *(u16*)(o + 0xA);
                *(u16*)(p + 0xE) = *(u16*)(o + 0xE);
                *(s32*)(p + 0x20) <<= 2;
                *(s32*)(p + 0x24) <<= 2;
                o[0x90]++;
            }
            o[0x8F] = D_80077080[func_8002DF78() & 3];
        }
    }
}
