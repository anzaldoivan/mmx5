#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern u8 D_800FE914_ovl06[];
extern u8 D_800FE918_ovl06[];

void func_800F5D90_ovl06(u8* obj) {
    u8 v;
    s32 r;
    s32 q;

    if (*(s8*)(obj + 6) == 0) {
        obj[6] = 1;
        *(s16*)(obj + 0x84) = 0x160;
        func_800171E8(obj, 6);
        *(u8**)(obj + 0x54) = D_800FE914_ovl06;
        *(u8**)(obj + 0x50) = D_800FE918_ovl06;
        obj[0x60] = 5;
        obj[0x8D] &= 0xFB;
    }
    if (!(obj[0x8D] & 2)) {
        if (*(s8*)(obj + 0x46) == 0) {
            r = 2;
            obj[5] = r;
            do {
                r = (s32)D_800FE914_ovl06;
            } while (0); // !FAKE: fences the sched1 hoist of the address loads
            q = (s32)D_800FE918_ovl06;
            *(s32*)(obj + 0x54) = r;
            obj[6] = 0;
            obj[0x88] = 0;
            obj[0x86] = 0;
            obj[0x87] = 0;
            *(s32*)(obj + 0x50) = q;
            obj[0x60] = 5;
            return;
        }
        if (obj[0x86] != 0) {
            v = 8;
        } else if (obj[0x87] != 0) {
            v = 9;
        } else if (obj[0x8A] != 0) {
            v = 3;
        } else {
            goto call; // !FAKE: goto kept for the matching branch layout
        }
        obj[5] = v;
        obj[6] = 0;
        return;
    call: // !FAKE: label kept for the matching branch layout
        func_80017248(obj);
        return;
    }
    func_80017248(obj);
}
