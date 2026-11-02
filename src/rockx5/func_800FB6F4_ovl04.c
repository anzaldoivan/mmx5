#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern u8 D_800D1C00[];
extern void* D_80102CAC_ovl04[];

void func_800FB6F4_ovl04(u8* obj) {
    u8* parent;
    s32 r;
    u8 st;
    s8 s;

    st = obj[5];
    parent = *(u8**)(obj + 0x80);
    obj[0x8E] = st;
    *(s16*)(obj + 0xA) = *(s16*)(parent + 0xA) + *(s16*)(obj + 0x88);
    *(s16*)(obj + 0xE) = *(s16*)(parent + 0xE) + *(s16*)(obj + 0x8A);
    ((void (*)(u8*))D_80102CAC_ovl04[(s8)st])(obj);
    func_800317B8(obj);
    r = func_80031DD0(obj);
    if (r < 0) {
        func_8004FD24(obj);
        do { // !FAKE: loop notes keep the lb after the state store
            obj[5] = 4;
        } while (0);
        s = ((s8*)obj)[2];
        obj[3] = 0;
        *(s32*)(obj + 0x54) = 0;
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x84) = 0;
        if (s == 12) {
            func_800171E8(obj, 0x11);
        } else if (s == 13) {
            func_800171E8(obj, 0x37);
        } else if (s == 14) {
            func_800171E8(obj, 0x38);
        } else if (s == 15) {
            func_800171E8(obj, 0x39);
        }
        goto set; // !FAKE: goto kept for the matching branch layout
    }
    if (r > 0) {
    set:
        D_800D1C00[0x27] |= 1;
    } else {
        if (*(u16*)(parent + 0x42) & 0x8000) {
            *(u16*)(obj + 0x42) |= 0x8000;
        }
    }
    if (D_800D1C00[0x2A] & obj[0x92]) {
        s = obj[5];
        if (s != 6) {
            if (s != 4) {
                func_8004FD24(obj);
            }
            *(s32*)(obj + 0x54) = 0;
            *(s32*)(obj + 0x50) = 0;
            obj[5] = 6;
        }
    }
    if (D_800D1C00[0x2A] & 4) {
        obj[4]++;
    }
}
