#include "types.h"
#include "mmx5/globals.h"

extern void func_80013288(s32);
extern void load_stage_ovl_b(void);
extern void setup_file_load(s32, s32, s32);
extern void pump_file_loads(void);
extern void func_80017668(void);
extern void func_80020950(void);
extern void func_80020A3C(void);
extern s32 func_80020F44(void);
extern s32 func_80027238(void);
extern void func_8002906C(void);
extern void func_8002A440(void);
extern void func_8002A4E4(void);
extern void func_8002A554(void);
extern void init_checkpoint_positions(void);
extern void func_8002B474(void);
extern void func_8002B520(void);
extern void func_8002D004(void);
extern void func_8003BAC8(void);
extern u8 D_8006FADD;
extern s16 D_8009A41A;
extern s32 D_8009A758;
extern u8 D_800D1598;
extern s8 D_800D1C1D;

u8 D_80091C30[8] = {0};
u8 D_80091C38[12] = {0};
u8 D_80091C44 = 0;
u8 D_80091C45 = 0;
// gcc word-aligns arrays and caps aligned() at 8: the gap to D_80091C50 needs
// objects of its own
u16 D_80091C46 = 0;
u32 D_80091C48[2] = {0};
X4_P_TAG* D_80091C50[2][4][8] = {0};
u8 D_80091D50 = 0;
s32 D_80091D54 = 0;
u16 g_tilemap_layer_stride = 0;
// aligned(8): pads the gap after g_tilemap_layer_stride; the array ends where bss starts
u32* D_80091D60[168] __attribute__((aligned(8))) = {0};

void func_800203F0(u8* arg0) {
    u32 i;
    u8* p;
    u8* q;

    if (func_80020F44() != 0 && D_800D1598 != D_800D1C1D) {
        load_stage_ovl_b();
    }
    i = 0;
    if (*(s8*)(arg0 + 0xC) == 0xC) {
        if ((*(s32*)(arg0 + 0x1C) & 0xFFFF00) == 0xFF0A00) {
            setup_file_load(0x57, 4, D_8009A758);
            pump_file_loads();
        }
    }
    for (i = 0, q = arg0 + 0x26; i < 8; i++) {
        q[i] = 0;
    }
    p = D_80091C38;
    p[0xC] = 0;
    *(s16*)(p + 0x10) = 0;
    func_8002C50C();
    func_8002D004();
    func_80017668();
    func_8002906C();
    init_checkpoint_positions();
    func_8002A440();
    func_8002A4E4();
    func_8002A554();
    func_8003BAC8();
    func_8002B474();
    func_8002B520();
    arg0[0x1C] = 1;
    arg0[0x1F] = 0;
    arg0[0x24] = 0;
    arg0[0x10] = 0;
    arg0[0x11] = 0;
    arg0[0x12] = 0;
    arg0[0x13] = 0;
    arg0[0x14] = 0;
    arg0[0x15] = 0;
    arg0[0x16] = 0;
    arg0[0x17] = 0;
    arg0[0x18] = 0;
    arg0[0x19] = 0;
    arg0[0x1A] = 0;
    arg0[0xF] = 0;
    arg0[0x7B] = D_8006FADD;
    func_80027238();
    func_80020950();
    if (arg0[0x43] != 0) {
        arg0[0x43] = 0;
    } else {
        func_80020A3C();
    }
    func_80013288(8);
    arg0[0] = 0xA;
    D_80091D54 = 1;
    D_8009A41A = 0x3C;
}
