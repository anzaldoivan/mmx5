#include "types.h"
#include "mmx5/globals.h"

void func_80027288(void);
void func_80017D88(void);
void silence_sound(s32, s32);
void func_8002D004(void);

void func_8001E668(void) {
    func_80027288();
    func_80017D88();
    silence_sound(0xFF, 0);
    func_8002C50C();
    func_8002D004();
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001D25C.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK create_task(M2C_UNK, M2C_UNK*); /* extern */
extern M2C_UNK D_800D1F28;
void func_8001E534(void);

void func_8001E6AC(void) {
    M2C_FIELD(&D_800D1F28, s8*, 0) = 1;
    M2C_FIELD(&D_800D1F28, s8*, 1) = 0;
    M2C_FIELD(&D_800D1F28, s8*, 2) = 0;
    M2C_FIELD(&D_800D1F28, s8*, 3) = 0;
    create_task(0, &func_8001E534);
}
#undef M2C_UNK
#undef M2C_FIELD

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001D2A0.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_8009A424;

void func_8001E6F0(void* arg0) {
    if (D_8009A424 == 0) {
        M2C_FIELD(arg0, s8*, 0xD) = 0;
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}
#undef M2C_FIELD

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void silence_sound(s32, s32); /* extern */
void func_80017D88(void);     /* extern */
void func_80027288(void);     /* extern */
void func_8002D004(void);     /* extern */
extern s8 D_8009A424;

void func_8001E71C(void* arg0) {
    if (D_8009A424 == 0) {
        M2C_FIELD(arg0, s8*, 0xD) = 1;
        func_80027288();
        func_80017D88();
        silence_sound(0xFF, 0);
        func_8002C50C();
        func_8002D004();
        M2C_FIELD(arg0, s8*, 1) = 0;
        M2C_FIELD(arg0, u8*, 0) = (u8)(M2C_FIELD(arg0, u8*, 0) + 1);
    }
}
