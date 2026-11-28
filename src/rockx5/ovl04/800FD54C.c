#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"

extern void start_pad_vibration(s32);
extern u8* alloc_class3_slot(void);
extern void func_800FD484_ovl04(u8* a0);
extern u8 D_80074EE0[];
extern u8 D_800755C0[];
extern u8* D_8010308C_ovl04;
extern u8* D_80103094_ovl04[];
extern u8 D_8010309C_ovl04[];

void func_800FD54C_ovl04(u8* arg0) {
    s32 r;
    s32 i;
    u8* p;
    u8* b;
    u8 t;

    if (g_playthrough_state.u[0x2A] & 1) {
        r = func_80031DD0(arg0);
    } else {
        r = 0;
    }
    if (r < 0) {
        start_pad_vibration(0xA);
        g_playthrough_state.u[0x2A] |= 4;
        *(u16*)(arg0 + 0x42) &= 0x7FFF;
        arg0[5]++;
        g_playthrough_state.u[0x24] = 0;
        for (i = 0; i < 2; i++) {
            p = D_80103094_ovl04[i];
            if (p != 0 && (s8)p[4] < 2) {
                p[4] = 5;
                D_80103094_ovl04[i] = 0;
                D_8010309C_ovl04[i] = 0x3C;
            }
        }
        D_8009A1F8.u[0x44] = 1;
        *(s16*)(arg0 + 0x7C) = 0;
        D_8010308C_ovl04 = alloc_class3_slot();
        if (D_8010308C_ovl04 != 0) {
            *D_8010308C_ovl04 = 1;
            D_8010308C_ovl04[1] = 0xB;
        }
        return;
    }
    if (r > 0 && r != 0x7F) {
        arg0[0x8F] = (u32)(r - 0x19) < 2 ? 2 : 0x1E;
        *(u8**)(arg0 + 0x58) = D_80074EE0;
    }
    t = arg0[0x8F];
    if (t != 0) {
        arg0[0x8F] = t + 0xFF;
        if (t & 2) {
            *(u16*)(arg0 + 0x42) |= 0x8000;
        } else {
            *(u16*)(arg0 + 0x42) &= 0x7FFF;
        }
        if (arg0[0x8F] == 0) {
            *(u8**)(arg0 + 0x58) = D_800755C0;
            *(u16*)(arg0 + 0x42) &= 0x7FFF;
        }
    }
    b = g_playthrough_state.u;
    if (((s8*)b)[0x28] == 0) {
        if (arg0[0x8D] == 0 || --arg0[0x8D] == 0) {
            b[0x28] = 1 << (random_byte() & 3);
            arg0[0x8D] = 0x3C;
        }
    }
    func_800FD484_ovl04(arg0);
    *(s16*)(arg0 + 0xE) = D_8009A206.s + 0xB0;
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void func_8002A600(s32, s32, s32);
extern u16 D_8009A22C;
extern u8* D_8010308C_ovl04;

void func_800FD778_ovl04(u8* a0) {
    s32 x;
    s32 y;
    u8* p;

    *(s16*)(a0 + 0xE) += 1;
    if (!(D_8009A420_as_s32 & 3)) {
        x = *(s32*)(a0 + 0x8);
        y = *(s32*)(a0 + 0xC);
        func_8004FD90(a0, 1, 0xFF, 0x1F);
        func_8004FD90(a0, 1, 0xFF, 0x1F);
        func_8004FD90(a0, 1, 0xFF, 0x1F);
        func_8004FD90(a0, 1, 0xFF, 0x1F);
        *(s32*)(a0 + 0x8) = x;
        *(s32*)(a0 + 0xC) = y;
    }
    if (*(s16*)(a0 + 0xE) < 0x137 && D_8009A22C == 0) {
        func_8002A600(0x10, 3, 2);
    }
    if (*(s16*)(a0 + 0xE) >= 0x140) {
        g_playthrough_state.u[0x2A] |= 8;
        if (D_8010308C_ovl04 != 0) {
            D_8010308C_ovl04[4] = 2;
        }
        a0[5]++;
    }
    if (!(D_8009A420_as_s32 & 7) && (random_byte() & 0x10)) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x18;
            p[2] = 0;
            *(u8**)(p + 0x50) = a0;
        }
    }
}
