#include "types.h"

extern u8* func_8002C938();
extern s32 func_8002DF78(void);

void func_800FAD04_ovl27(u8* arg0, u8 arg1, s8 arg2) {
    s32 kind;
    u8* obj;

    kind = arg1;
    obj = func_8002C938();
    if (obj != 0) {
        obj[0] = 0x41;
        obj[1] = 0x3C;
        obj[2] = kind;
        obj[0x5C] = arg2;
        *(s32*)(obj + 0x10) = 0;
        *(u8**)(obj + 0x80) = arg0;
        *(u16*)(obj + 0x40) = *(u16*)(arg0 + 0x40);
        *(u16*)(obj + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(obj + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(s32*)(obj + 0x30) = *(s32*)(arg0 + 0x30);
        obj[0x14] = arg0[0x14];
        if (kind != 0) {
            if (kind < 4) {
                goto roll; // !FAKE: goto kept for the matching branch layout
            }
            if (kind == 4) {
                goto fixed; // !FAKE: goto kept for the matching branch layout
            }
            return;
        roll: // !FAKE: label kept for the matching branch layout
            if (func_8002DF78() & 1) {
                *(s16*)(obj + 0xA) = 0x131B;
                *(s16*)(obj + 0xE) = 0x5B;
                obj[0x89] = 0;
            } else {
                *(s16*)(obj + 0xA) = 0x1365;
                *(s16*)(obj + 0xE) = 0x5B;
                obj[0x89] = 1;
            }
            return;
        fixed: // !FAKE: label kept for the matching branch layout
            *(s16*)(obj + 0xA) = 0x1340;
            *(s16*)(obj + 0xE) = 0x90;
        }
    }
}
