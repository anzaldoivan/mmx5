#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_8007B470[];

void func_8004AF30(u8* obj) {
    u8* p;
    u8* q;
    s32 o;
    u8* d = g_Player;

    if (((s8*)obj)[2] == 0) {
        if (((s8*)d)[5] != 0x29) {
            obj[4] = 3;
            return;
        }
        if (((s8*)d)[0x45] == 0) {
            return;
        }
    }
    p = D_1F800014;
    *(u8**)(obj + 0x38) = p + *(s32*)(p + 0x24);
    q = D_1F80001C.bytes;
    o = *(s32*)(q + 0x44);
    *(u8**)(obj + 0x30) = D_8007B470;
    *(s16*)(obj + 0x40) = 0x520;
    *(s16*)(obj + 0x42) = 0x7801;
    obj[0x16] = 1;
    *(u8**)(obj + 0x3C) = q + o;
    obj[0x15] = d[0x15];
    if (((s8*)obj)[2] != 0) {
        set_animation(obj, 0);
        obj[5] = 2;
        obj[3] = 1;
    }
    *(s16*)(obj + 0x8C) = 0;
    obj[4]++;
}
