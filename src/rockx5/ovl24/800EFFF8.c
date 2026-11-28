#include "types.h"
#include "mmx5/ovl24.h"
#include "mmx5/globals.h"

extern u8 D_800F5F7A_ovl24;
extern void func_8002D004(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);

void func_800EFFF8_ovl24(u8* a0) {
    D_800F5F7F_ovl24.u = g_playthrough_state.u[0x44];
    func_8002C50C();
    func_8002D004();
    init_checkpoint_positions();
    func_8002906C();
    func_80027238();
    a0[0xE] = 0;
    g_playthrough_state.u[0x28] = 0;
    D_800F5F7A_ovl24 = 0;
    D_800F5F80_ovl24 = 0;
    g_Player[0xC9] = a0[0x4C];
    g_Player[2] = D_800F5F7F_ovl24.u;
    a0[2]++;
}

extern s32 func_800177B0(s32, s32);

void func_800F009C_ovl24(u8* arg0) {
    func_800177B0(0x19, 0x7F);
    arg0[2]++;
}

extern void func_80013288(s32);
extern u8 D_800D1F3C;

void func_800F00D4_ovl24(u8* arg0) {
    if (D_800D1F3C == 2) {
        func_80013288(8);
        arg0[2]++;
    }
}

void func_800F011C_ovl24(u8* arg0) {
    arg0[1] = 1;
    arg0[2] = 0;
    arg0[3] = 0;
}
