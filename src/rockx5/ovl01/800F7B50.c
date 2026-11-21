#include "types.h"
#include "mmx5/ovl01.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

#define D_800FD408_ovl01_as_u8_rows ((u8(*)[6])D_800FD408_ovl01)

extern s32 func_8002D800(u8* a0);
extern u8* D_800FD3F4_ovl01[];

void func_800F7B50_ovl01(u8* a0) {
    s8 idx;
    u8* p;

    if (func_8002D800(a0) == 0) {
        idx = ((s8*)a0)[2];
        a0[0x14] = D_800FD408_ovl01_as_u8_rows[idx][0];
        p = D_800FD3F4_ovl01[idx];
        *(u8**)(a0 + 0x1C) = p;
        a0[0x18] = p[0];
        a0[0x19] = p[1];
        a0[0x1A] = p[2];
        a0[0x1B] = p[3];
        a0[4]++;
    }
}
#undef D_800FD408_ovl01_as_u8_rows

extern void func_800F79C0_ovl01(u8* a0);
extern u8 D_8009A197;

void func_800F7BEC_ovl01(u8* a0) {
    if (*(*(u8**)(a0 + 0x20) + 0x87) >= 2) {
        clear_object_slot(a0);
    } else {
        if (is_off_screen(a0, D_800FD408_ovl01[*(s8*)(a0 + 2)][1],
                          D_800FD408_ovl01[*(s8*)(a0 + 2)][2]) == 0 &&
            D_8009A197 == 0 && !(*(u16*)(*(u8**)(a0 + 0x20) + 0x42) & 0x8000)) {
            func_800F79C0_ovl01(a0);
        }
    }
}
