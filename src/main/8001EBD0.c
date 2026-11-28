#include "types.h"
#include "mmx5/globals.h"

extern void func_80027288(void);
extern void func_80017D88(void);
extern void silence_sound(s32, s32);
extern void func_8002D004(void);
extern void func_80013BD4(void);
extern void func_800176B0(void);
extern void func_80013288(s32);

void func_8001EBD0(u8* arg0) {
    u8* p;

    arg0[0xD] = 1;
    func_80027288();
    func_80017D88();
    silence_sound(0xFF, 0);
    func_8002C50C();
    func_8002D004();
    func_80013BD4();
    func_800176B0();
    p = func_8002D27C();
    if (p != 0) {
        p[1] = 0x15;
        p[0] = 1;
        p[0x47] = 0;
        p[2] = 0;
        *(s16*)(p + 0xA) = 0x80;
        *(s16*)(p + 0xE) = 0x78;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[1] = 0x15;
        p[0] = 1;
        p[0x47] = 1;
        p[2] = 0;
        *(s16*)(p + 0xA) = 0x120;
        *(s16*)(p + 0xE) = 0x78;
    }
    *(s16*)(arg0 + 4) = 0x12C;
    func_80013288(8);
    arg0[1]++;
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001D8A0.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/game_info.c:func_8001D64C, AGPL-3.0; proven shared with X6 by exact signature 370ee8910a36 (see THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
void func_800132F8(s32);

void func_8001ECBC(struct X4_GameInfo* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x4) == 0) {
        arg0->mode++;
        func_800132F8(8);
    }
}
#undef M2C_FIELD

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001D8EC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/game_info.c:func_8001D698, AGPL-3.0; proven shared with X6 by exact signature 08f62733c4aa (see THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8001ED08(struct X4_GameInfo* arg0) {
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    M2C_FIELD(arg0, s8*, 0x0) = 0;
    arg0->mode = 0;
    M2C_FIELD(arg0, s8*, 0x2) = 0;
    M2C_FIELD(arg0, s8*, 0x3) = 0;
    if (++M2C_FIELD(arg0, s8*, 0xC) == 4) {
        M2C_FIELD(arg0, s8*, 0xC) = 0;
    }
}
#undef M2C_FIELD

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001D930.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/game_info.c:func_8001D6DC, AGPL-3.0; proven shared with X6 by exact signature 07619b425e9d (see THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
void func_80022618(void);
extern s8 D_8009A424;
#define D_8009A424 (*(s8(*)[]) & D_8009A424)
void func_800272B4();

#define M2C_UNK s32
void func_80024698(void);
void func_8001ED4C(struct X4_GameInfo* arg0) {
    if (D_8009A424[0] == 0) {
        if (M2C_FIELD(arg0, s8*, 0xE) == 1) {
            M2C_FIELD(arg0, s8*, 0x0) = 6;
        } else {
            M2C_FIELD(arg0, s8*, 0x0) = 1;
        }
        return;
    }

    switch (M2C_FIELD(arg0, s8*, 0xE)) {
    case 0:
        break;
    case 1:
        func_80022618();
        func_800272B4();
        break;
    case 2:
        func_800272B4();
        break;
    case 3:
        func_80022618();
        func_80024698();
        break;
    }
}
#undef D_8009A424
