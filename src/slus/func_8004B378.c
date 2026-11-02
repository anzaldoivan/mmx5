#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D6FC(u8* obj);
extern void func_8004B49C(u8* obj, u8* g);
extern void func_8004B8E4(u8* obj, u8* g);
extern u8 D_8009A0A0[];

void func_8004B378(u8* obj) {
    u8* g = D_8009A0A0;
    s32 hit;
    u8 t;

    hit = ((s8*)g)[0x5C] == 0;
    if (((s8*)g)[0xD3] != 0) {
        hit = 1;
    }
    if (((s8*)g)[0xCF] != 0) {
        hit = 1;
    }
    t = obj[1];
    if (((s8*)obj)[1] != 0x2C && *(s32*)(obj + 0x84) != g[0x17]) {
        hit = 1;
    }
    if (obj[0x15] != g[0x15] && (u32)(t - 0x18) < 3) {
        hit = 1;
    }
    if ((s8)t == 0x2C && ((s8*)g)[5] != 0x3B) {
        hit = 1;
    }
    if (hit == 0) {
        if (((s8*)obj)[4] == 0) {
            goto first; // !FAKE: goto kept for the matching branch layout
        }
        func_80017248(obj);
        if (((s8*)obj)[0x46] != 0) {
            goto second; // !FAKE: goto kept for the matching branch layout
        }
    }
    func_8002D6FC(obj);
    return;
first: // !FAKE: label kept for the matching branch layout
    func_8004B49C(obj, g);
second: // !FAKE: label kept for the matching branch layout
    func_8004B8E4(obj, g);
}
