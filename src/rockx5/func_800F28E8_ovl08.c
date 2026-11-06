#include "types.h"

extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);

void func_800F28E8_ovl08(u8* parent) {
    u8* o;
    u16 dx;
    u16 dy;

    o = func_8002D27C();
    if (o != 0) {
        o[0] = 0x41;
        o[1] = 0x24;
        o[2] = 0;
        *(u16*)(o + 0x40) = *(u16*)(parent + 0x40);
        *(u16*)(o + 0x42) = *(u16*)(parent + 0x42) & 0x7FFF;
        *(s32*)(o + 0x30) = *(s32*)(parent + 0x30);
        *(s32*)(o + 0x3C) = *(s32*)(parent + 0x3C);
        o[0x14] = parent[0x14];
        *(u8**)(o + 0x50) = parent;
        dx = func_8002DF78() & 0x3F;
        dy = func_8002DF78() & 0x1F;
        if (func_8002DF78() & 1) {
            *(u16*)(o + 0xA) = *(u16*)(parent + 0xA) + dx;
        } else {
            *(u16*)(o + 0xA) = *(u16*)(parent + 0xA) - dx;
        }
        if (func_8002DF78() & 1) {
            *(u16*)(o + 0xE) = *(u16*)(parent + 0xE) + dy;
        } else {
            *(u16*)(o + 0xE) = *(u16*)(parent + 0xE) - dy;
        }
        *(u16*)(o + 0x8) = 0;
        *(u16*)(o + 0xC) = 0;
    }
}
