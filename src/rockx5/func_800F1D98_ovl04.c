#include "types.h"
#include "addr.h"

extern s32 func_80031DD0(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A0A0[];
extern u8 D_80101640_ovl04[];
extern void* D_80101664_ovl04[];

void func_800F1D98_ovl04(u8* obj) {
    u8* g;
    s16 x;

    if (func_80031DD0(obj) < 0) {
        func_8004D4F4(5, D_80101640_ovl04, obj);
        func_80054440(obj, 0x11);
        obj[3] = 0;
        *(s16*)(obj + 0x7C) = 0xF;
        *(s16*)(obj + 0x7E) = 5;
        obj[4] = 6;
        return;
    }
    g = D_8009A0A0;
    if (g[0xF7] == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        if (--*(u16*)(D_1F80004C.bytes + 0x82) == 0xFFFF) {
            *(u16*)(D_1F80004C.bytes + 0x82) = 0x20;
            if (D_1F80004C.bytes[0x84] == 0) {
                x = *(s16*)(obj + 0xA);
                if (*(s16*)(g + 0xA) < x) {
                    obj[0x15] = 0;
                } else if (x < *(s16*)(g + 0xA)) {
                    obj[0x15] = 0x40;
                }
            }
        }
        ((void (*)(u8*))D_80101664_ovl04[(s8)obj[5]])(obj);
        func_80017248(obj);
        if ((s8)obj[5] == 2) {
            obj[0x60] = 4;
            obj[0x62] = 0;
        } else {
            obj[0x62] = 3;
            obj[0x60] = 0;
        }
        if ((s8)D_8009A0A0[0xCA] == 0 && func_800317B8(obj) != 0 &&
            (s8)D_8009A0A0[0xCA] != 0) {
            obj[5] = 4;
            obj[6] = 0;
        }
    } else {
        obj[0x60] = 4;
        obj[0x62] = 0;
        func_800317B8(obj);
    }
    if (func_8002D938(obj, 0xA0, 0x40) == 0) {
        func_8002D9EC(obj, 0x70, 0x20);
        return;
    }
    obj[4] = 3;
}
