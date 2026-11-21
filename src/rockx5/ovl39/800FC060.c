#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800FA214_ovl00 D_800FEB90_ovl39

#define func_800EEB64_ovl00 func_800FC060_ovl39
#include "shared/func_800EEB64_ovl00.c"
#undef func_800EEB64_ovl00
#undef D_800FA214_ovl00

extern u8 D_8009A1F8[];

void func_800FC09C_ovl39(u8* a0) {
    u8* p = D_8009A1F8;
    u8* q = g_Player;
    u8* r;

    *(s16*)(p + 0x94) = 0;
    p[0xA0] = 1;
    if (*(s32*)(q + 8) > *(s32*)(a0 + 8)) {
        q[0x15] = 0;
    } else {
        q[0x15] = 0x40;
    }
    r = g_Player;
    func_8003D29C(0x49, r[0x15]);
    if ((s8)r[5] == 0x49) {
        func_8002385C(0x4A, 0xFF, 0);
        a0[5]++;
    }
}

extern u8 D_80091C44;
extern u8 D_8009A1F8[];

void func_800FC140_ovl39(u8* a0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8;
        a0[5]++;
        *(s16*)(p + 0x96) = 0;
        p[0xA0] = 1;
        *(s16*)(a0 + 0x7C) = 0x7F;
        *(s16*)(a0 + 0x7E) = 25;
        a0[0x61] = 25;
        *(u16*)(a0 + 0x42) &= 0x7FFF;
    }
}

extern u8 D_8009A11A;
extern u8 D_800D1C00[];

void func_800FC19C_ovl39(void) {
    u8* p = D_800D1C00;

    p[0xF] = 0x10;
    p[0x24] = 0;
    *(s32*)(p + 0x20) = 0;
    D_8009A11A = 0;
    clear_object_slot();
}
