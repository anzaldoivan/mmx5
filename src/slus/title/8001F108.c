#include "types.h"
#include "mmx5/globals.h"

extern void func_8002CF20(void);
extern s32 func_80013674(void);
extern void func_80017668(void);
extern void func_8002D004(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_80013288(s32);
extern u8 D_800D1C00[];
extern u8 D_8009A1F8[];

void func_8001F108(u8* a0) {
    u8* p;
    u8* q;

    a0[0xD] = 2;
    func_8001E668();
    func_8002CF20();
    p = D_800D1C00;
    p[0xC] = 0xE;
    p[0xD] = 0;
    func_80013674();
    func_80017668();
    func_8002C50C();
    func_8002D004();
    init_checkpoint_positions();
    func_8002906C();
    func_80027238();
    q = D_8009A1F8;
    q[3] = 1;
    q[0x57] = 0;
    q[0xAB] = 0;
    func_80013288(8);
    a0[1]++;
}

extern u8 D_80070F28[];

void func_8001F1B0(u8* a0) {
    u8* obj;
    u32 i;

    for (i = 0; i < 1; i++) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x13;
            obj[2] = D_80070F28[i];
        }
    }
    *(u16*)(a0 + 4) = 0x258;
    a0[0xD] = 0;
    a0[1]++;
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001DF5C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/E47C.c:func_8001E638, AGPL-3.0; proven shared with X6 by exact signature 0bffad427ba7 (see THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
void func_800132F8(s32);

void tick_title_demo_timer(struct X4_GameInfo* arg0) {
    M2C_FIELD(arg0, s16*, 0x4)--;
    if (M2C_FIELD(arg0, s16*, 0x4) == 0) {
        func_800132F8(8);
        arg0->mode++;
    }
}
