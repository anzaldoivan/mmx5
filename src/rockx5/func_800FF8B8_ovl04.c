#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8004FD24(u8* a0);
extern u8 D_8009A0A0[];
extern s8 D_8009A0A5;
extern u16 D_8009A206;
extern u8 D_800D1C26;
extern u8 D_80102ED8_ovl04[];
extern u8 D_80102EE0_ovl04[];
extern u8 D_80102EE4_ovl04[];

void func_800FF8B8_ovl04(u8* obj) {
    s8 state;
    s32 y;
    s32 t;
    u8* base;

    state = obj[6];
    if (state == 0) {
        t = *(u16*)(obj + 0xA) - 1;
        *(s16*)(obj + 0xA) = t;
        y = D_8009A206 + *(u16*)(obj + 0x24);
        *(s16*)(obj + 0xE) = y;
        base = D_8009A0A0;
        if (*(s16*)(base + 0xA) >= (s16)t) {
            obj[0x15] = 0;
            *(u8**)(obj + 0x50) = D_80102ED8_ovl04;
            *(u8**)(obj + 0x54) = D_80102EE0_ovl04;
            if (*(s16*)(base + 0xE) >= (s16)y) {
                func_800171E8(obj, 0x2E);
                obj[6] = 2;
            } else {
                func_800171E8(obj, 0x13);
                obj[6] = 1;
            }
        }
    } else if (state == 1) {
        *(s32*)(obj + 0xC) += -0x30000;
    } else if (state == 2) {
        *(s32*)(obj + 0xC) += 0x30000;
    }
    func_80017248(obj);
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
    err:
        func_8004FD24(obj);
        func_8004D4F4(3, D_80102EE4_ovl04, obj);
    } else if ((D_800D1C26 & 2) && D_8009A0A5 == 0x14) {
        goto err; // !FAKE: goto kept for the matching branch layout
    } else if (func_8002D938(obj, 0x40, 0x40) == 0) {
        func_8002D9EC(obj, 0x10, 0x10);
        return;
    }
    obj[4]++;
}
