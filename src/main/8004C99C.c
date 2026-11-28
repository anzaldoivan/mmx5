#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_8004C99C(u8* obj) {
    u8* g = g_Player;
    s32 mask;
    s16 d;

    animate_object(obj);
    apply_object_motion(obj);
    mask = 1;
    if (obj[0x15] == 0) {
        mask = 2;
    }
    if (*(s16*)(g + 0xA) - *(s16*)(obj + 0xA) >= 0) {
        d = *(u16*)(g + 0xA) - *(u16*)(obj + 0xA);
    } else {
        d = *(u16*)(obj + 0xA) - *(u16*)(g + 0xA);
    }
    if (*(s8*)(g + 5) != 0x3B || (obj[0x70] & mask) || d >= 0x61) {
        func_8003B33C(obj, 0x11);
        obj[5] = 1;
        *(s16*)(obj + 0x88) = 0;
        return;
    }
    if (*(s8*)(obj + 3) == 0) {
        obj[4]++;
        return;
    }
    if (*(s8*)(obj + 0x98) != 0) {
        *(s32*)(obj + 0x50) = 0;
        func_8003B33C(obj, 0x68);
        obj[5] = 2;
    }
    func_8002D89C(obj);
}

void func_8004CAB4(u8* obj) {
    s32 t;

    animate_object(obj);
    t = *(u16*)(obj + 0x88) + 1;
    *(u16*)(obj + 0x88) = t;
    if ((s16)t >= 16) {
        obj[4]++;
    } else if (t & 1) {
        obj[3] = 0;
    } else {
        obj[3] = 1;
    }
}

extern u8* func_8002D078();
extern signed char D_8009A0A5;

void func_8004CB24(u8* p) {
    u8* q;

    animate_object(p);
    if (*(s8*)(p + 0x45) & 0x80) {
        p[0x45] &= 0x7F;
        q = func_8002D078();
        if (q != 0) {
            q[0] = 1;
            q[1] = 0x2C;
            q[2] = 0;
            q[0x14] = p[0x14];
            *(s32*)(q + 0x84) = p[0x17];
            *(u8**)(q + 0x7C) = p;
        }
    }
    if (D_8009A0A5 != 0x3B) {
        p[4]++;
    } else if (*(s8*)(p + 0x46) == 0) {
        p[5] = 1;
        *(s16*)(p + 0x88) = 0;
    }
}
