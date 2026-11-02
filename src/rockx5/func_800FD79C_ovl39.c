#include "types.h"

extern u8* func_8002D1A4();
extern u8* func_8002D0E4(void);

void func_800FD79C_ovl39(u8* arg0) {
    u8* p;
    s32 i;

    p = func_8002D1A4();
    if (p != 0) {
        p[0] = 0x61;
        p[1] = 0x28;
        p[2] = 1;
        *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
        *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        p[0x15] = arg0[0x15];
        *(u16*)(p + 0xA) = *(u16*)(arg0 + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(arg0 + 0xE);
        *(u8**)(p + 0x7C) = arg0;
    }
    for (i = 0; i < 3; i++) {
        p = func_8002D0E4();
        if (p != 0) {
            p[0] = 0x61;
            p[1] = 0x15;
            p[2] = i + 3;
            *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
            *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
            *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
            p[0x15] = arg0[0x15];
            *(u16*)(p + 0xA) = *(u16*)(arg0 + 0xA);
            *(u16*)(p + 0xE) = *(u16*)(arg0 + 0xE);
            *(u8**)(p + 0x50) = arg0;
        }
    }
    *(u16*)(arg0 + 0x82) = 0x78;
    arg0[6]++;
}
