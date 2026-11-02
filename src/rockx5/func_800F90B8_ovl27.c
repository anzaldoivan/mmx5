#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002DF54(u8* a0);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_8009A0A0[];

void func_800F90B8_ovl27(u8* obj) {
    u8* p;
    s32 px;
    s32 pz;
    s32 ang;

    if (--*(s16*)(obj + 0x7C) == -1) {
        if (*(u16*)(obj + 0x7E) & 1) {
            func_800171E8(obj, 0xA);
            D_1F80004C.bytes[0x8A] = 0;
            *(u16*)(obj + 0x7C) = 0x3C;
        } else {
            func_800171E8(obj, 0xC);
            D_1F80004C.bytes[0x8A] = 1;
            *(u16*)(obj + 0x7C) = 0x19;
        }
        if (--*(s16*)(obj + 0x7E) != 0) {
            p = D_8009A0A0;
            px = *(s16*)(p + 0xA);
            pz = *(s16*)(p + 0xE);
            ang = ratan2(*(s16*)(obj + 0xE) - pz, px - *(s16*)(obj + 0xA));
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x2C) = 0;
            *(s32*)(obj + 0x20) = rcos(ang) * 16;
            *(s32*)(obj + 0x24) = rsin(ang) * 16;
            if (*(s32*)(obj + 0x20) != 0) {
                *(s32*)(obj + 0x20) = *(s32*)(obj + 0x20) * 9 / 2;
            } else {
                *(s32*)(obj + 0x20) = 0;
            }
            if (*(s32*)(obj + 0x24) != 0) {
                *(s32*)(obj + 0x24) = *(s32*)(obj + 0x24) * 9 / 2;
            } else {
                *(s32*)(obj + 0x24) = 0;
            }
        } else {
            func_800171E8(obj, 0xA);
            D_1F80004C.bytes[0x8A] = 0;
            obj[6]++;
            return;
        }
    }
    if (*(u16*)(obj + 0x7E) & 1) {
        func_8002DF54(obj);
    }
}
