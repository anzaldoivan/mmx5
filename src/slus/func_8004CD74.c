#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D6FC(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A0A0[];

void func_8004CD74(u8* obj) {
    u8* g = D_8009A0A0;
    s32 hit;

    hit = ((s8*)g)[0x5C] == 0;
    if (((s8*)g)[0xD3] != 0) {
        hit = 1;
    }
    if (g[0x17] != 0x66) {
        hit = 1;
    }
    if (((s8*)g)[0xCF] != 0) {
        hit = 1;
    }
    if (hit != 0) {
        goto fail; // !FAKE: goto kept for the matching branch layout
    }
    if (((s8*)obj)[4] != 0) {
        func_80017248(obj);
        if (((s8*)obj)[0x46] != 0) {
            goto tail; // !FAKE: goto kept for the matching branch layout
        }
    fail: // !FAKE: label kept for the matching branch layout
        func_8002D6FC(obj);
        return;
    }
    obj[3] = 1;
    *(s32*)(obj + 0x3C) = *(s32*)(g + 0x3C);
    *(s32*)(obj + 0x30) = *(s32*)(g + 0x30);
    *(u16*)(obj + 0x40) = *(u16*)(g + 0x40);
    *(u16*)(obj + 0x42) = 0x7801;
    obj[0x16] = 2;
    func_800171E8(obj, 0x7C);
    obj[4]++;
tail: // !FAKE: label kept for the matching branch layout
    *(s32*)(obj + 8) = *(s32*)(g + 8);
    *(s32*)(obj + 0xC) = *(s32*)(g + 0xC);
    obj[0x15] = g[0x15];
    func_8002D9EC(obj, 0x80, 0x80);
}
