#include "types.h"

extern u8* func_8003D3A8(s32, s32, s32, u8*);
extern u8 D_8009A0A0[];
extern void* D_80077120[];
extern s8 D_800770E8[][3];

void func_800490BC(u8* obj) {
    u8* g;
    s32 hit;

    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    g = D_8009A0A0;
    hit = ((s8*)g)[0xD3] != 0;
    if (((s8*)g)[0xD4] != 0) {
        hit = 1;
    }
    if (((s8*)g)[0x93] != 5) {
        hit = 1;
    }
    if (((s8*)g)[0x96] == 0xE) {
        hit = 1;
    }
    if (hit != 0) {
        obj[0x8C] = 100;
        obj[0x4] = 2;
    }
    ((void (*)(u8*))D_80077120[((s8*)obj)[0x4]])(obj);
    if (((s8*)obj)[0x4] != 2) {
        obj[0x8C]++;
        if (obj[0x8C] >= 100) {
            obj[0x8C] = 100;
        }
        if (((s8*)obj)[0x2] == 0 && (obj[0x8C] == 4 || obj[0x8C] == 8)) {
            func_8003D3A8(1, ((s8*)obj)[0x1],
                          D_800770E8[obj[0x8D]][((volatile u8*)obj)[0x8C] >> 2],
                          obj); // !FAKE: volatile forces the byte reload
        }
    }
}
