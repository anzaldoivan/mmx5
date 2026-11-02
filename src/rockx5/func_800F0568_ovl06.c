#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern u8* func_8002D078();
extern s32 func_8002DF78(void);
extern u8 D_8009A0A0[];
extern s32 D_8009A420;

void func_800F0568_ovl06(u8* obj) {
    u8* child;
    u8* g;
    u8 st;
    s32 t;
    u8 f;
    u16 h;
    u16 v;
    s32 mask;
    s32 m1;
    s8 s6;

    if (!(D_8009A420 & 3) && (func_8002DF78() & 1)) {
        func_8002DF78();
    }
    s6 = *(s8*)(obj + 6);
    if (s6 == 0) {
        obj[6] = s6 + 1;
        child = func_8002D078();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x3E;
            child[2] = 1;
            *(u16*)(child + 0xA) = *(u16*)(obj + 0xA);
            *(u16*)(child + 0xE) = *(u16*)(obj + 0xE);
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            child[0x16] = obj[0x16];
            *(u8**)(child + 0x7C) = obj;
            child[0x15] = obj[0x15];
        }
        func_800171E8(obj, 9);
        if (obj[0x8D] == 0) {
            g = D_8009A0A0;
            g[0xD8] = 0x37;
            g[6] = 0;
        }
        func_80016490(5, 0xB, 0);
    }
    st = obj[0xA8];
    t = obj[0x90] - 1;
    obj[0x90] = t;
    if (!(st & 8)) {
        obj[5] = 0xC;
        obj[6] = 0;
        return;
    }
    f = obj[0x97];
    if (!(f & 2)) {
        if ((st & 3) || (obj[0x45] & 1)) {
            if ((s8)t < 0) {
                obj[5] = 8;
                obj[6] = 0;
            } else {
                goto add; // !FAKE: goto kept for the matching branch layout
            }
        } else {
            if (!(f & 8)) {
                m1 = 2;
                if (obj[0x15] != 0) {
                    m1 = 1;
                }
                v = *(u16*)(obj + 0x88) & m1;
            } else {
                mask = 2;
                if (obj[0x15] != 0) {
                    mask = 1;
                }
                h = *(u16*)(obj + 0x88);
                if (h & mask) {
                    goto add; // !FAKE: goto kept for the matching branch layout
                }
                v = h & 0x100;
            }
            if (v != 0) {
            add:
                *(s32*)(obj + 8) += *(s32*)(obj + 0x20);
            }
        }
        func_80017248(obj);
        return;
    }
    func_80017248(obj);
}
