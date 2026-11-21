#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/object.h"

extern u8 D_8007B430[];
extern u8 D_800770AC[];
extern s16 D_8009A206;

void func_800497C8(u8* obj) {
    u8* p = g_Player;
    u8* s;

    if (((s8*)p)[5] != 0x28) {
        obj[4] = 2;
        return;
    }
    if (((s8*)p)[0x45] & 0x80) {
        s = D_1F80001C.bytes;
        s += *(s32*)(s + 0x6C);
        *(u8**)(obj + 0x30) = D_8007B430;
        *(u16*)(obj + 0x40) = 0x540;
        *(u16*)(obj + 0x42) = 0x7801;
        obj[0x16] = 0;
        obj[0x15] = 0;
        *(u8**)(obj + 0x50) = D_800770AC;
        obj[0x64] = 1;
        *(u8**)(obj + 0x3C) = s;
        *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
        *(s16*)(obj + 0xE) = D_8009A206 - 0x50;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0xFFE80000;
        set_animation(obj, 6, p);
        *(s16*)(obj + 0x92) = 0;
        obj[3] = 1;
        obj[4]++;
    }
}

void func_800498AC(u8* obj) {
    u8* p = g_Player;

    p[0x98]--;
    p[0x99]--;
    p[0xA6]--;
    clear_object_slot(obj);
}
