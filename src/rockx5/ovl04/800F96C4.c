#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"

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
            set_animation(obj, D_80102B98_ovl04[obj[0x94]]);
        } else {
            set_animation(obj, D_80102B9C_ovl04[obj[0x94]]);
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
                set_animation(obj, D_80102B98_ovl04[obj[0x94]]);
            } else {
                set_animation(obj, D_80102B9C_ovl04[obj[0x94]]);
            }
            obj[0x95] = 0xFF;
            obj[0x96] = ~obj[0x93];
            obj[6]++;
        }
    }
}

extern u8* func_8002C938();
extern u8* func_8002D210();
extern u8 D_800D1C2A[];

void func_800F984C_ovl04(u8* obj) {
    u8 state;
    u8* p;
    u8* q;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) & 0x80) {
        state = obj[0x94];
        obj[0x45] &= 0x7F;
        switch (state) {
        case 1:
            if (random_byte() & 0x40) {
                p = func_8002C938();
                if (p != 0) {
                    p[1] = 3;
                    p[2] = 0x12;
                    p[0] = 0x41;
                    *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - 0x30;
                    *(s16*)(p + 0xE) = *(s16*)(obj + 0xE);
                }
                obj[0x8D] = 0;
                obj[6] += 2;
            } else {
                p = func_8002C938();
                if (p != 0) {
                    p[1] = 3;
                    p[2] = 0x20;
                    p[0] = 0x41;
                    *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - 0x30;
                    *(s16*)(p + 0xE) = *(s16*)(obj + 0xE);
                }
                p = func_8002C938();
                if (p != 0) {
                    p[1] = 3;
                    p[2] = 0x21;
                    p[0] = 0x41;
                    *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - 0x30;
                    *(s16*)(p + 0xE) = *(s16*)(obj + 0xE);
                }
                p = func_8002C938();
                if (p != 0) {
                    p[1] = 3;
                    p[2] = 0x22;
                    p[0] = 0x41;
                    *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - 0x30;
                    *(s16*)(p + 0xE) = *(s16*)(obj + 0xE);
                }
                obj[6] += 1;
            }
            break;
        case 2:
            q = func_8002D210();
            if (q != 0) {
                q[1] = 4;
                q[2] = state;
                q[0] = 0x41;
                *(s16*)(q + 0xA) = *(s16*)(obj + 0xA) - 0x30;
                *(s16*)(q + 0xE) = *(s16*)(obj + 0xE);
            }
            obj[6] += 1;
            break;
        case 3:
            if (obj[0x95] == 0xFF) {
                obj[0x8D] = 0;
                obj[6] += 3;
            } else {
                D_800D1C2A[1] = 2;
                q = func_8002D1A4();
                if (q != 0) {
                    q[0] = 0x41;
                    q[1] = 0xB;
                    *(u8**)(q + 0x7C) = obj;
                    q[2] = 1;
                }
                q = func_8002D1A4();
                if (q != 0) {
                    q[0] = 0x41;
                    q[1] = 0xB;
                    *(u8**)(q + 0x7C) = obj;
                    q[2] = state;
                }
                obj[6] += 4;
            }
            break;
        }
    }
}
