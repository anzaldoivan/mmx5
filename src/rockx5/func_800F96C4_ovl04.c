#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800D1C00[];
extern u8 D_80102B98_ovl04[];
extern u8 D_80102B9C_ovl04[];

void func_800F96C4_ovl04(u8* obj) {
    u8* g;
    u8* h;
    s8 m;

    g = D_800D1C00;
    m = g[0x28] & obj[0x93];
    if (m != 0) {
        obj[0x94] = m >> 4;
        if (obj[0x94] == 3) {
            g[0x2B] = 1;
        }
        if ((s8)obj[5] == 2) {
            func_800171E8(obj, D_80102B98_ovl04[obj[0x94]]);
        } else {
            func_800171E8(obj, D_80102B9C_ovl04[obj[0x94]]);
        }
        obj[0x96] = 0xFF;
        obj[0x95] = ~obj[0x93];
        obj[6]++;
    }
    h = D_800D1C00;
    if (*(s8*)(h + 0x28) == 0) {
        m = h[0x29] & obj[0x93];
        if (m != 0) {
            obj[0x94] = m >> 4;
            if (obj[0x94] == 3) {
                h[0x2B] = 1;
            }
            if ((s8)obj[5] == 2) {
                func_800171E8(obj, D_80102B98_ovl04[obj[0x94]]);
            } else {
                func_800171E8(obj, D_80102B9C_ovl04[obj[0x94]]);
            }
            obj[0x95] = 0xFF;
            obj[0x96] = ~obj[0x93];
            obj[6]++;
        }
    }
}
