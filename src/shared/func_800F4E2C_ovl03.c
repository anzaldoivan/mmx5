/* Shared body (DK-5), from the banked draft of func_800F4E2C_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern u8 D_8009A0A0[];
extern u8 D_800F9E68_ovl03[];
extern u8 D_800FA0BC_ovl03[][6];
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void DEDUP_NAME(u8* obj) {
    u8* p;

    p = D_8009A0A0;
    if (*(s16*)(p + 0xA) > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    D_8009A0A0[0xCA] = 0;
    if ((s16)((s16)(*(u16*)(obj + 0x7C))++ % 40) == 0) {
        func_80016490(2, 0x11, obj);
    }
    if (*(s32*)(obj + 0x20) < 0) {
        if (*(s16*)(obj + 0xA) <= D_800FA240_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA240_ovl03;
            *(s32*)(obj + 0x20) = 0;
            obj[0x8E] = 0;
        }
    } else if (*(s32*)(obj + 0x20) > 0) {
        if (*(s16*)(obj + 0xA) >= D_800FA242_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA242_ovl03;
            *(s32*)(obj + 0x20) = 0;
            obj[0x8E] = 1;
        }
    }
    if (*(s16*)(obj + 0xE) <= D_800FA244_ovl03) {
        *(s16*)(obj + 0xE) = D_800FA244_ovl03;
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s32*)(obj + 0x20) == 0 && *(s32*)(obj + 0x24) == 0) {
        *(u8**)(obj + 0x50) = D_800F9E68_ovl03;
        obj[5] = D_800FA0BC_ovl03[obj[0x92]][obj[0x93]++];
        obj[6] = 0;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
