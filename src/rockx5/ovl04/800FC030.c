#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"

extern void func_800FBA74_ovl04(u8* o);
extern void func_800FBEF8_ovl04(u8* o);
extern u8 D_80102B30_ovl04[][2];

void func_800FC030_ovl04(u8* o) {
    u8* p;
    u8* q;
    u8* r;
    s32 i;
    s32 t;

    func_800FBEF8_ovl04(o);
    func_800FBA74_ovl04(o);
    p = g_playthrough_state.u;
    if (*(u16*)(p + 0x28) == 0) {
        if (o[0x8D] == 0 || --o[0x8D] == 0) {
            i = random_byte() & 0xF;
            p[0x28] = D_80102B30_ovl04[i][0];
            p[0x29] = D_80102B30_ovl04[i][1];
            o[0x8D] = 0x78;
        }
    }
    r = g_playthrough_state.u;
    if (r[0x26] & 2) {
        ((s32(*)())func_8003D29C)(0x14, 0x40);
        o[5]++;
        o[0x8D] = 0x78;
        o[0x90] = 0x40;
        o[0x91] = 0x40;
    }
    q = D_8009A1F8.u;
    t = *(s16*)(o + 0x86) - 0x120;
    *(s16*)(o + 0xA) = *(u16*)(q + 0xA) - t;
    *(s16*)(o + 0xE) = *(u16*)(q + 0xE) + 0x58;
}

extern void start_pad_vibration(s32);
extern u8* alloc_class3_slot(void);
extern s32 func_800F033C_ovl04(void);
extern u8 D_80074EE0[];
extern u8 D_80102A9C_ovl04[];
extern u8 D_80102AA0_ovl04[];
extern u8 D_800755C0[];
extern u8 D_8009A0B5;
extern s8 D_8009A23C[];
extern u8* D_8010308C_ovl04;
extern u8 D_80102B50_ovl04[][2];

