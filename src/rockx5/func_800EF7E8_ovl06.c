#include "types.h"

extern u8* func_8002D078();
extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern u8 D_8009A0A0[];

void func_800EF7E8_ovl06(u8* obj) {
    u8* q;
    u8* p;
    s32 v;
    s32 hit;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        if (obj[0x87] == 1) {
            q = func_8002D078();
            if (q != 0) {
                q[0] = 0x41;
                q[1] = 0x3E;
                q[2] = 2;
                *(u16*)(q + 0xA) = *(u16*)(obj + 0xA);
                *(u16*)(q + 0xE) = *(u16*)(obj + 0xE);
                *(s32*)(q + 0x30) = *(s32*)(obj + 0x30);
                *(u16*)(q + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(q + 0x3C) = *(s32*)(obj + 0x3C);
                *(u16*)(q + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                q[0x16] = obj[0x16];
                *(u8**)(q + 0x7C) = obj;
                q[0x15] = obj[0x15];
            }
            func_800171E8(obj, 10);
            if (obj[0x8D] == 0) {
                D_8009A0A0[0xD8] = 0x32;
                D_8009A0A0[6] = 0;
            }
            func_80016490(5, 0x10, 0);
        } else {
            p = func_8002D078();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x3D;
                p[2] = 0;
                *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
                *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
                *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
                *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
                *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                p[0x16] = obj[0x16];
                *(u8**)(p + 0x7C) = obj;
                p[0x15] = obj[0x15];
            }
            func_800171E8(obj, 8);
            if (obj[0x8D] == 0) {
                D_8009A0A0[0xD8] = 0x31;
                D_8009A0A0[6] = 0;
            }
            func_80016490(5, 0xB, 0);
        }
        obj[0x81] = 0;
    }
    if (((s8*)obj)[0x46] == 0) {
        v = obj[0x81];
        if (v != 0) {
            v = 3;
        } else {
            v = 1;
            obj[0x87] = 0;
            obj[0x81] = 0;
        }
        obj[5] = v;
        obj[6] = 0;
        return;
    }
    if (obj[0x45] & 1) {
        hit = 0;
        if (*(u16*)(obj + 0x8A) & 0x30) {
            hit = 1;
            if (((s8*)obj)[2] != 0) {
                hit = obj[0x7E] == 0;
            }
        }
        if (hit && obj[0x81] == 0 && obj[0x87] < 2) {
            obj[0x87]++;
            obj[0x81] = 1;
        }
    }
    func_80017248(obj);
}
