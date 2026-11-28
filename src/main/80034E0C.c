#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void func_800132F8(s8 arg);

void func_80034E0C(u8* arg0) {
    func_800132F8(8);
    ((s32(*)())func_800272DC)();
    arg0[5] = 1;
}

extern s8 D_8009A424;
void func_800183E8(void);

void func_80034E44(u8* arg0) {
    if (D_8009A424 != 0) {
        func_800272DC();
    } else {
        func_800183E8();
        arg0[5] = 2;
    }
}

extern void func_80013288(s32);
extern void run_stage_frame(void);
extern void func_8003DF20(u8* p);
extern void func_8003EE38(u8* p);
extern void player_reset_charge(u8* p);
extern void func_8003F35C(void);
extern s8 D_800E9528;

void func_80034E90(u8* arg0) {
    u8* p = g_Player;

    if (*(s32*)(arg0 + 0x38) == 0) {
        if (*(s8*)(p + 2) == 0) {
            func_8003F35C();
            if (D_800E9528 != *(s8*)(p + 0x93)) {
                player_reset_charge(p);
            }
            func_8003EE38(p);
            if (D_800E9528 != *(s8*)(p + 0x93)) {
                if (D_800E9528 == 6) {
                    if (p[0x91] != 0) {
                        p[0x91] = 1;
                    }
                    if (p[0x92] != 0) {
                        p[0x92] = 1;
                    }
                }
                func_8003DF20(p);
            }
        }
        D_800C9310.b |= 1;
        run_stage_frame();
        func_80013288(8);
    }
    arg0[5] = 3;
}

extern s8 D_8009A424;
extern s8 D_800D1C01;
extern s32 D_8009A1F0;
extern s32 D_80091D54;
extern void func_800272B4(void);

void func_80034F84(u8* a0) {
    u8* p;

    if (D_8009A424 == 0) {
        if (*(s32*)(a0 + 0x38) == 0) {
            D_800D1C01 = 0;
        } else {
            p = g_playthrough_state.u;
            p[0x27] = 2;
            p[0] = 0xB;
            p[1] = 0;
            p[2] = 0;
            p[0x10] = 0;
            p[0x11] = 0;
            p[0x12] = 0;
            p[0x13] = 0;
            p[0x14] = 0;
            p[0x15] = 0;
            p[0x16] = 0;
            p[0x17] = 0;
            D_80091D54 = 0;
            *(s32*)(p + 0xB0) += D_8009A1F0;
        }
        a0[4] = 0;
        a0[5] = 0;
    }
    if (*(s32*)(a0 + 0x38) == 0) {
        func_800272B4();
    }
}