void func_800FC144_ovl04(u8* o) {
    s32 r;
    s32 flag;
    s32 x;
    s32 z;
    s32 v;
    s32 sum;
    s32 w;
    s32 h;
    u8* p;
    u8* g;
    u8* q;
    s32 i;

    if (o[0x8F] != 0) {
        *(u8**)(o + 0x58) = D_80074EE0;
        *(u8**)(o + 0x54) = D_80102A9C_ovl04;
        if (func_80031DD0(o)) {
            g_playthrough_state.u[0x27] |= 1;
        }
        *(u8**)(o + 0x54) = D_80102AA0_ovl04;
        if (func_80031DD0(o)) {
            g_playthrough_state.u[0x27] |= 1;
        }
        if (o[0x8F]-- & 2) {
            *(u16*)(o + 0x42) |= 0x8000;
        } else {
            *(u16*)(o + 0x42) &= 0x7FFF;
        }
        if (o[0x8F] == 0) {
            *(u16*)(o + 0x42) &= 0x7FFF;
        }
    } else {
        flag = 0;
        *(u8**)(o + 0x58) = D_800755C0;
        if (!(g_playthrough_state.u[0x2A] & 1)) {
            *(u8**)(o + 0x54) = D_80102A9C_ovl04;
            o[0x5C] = o[0x90];
            r = func_80031DD0(o);
            if (r < 0) {
                flag = 1;
                g_playthrough_state.u[0x2A] |= 1;
                g_playthrough_state.u[0x27] |= 1;
                o[0x90] = 0;
                func_8004FD24(o);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
            }
            if (r > 0) {
                flag |= 1;
                g_playthrough_state.u[0x27] |= 1;
                if (r != 0x7F) {
                    if (r == 0x19 || r == 0x1A) {
                        o[0x8F] = 2;
                    } else {
                        o[0x8F] = 0x1E;
                    }
                }
                o[0x90] = o[0x5C];
            }
        }
        if (!(g_playthrough_state.u[0x2A] & 2)) {
            if (((s8*)g_playthrough_state.u)[0x27] != 0) {
                *(u8**)(o + 0x58) = D_80074EE0;
            }
            *(u8**)(o + 0x54) = D_80102AA0_ovl04;
            o[0x5C] = o[0x91];
            r = func_80031DD0(o);
            if (r < 0) {
                flag |= 1;
                g_playthrough_state.u[0x2A] |= 2;
                g_playthrough_state.u[0x27] |= 1;
                x = *(s32*)(o + 0x8);
                z = *(s32*)(o + 0xC);
                o[0x91] = 0;
                *(s16*)(o + 0xA) += 0x20;
                *(s16*)(o + 0xE) += 0x30;
                func_8004FD24(o);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                *(s32*)(o + 0x8) = x;
                *(s32*)(o + 0xC) = z;
            }
            if (r > 0) {
                flag |= 1;
                g_playthrough_state.u[0x27] |= 1;
                if (r != 0x7F) {
                    if (r == 0x19 || r == 0x1A) {
                        o[0x8F] = 2;
                    } else {
                        o[0x8F] = 0x1E;
                    }
                }
                o[0x91] = o[0x5C];
            }
        }
        if (flag) {
            *(u16*)(o + 0x42) |= 0x8000;
        } else {
            *(u16*)(o + 0x42) &= 0x7FFF;
        }
    }
    sum = o[0x90] + o[0x91];
    o[0x5C] = sum;
    if ((s8)sum == -0x80) {
        o[0x5C] = 0x7F;
    }
    if ((g_playthrough_state.u[0x2A] & 3) == 3) {
        start_pad_vibration(10);
        g_playthrough_state.u[0x2A] |= 4;
        func_8003D29C(0x14, D_8009A0B5);
        h = *(u16*)(o + 0x42);
        o[5] += 1;
        h &= 0x7FFF;
        *(u16*)(o + 0x42) = h;
        g_playthrough_state.u[0x24] = 0;
        D_8009A23C[0] = 1;
        *(s16*)(o + 0x7C) = 0;
        p = alloc_class3_slot();
        D_8010308C_ovl04 = p;
        if (p != 0) {
            p[0] = 1;
            D_8010308C_ovl04[1] = 0xB;
        }
        return;
    }
    if (func_800F033C_ovl04()) {
        v = *(s32*)(o + 0x84) + 0x10000;
        *(s32*)(o + 0x84) = v;
        if (v > 0x1FFFFF) {
            *(s32*)(o + 0x84) = 0x200000;
        }
    }
    g = g_playthrough_state.u;
    if (((s8*)g)[0x27] != 0) {
        g[0x27] = 0;
    }
    if (*(u16*)(g + 0x28) == 0) {
        if (o[0x8D] == 0 || --o[0x8D] == 0) {
            i = random_byte() & 0xF;
            g[0x28] = D_80102B50_ovl04[i][0];
            g[0x29] = D_80102B50_ovl04[i][1];
            o[0x8D] = 0x3C;
        }
    }
    q = D_8009A1F8.u;
    w = *(s16*)(o + 0x86) - 0x120;
    *(s16*)(o + 0xA) = *(u16*)(q + 0xA) - w;
    *(s16*)(o + 0xE) = *(u16*)(q + 0xE) + 0x58;
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void func_8002A600(s32, s32, s32);
extern u16 D_8009A22C;
extern u8* D_8010308C_ovl04;

void func_800FC6A0_ovl04(u8* a0) {
    s32 x;
    s32 y;
    u8* p;

    *(u16*)(a0 + 0xA) += 1;
    if (!(D_8009A420_as_s32 & 3)) {
        x = *(s32*)(a0 + 0x8);
        y = *(s32*)(a0 + 0xC);
        *(u16*)(a0 + 0xA) -= 0x10;
        *(u16*)(a0 + 0xE) += 8;
        func_8004FD90(a0, 1, 0x1F, 0x7F);
        func_8004FD90(a0, 1, 0x1F, 0x7F);
        func_8004FD90(a0, 1, 0x1F, 0x7F);
        func_8004FD90(a0, 1, 0x1F, 0x7F);
        *(s32*)(a0 + 0x8) = x;
        *(s32*)(a0 + 0xC) = y;
    }
    if (*(s16*)(a0 + 0xA) < 0xCB7 && D_8009A22C == 0) {
        func_8002A600(0x10, 3, 2);
    }
    if (*(s16*)(a0 + 0xA) >= 0xCC0) {
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
