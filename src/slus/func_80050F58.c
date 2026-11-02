#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002D6FC(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u32* D_8007B2E8[];
extern u8 D_8009A0A0[];

void func_80050F58(u8* obj) {
    u8* g;
    s32 sel;
    u8* sp;
    s32 off;

    g = D_8009A0A0;
    if (((s8*)obj)[4] == 0) {
        obj[3] = 1;
        ((s8*)obj)[2] = -1;
        sp = D_1F80001C.bytes;
        off = *(s32*)(sp + 0x30);
        *(u32***)(obj + 0x30) = D_8007B2E8;
        *(s16*)(obj + 0x40) = 0;
        *(s16*)(obj + 0x42) = 0x7802;
        obj[0x16] = 3;
        obj[0x5C] = 0;
        obj[4]++;
        *(u8**)(obj + 0x3C) = sp + off;
    }
    sel = -1;
    if ((u8)(g[0x47] + 0x1B) < 2) {
        sel = 0;
    }
    if ((u8)(g[0x47] + 0x23) < 2) {
        sel = 1;
    }
    if ((u8)(g[0x47] + 0x21) < 2) {
        sel = 2;
    }
    if ((u8)(g[0x47] + 0x1F) < 2) {
        sel = 3;
    }
    if ((u8)(g[0x47] + 0x1D) < 2) {
        sel = 4;
    }
    if (sel == -1) {
        func_8002D6FC(obj);
        return;
    }
    if (sel != (s8)obj[2]) {
        func_800171E8(obj, sel + 0x20);
        obj[2] = sel;
    } else {
        func_80017248(obj);
    }
    obj[0x15] = g[0x15];
    *(s32*)(obj + 8) = *(s32*)(g + 8);
    *(s32*)(obj + 0xC) = *(s32*)(g + 0xC);
    if (((s8*)obj)[0x5C] == 0) {
        obj[0x5C] = 8;
        func_80016490(0, 0x1F, obj);
    } else {
        ((s8*)obj)[0x5C]--;
    }
    func_8002D9EC(obj, 0x28, 0x28);
}
