#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8007706C[];
extern u8 D_8007B424[];
extern u8 D_8009A0A0[];

void func_80047FB8(u8* obj) {
    u8* g = D_8009A0A0;
    s8 kind = *(s8*)(obj + 2);
    s32 off;
    u8* t;
    u8* u;

    if (kind == 0 || kind == 0x40) {
        if (*(s8*)(g + 5) != 0x27) {
            obj[4] = 2;
            return;
        }
        if (!(*(s8*)(g + 0x45) & 0x80)) {
            return;
        }
    }
    *(u8**)(obj + 0x50) = D_8007706C;
    obj[0x64] = 0;
    t = D_1F800014;
    *(u8**)(obj + 0x38) = t + *(s32*)(t + 0x14);
    u = D_1F80001C.bytes;
    off = *(s32*)(u + 0x34);
    *(u8**)(obj + 0x30) = D_8007B424;
    *(s16*)(obj + 0x40) = 0x520;
    *(s16*)(obj + 0x42) = 0x7801;
    obj[0x16] = 1;
    *(u8**)(obj + 0x3C) = u + off;
    if (obj[2] & 0x40) {
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x20) = 0x80000;
        *(s16*)(obj + 0xA) = *(s16*)(g + 0xA) + 0x20;
        if (g[0x15] != 0) {
            *(s16*)(obj + 0xA) -= 8;
        }
    } else {
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = 0xFFF80000;
        *(s16*)(obj + 0xA) = *(s16*)(g + 0xA) - 0x18;
        if (g[0x15] != 0) {
            *(s16*)(obj + 0xA) -= 8;
        }
        func_80016490(1, 0x11, obj);
    }
    *(s32*)(obj + 0x24) = 0;
    *(s16*)(obj + 0xE) = *(s16*)(g + 0xE) - 8;
    obj[0x67] = 1;
    func_800171E8(obj, 1);
    obj[4]++;
    func_8002D9EC(obj, 0xA0, 0xA0);
    obj[0x8D] = 4;
    obj[0x8C] = 0;
}
