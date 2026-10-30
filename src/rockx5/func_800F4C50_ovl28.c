#include "types.h"

extern int func_8002D6FC();
extern void (*D_800FE36C_ovl28[])(u8* obj, u8* parent);

void func_800F4C50_ovl28(u8* obj) {
    u8* parent = *(u8**)(obj + 0x50);

    obj[0x47] = parent[0x47];
    obj[0x15] = parent[0x15];
    *(s32*)(obj + 0x38) = *(s32*)(parent + 0x38);
    *(s32*)(obj + 0x3C) = *(s32*)(parent + 0x3C);
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    if (*(signed char*)(obj + 4) == 0) {
        if (*(signed char*)(parent + 0x9A) != 0) {
            if (*(signed char*)(parent + 0x9A) > 0) {
                obj[3] = 1;
                *(s16*)(obj + 0x54) = 3;
                *(s16*)(obj + 0x56) = 8;
                *(s16*)(obj + 0x58) = (5 - *(signed char*)(obj + 2)) * 2;
                *(s32*)(obj + 0x8) = *(s32*)(parent + 0x8);
                *(s32*)(obj + 0xC) = *(s32*)(parent + 0xC);
                obj[4] = 1;
                obj[5] = 0;
            } else {
                parent[0x9A] = 0;
            }
        }
    } else if (*(signed char*)(parent + 0x9A) == 0) {
        obj[3] = 0;
        obj[4] = 0;
    } else {
        D_800FE36C_ovl28[*(signed char*)(obj + 5)](obj, parent);
    }
    if (*(signed char*)(parent + 4) == 2) {
        func_8002D6FC(obj);
    }
}
