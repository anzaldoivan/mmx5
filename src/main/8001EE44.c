#include "types.h"
#include "mmx5/globals.h"

extern void func_80017D88(void);
extern void func_800177B0(s32, s32);
extern void func_8002C1C8(void);
extern void func_80013288(s32);
extern s8 D_8009A426;
extern u8 D_80070EF4[];

void func_8001EE44(u8* a0) {
    u8* obj;
    u8 i;

    D_8009A426 = 0;
    func_80017D88();
    func_800177B0(0x14, 0x7F);
    func_8002C1C8();
    func_8002C50C();
    for (i = 0; i < 6; i++) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x13;
            obj[2] = D_80070EF4[i];
        }
    }
    func_80013288(8);
    *(u16*)(a0 + 4) = 0;
    a0[1]++;
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001DBAC.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_8009A424;

void func_8001EF0C(void* arg0) {
    if (D_8009A424 == 0) {
        M2C_FIELD(arg0, s8*, 0) = 3;
        M2C_FIELD(arg0, s8*, 1) = 0;
        M2C_FIELD(arg0, s8*, 2) = 0;
        M2C_FIELD(arg0, s8*, 3) = 0;
    }
}
