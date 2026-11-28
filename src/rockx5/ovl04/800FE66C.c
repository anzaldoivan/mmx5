#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/object.h"

extern s32 func_80024548(s32);
extern signed char D_8009A0A5;
extern u8 D_80102A50_ovl04[];

void func_800FE66C_ovl04(u8* arg0) {
    u8* g;

    if (D_8009A0A5 == 0x14) {
        g = g_playthrough_state.u;
        g[0x24] = 1;
        g[0x25] = 0;
        *(u8**)(g + 0x20) = arg0;
        arg0[0x5C] = 0;
        if (((s8*)arg0)[2] == 1) {
            g[0xA2] = 0x7F;
        } else if (((s8*)arg0)[2] == 9) {
            ((s32(*)())func_80028B18)(0, 0xBA0, 0x3A0, D_80102A50_ovl04);
            g[0xA2] = 0x7F;
        } else {
            g[0xA2] = 0x7F;
        }
        func_80024548(0);
        *(s16*)(arg0 + 0x7C) = 2;
        arg0[5]++;
    }
}

extern u8 D_800755C0[];

void func_800FE720_ovl04(u8* p) {
    if (*(s8*)(p + 0x5C) < D_800D1CA2) {
        if (--*(s16*)(p + 0x7C) == 0) {
            play_sound(0, 0xE, 0);
            *(s16*)(p + 0x7C) = 2;
        }
        p[0x5C]++;
    } else {
        func_8003D2C4();
        *(u8**)(p + 0x58) = D_800755C0;
        p[5]++;
        p[0x8F] = 0;
        if (*(s8*)(p + 2) == 1) {
            p[0x8D] = 0x78;
        } else if (*(s8*)(p + 2) == 9) {
            p[0x8D] = 0x3C;
        } else {
            p[0x8D] = 0x3C;
        }
    }
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void func_8002A600(s32, s32, s32);
extern s8 D_8009A0A5;
extern u16 D_8009A22C;

void func_800FE7E4_ovl04(u8* p) {
    s32 s1;
    s32 s0;

    if (!(D_8009A420_as_s32 & 7)) {
        s1 = *(s32*)(p + 0x8);
        s0 = *(s32*)(p + 0xC);
        *(u16*)(p + 0xA) += 0x20;
        *(u16*)(p + 0xE) -= 0x20;
        func_8004FD90(p, 1, 0x1F, 0x7F);
        func_8004FD90(p, 1, 0x1F, 0x7F);
        func_8004FD90(p, 1, 0x1F, 0x7F);
        func_8004FD90(p, 1, 0x1F, 0x7F);
        *(s32*)(p + 0x8) = s1;
        *(s32*)(p + 0xC) = s0;
    }
    *(u16*)(p + 0x7C) += 1;
    if (D_8009A22C == 0) {
        func_8002A600(0x30, 3, 2);
    }
    if (*(s16*)(p + 0x7C) >= 0xB4 && D_8009A0A5 == 0x14) {
        p[5]++;
    }
}
#undef D_8009A420_as_s32

extern u16 D_8009A22C;

void func_800FE8F8_ovl04(void) {
    if (D_8009A22C == 0) {
        u8* p = g_playthrough_state.u;
        p[0x26] |= 4;
        clear_object_slot();
    }
}
