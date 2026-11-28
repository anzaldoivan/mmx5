#include "types.h"
#include "mmx5/object.h"
#include "mmx5/ovl25.h"
#include "addr.h"
#include "mmx5/globals.h"

#define D_800F0CF4_ovl25_as_Blk200 (*(Blk200*)D_800F0CF4_ovl25)
#define D_800F10F4_ovl25_as_Blk200 (*(Blk200*)D_800F10F4_ovl25)
#define D_800F14F4_ovl25_as_Blk200 (*(Blk200*)D_800F14F4_ovl25)
#define D_800F18F4_ovl25_as_Blk200 (*(Blk200*)D_800F18F4_ovl25)
#define D_800F1CF4_ovl25_as_Blk200 (*(Blk200*)D_800F1CF4_ovl25)
#define D_800F20F4_ovl25_as_Blk200 (*(Blk200*)D_800F20F4_ovl25)

extern void func_80017668(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_800177B0(s32, s32);
extern void func_80013288(s32);

void func_800EE99C_ovl25(u8* arg0) {
    u8 i;
    u8* p;
    u8* src;

    for (i = 0; i < 16; i++) {
        p = arg0 + 0x26;
        p[i] = 0;
    }
    func_80017668();
    init_checkpoint_positions();
    func_8002906C();
    func_80027238();
    D_8009A1F8.u[3] = 0;
    D_8009A1F8.u[0x57] = 1;
    D_8009A1F8.u[0xAB] = 0;
    D_800C9310.b |= 1;
    src = D_1F800028 + 0xA00;
    D_800F0CF4_ovl25_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0xC00;
    D_800F10F4_ovl25_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0xE00;
    D_800F14F4_ovl25_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x1000;
    D_800F18F4_ovl25_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x1200;
    D_800F1CF4_ovl25_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x1400;
    D_800F20F4_ovl25_as_Blk200 = *(Blk200*)src;
    do {
        arg0[1]++;
        *(s16*)(arg0 + 4) = 0;
        arg0[2] = 0;
        func_800177B0(0x1C, 0x73);
    } while (0); // !FAKE: loop notes weight arg0's refs so it takes s0
    func_80013288(8);
}
#undef D_800F0CF4_ovl25_as_Blk200
#undef D_800F10F4_ovl25_as_Blk200
#undef D_800F14F4_ovl25_as_Blk200
#undef D_800F18F4_ovl25_as_Blk200
#undef D_800F1CF4_ovl25_as_Blk200
#undef D_800F20F4_ovl25_as_Blk200

extern s8 D_8009A424;
extern u8 D_800D1F3C;
extern u8 D_8009A2A3;
extern u8 D_800F0EF4_ovl25[];
extern u8 D_800F12F4_ovl25[];
extern u8 D_800F16F4_ovl25[];
extern u8 D_800F1AF4_ovl25[];
extern u8 D_800F1EF4_ovl25[];
extern u8 D_800F22F4_ovl25[];

void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800EEE48_ovl25(u8* arg0) {
    if (D_8009A424 == 0) {
        if (((s8*)arg0)[2] == 0) {
            if (D_800D1F3C == 2) {
                arg0[2]++;
            }
        } else {
            (*(u16*)(arg0 + 4))++;
            if (*(s16*)(arg0 + 4) >= 0x3D) {
                func_8002C3CC(D_800F0EF4_ovl25, D_800F0CF4_ovl25, 0x100, 0, 0);
                load_palette(0x50, D_800F0EF4_ovl25, 0x10);
                func_8002C3CC(D_800F12F4_ovl25, D_800F10F4_ovl25, 0x100, 0, 0);
                load_palette(0x60, D_800F12F4_ovl25, 0x10);
                func_8002C3CC(D_800F16F4_ovl25, D_800F14F4_ovl25, 0x100, 0, 0);
                load_palette(0x70, D_800F16F4_ovl25, 0x10);
                func_8002C3CC(D_800F1AF4_ovl25, D_800F18F4_ovl25, 0x100, 0, 0);
                load_palette(0x80, D_800F1AF4_ovl25, 0x10);
                func_8002C3CC(D_800F1EF4_ovl25, D_800F1CF4_ovl25, 0x100, 0, 0);
                load_palette(0x90, D_800F1EF4_ovl25, 0x10);
                func_8002C3CC(D_800F22F4_ovl25, D_800F20F4_ovl25, 0x100, 0, 0);
                load_palette(0xA0, D_800F22F4_ovl25, 0x10);
                D_8009A2A3 = 1;
                arg0[2] = 0;
                arg0[1]++;
            }
        }
    }
}
