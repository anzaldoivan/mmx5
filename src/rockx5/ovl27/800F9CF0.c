#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/object.h"

extern u8 D_8009A0B5;

void func_800F9CF0_ovl27(u8* arg0) {
    ((s32(*)())func_8003D29C)(0x14, D_8009A0B5);
    arg0[5]++;
}

extern u8* alloc_class3_slot(void);

void func_800F9D2C_ovl27(u8* a0) {
    u8* p;
    u8* base;

    p = alloc_class3_slot();
    if (p != 0) {
        base = D_8009A1F8.u;
        p[0] = 1;
        p[1] = 0x1A;
        *(s16*)(p + 0xA) = *(s16*)(base + 0xA) + 0xA0;
        *(s16*)(p + 0xE) = *(s16*)(base + 0xE) + 0x78;
        *(u8**)(D_1F80004C.bytes + 0x80) = p;
    }
    a0[5]++;
}

void func_800F9DAC_ovl27(u8* a0) {
    u8* p;

    if (**(s8**)(D_1F80004C.bytes + 0x80) == 0) {
        p = g_playthrough_state.u;
        p[0xF] = 0x10;
        p[0x24] = 0;
        *(s32*)(p + 0x20) = 0;
        clear_object_slot(a0);
    }
}
