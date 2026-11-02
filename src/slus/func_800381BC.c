#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_800306E0(u8* a0);
extern s32 func_80038008(u8* a0);
extern void func_8003B33C(u8*, s32);
extern void func_8003B4CC(u8* obj, s32 arg1, s32 arg2);

void func_800381BC(u8* p) {
    s32 d;
    s32 s;
    s32 r;
    u8 id;
    QByte c; // !FAKE: one-byte struct keeps QImode for the lone sll 24 (C0279)

    if (((s8*)p)[0x84] != 0) {
        d = func_80038008(p);
    } else {
        u16 m = *(u16*)(p + 0x7C);
        s = 0;
        if (m & 0xC) {
            s = 1;
            if (m & 4) {
                *(s32*)(p + 0x24) = *(s32*)(p + 0x138);
            } else {
                s = 2;
                *(s32*)(p + 0x24) = -*(s32*)(p + 0x138);
            }
            func_8002DF54(p);
            r = func_800306E0(p) ^ 0x2E;
            *(s32*)(p + 0xC) = *(s32*)(p + 0x1C);
            if (r) {
                s = 0;
            } else {
                func_8002DF54(p);
            }
        }
        d = s;
    }
    c.b = p[2];
    if (((s8*)p)[2] == 0) {
        if (((s8*)p)[0x8F] != 0) {
            func_8003B33C(p, d + 0x91);
            return;
        }
        if (((s8*)p)[0x8E] == 0) {
            id = 0x91;
            if (p[0x17] != 0x91) {
                id = d - 0x60;
            }
        } else {
            id = d - 0x6F;
        }
    } else {
        id = d - 0x60;
    }
    if (id != p[0x17]) {
        if (id == 0xA0) {
            if ((s8)c.b == 0) {
                func_8003B4CC(p, 0xA0, 2);
            } else {
                func_8003B4CC(p, 0xA0, 4);
            }
        } else {
            func_8003B33C(p, id);
        }
    } else {
        func_80017248(p);
    }
    if (((s8*)p)[0x46] == 0 && ((s8*)p)[0x8E] == 0) {
        if (((s8*)p)[2] == 0) {
            func_8003B4CC(p, 0xA0, 2);
        } else {
            func_8003B4CC(p, 0xA0, 4);
        }
    }
}
