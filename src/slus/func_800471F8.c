#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D0E4(void);
extern u8 D_80076FD4[];
extern s32 D_80076FF4[];
extern s32 D_80077014[];
extern s32 D_80077034[];
extern u8 D_8007B480[];
extern u8 D_8009A0A0[];

void func_800471F8(u8* obj) {
    u8* g;
    u8* s;
    u8* q;
    s32 i;
    s32 v;
    u8 t;
    s32 y;
    s32 off;

    g = D_8009A0A0;
    if (((s8*)g)[5] != 0x2B) {
        v = 3;
        goto store; // !FAKE: goto kept for the matching branch layout
    }
    if (!(((s8*)g)[0x45] & 0x80)) {
        return;
    }
    t = obj[2];
    *(u8**)(obj + 0x50) = D_80076FD4;
    obj[3] = 1;
    obj[0x64] = t + 1;
    s = D_1F80001C.bytes;
    off = *(s32*)(s + 0x64);
    *(u8**)(obj + 0x30) = D_8007B480;
    *(u16*)(obj + 0x40) = 0x540;
    *(u16*)(obj + 0x42) = 0x7801;
    obj[0x16] = 1;
    *(u8**)(obj + 0x3C) = s + off;
    if ((s8)t >= 4) {
        obj[0x15] = 0x40;
        y = *(u16*)(g + 0xA) + 0x20;
    } else {
        obj[0x15] = 0;
        y = *(u16*)(g + 0xA) - 0x18;
    }
    *(u16*)(obj + 0xA) = y;
    if (g[0x15] != 0) {
        *(u16*)(obj + 0xA) = y - 8;
    }
    i = ((s8*)obj)[2];
    *(u16*)(obj + 0xE) = *(u16*)(g + 0xE) - 8;
    *(s32*)(obj + 0x20) = D_80076FF4[i];
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = D_80077014[i];
    *(s32*)(obj + 0x2C) = D_80077034[i];
    func_800171E8(obj, 0);
    if (((s8*)obj)[2] == 0 || ((s8*)obj)[2] == 4) {
        q = func_8002D0E4();
        if (q != 0) {
            q[0] = 1;
            q[1] = 3;
            q[2] = 0xF;
            *(u8**)(q + 0x3C) = *(u8**)(obj + 0x3C);
            *(u8**)(q + 0x30) = *(u8**)(obj + 0x30);
            q[0x14] = obj[0x14];
            *(u16*)(q + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(q + 0x42) = *(u16*)(obj + 0x42);
            q[0x16] = 0;
            q[0x15] = 0;
            *(u16*)(q + 0xA) = *(u16*)(obj + 0xA);
            *(u16*)(q + 0xE) = *(u16*)(obj + 0xE);
        }
    }
    v = obj[4] + 1;
store:
    obj[4] = v;
}
