#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "addr.h"

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_8009A197;
extern u8 D_800F95F0_ovl11[];
extern void* D_800F967C_ovl11[];

void func_800EEBF0_ovl11(u8* arg0) {
    if (func_80031DD0(arg0) < 0 && *(s8*)(arg0 + 5) != 3) {
        func_8004FD24(arg0);
        func_8004D4F4(2, D_800F95F0_ovl11, arg0);
        *(s16*)(arg0 + 0x82) = 0;
        arg0[3] = 0;
        arg0[4] = 2;
        return;
    }
    if (D_8009A197 == 0 && *(s16*)(arg0 + 0x84) != 0) {
        ((void (*)(u8*))D_800F967C_ovl11[*(s8*)(arg0 + 5)])(arg0);
    }
    if (*(s8*)(arg0 + 0x45) == 4) {
        play_sound(5, 0x19, arg0);
    }
    func_800317B8(arg0);
    if (*(s8*)(arg0 + 5) == 2) {
        func_8002D89C(arg0);
    } else {
        arg0[3] = 0;
    }
    if (*(s16*)(arg0 + 0x84) == 0) {
        u8* d = D_8009A1F8.u;
        s32 dx = *(u16*)(arg0 + 0xA) - *(u16*)(d + 0xA);
        s16 dy = *(u16*)(arg0 + 0xE) - *(u16*)(d + 0xE);
        if ((u16)dx < 0x140 && (u16)dy < 0xF0) {
            *(s16*)(arg0 + 0x84) = 1;
        }
    }
}

extern u8* find_free_visual_obj(void);
extern s32 func_8002DFB0(void);
extern void start_pad_vibration(s32);
extern s32 func_8002B5B4(s32);
extern u8 D_800F9618_ovl11[];
extern s16 D_800F9648_ovl11[][4];
extern s16 D_800F9620_ovl11[][4];
extern u8 D_8009A244;
extern u16 D_800F95F4_ovl11[];
extern u16 D_800F9604_ovl11[];
extern u32* D_80098118;
extern s8 D_800D1C26;

void func_800EED38_ovl11(u8* a0) {
    u8* p;
    u8* q;
    u8* r;
    u8* base;
    u16* tx;
    u16* ty;
    s32 a;
    s32 b;
    s32 i;
    s32 t;

    a0[3] = 0;
    if (*(s16*)(a0 + 0x7C) == 0) {
        if (*(u16*)(a0 + 0x82) != 0) {
            r = func_8002D1A4();
            if (r != 0) {
                r[0] = 0x41;
                r[1] = 0x2A;
                *(u16*)(r + 0x40) = *(u16*)(a0 + 0x40);
                *(u16*)(r + 0x42) = *(u16*)(a0 + 0x42) & 0x7FFF;
                *(u32*)(r + 0x3C) = *(u32*)(a0 + 0x3C);
                r[0x14] = a0[0x14];
                base = g_Player;
                *(u32*)(r + 8) = *(u32*)(base + 8);
                *(u32*)(r + 0xC) = *(u32*)(base + 0xC);
                *(u32*)(r + 0x30) = *(u32*)(a0 + 0x30);
                *(u8**)(r + 0x7C) = a0;
            }
            func_800317B8(a0);
        } else {
            *(u8**)(a0 + 0x50) = D_800F9618_ovl11;
            func_800317B8(a0);
        }
        if (((s8*)a0)[2] < 5) {
            i = ((s8*)a0)[2];
            func_80028B18(0, D_800F9648_ovl11[i][0], D_800F9648_ovl11[i][1],
                          D_800F9620_ovl11[i]);
            D_8009A244 = 1;
        }
    }
    if (((s8*)a0)[2] < 5) {
        if ((a0[0x7C] & 0xF) == 0) {
            q = find_free_visual_obj();
            if (q != 0) {
                q[0] = 0x21;
                q[1] = 4;
                q[2] = 0;
                q[4] = 0;
                q[5] = 0;
                q[6] = 0;
                t = func_8002DFB0();
                *(u16*)(q + 0xA) =
                    (u16)D_800F9648_ovl11[((s8*)a0)[2]][0] +
                    t % ((u16)D_800F9620_ovl11[((s8*)a0)[2]][2] << 4);
                t = func_8002DFB0();
                *(u16*)(q + 0xE) =
                    (u16)D_800F9648_ovl11[((s8*)a0)[2]][1] +
                    t % ((u16)D_800F9620_ovl11[((s8*)a0)[2]][3] << 4);
                q[0x15] = 0;
                q[0x14] = 0;
                q[0x16] = 1;
            }
        }
        if (*(s16*)(a0 + 0x7C) < 0x1E) {
            if (*(s16*)(a0 + 0x7C) == 0x14) {
                start_pad_vibration(3);
            }
            if ((a0[0x7C] & 7) == 0) {
                tx = D_800F95F4_ovl11;
                ty = D_800F9604_ovl11;
                for (i = 1; i >= 0; i--) {
                    p = func_8002D27C();
                    if (p != 0) {
                        p[0] = 0x41;
                        p[1] = 0x31;
                        p[0x15] = random_byte() & 0x40;
                        p[2] = 0;
                        *(u16*)(p + 0xA) = D_800F9648_ovl11[((s8*)a0)[2]][0] +
                                           tx[random_byte() & 7];
                        if ((u8)(a0[2] - 3) < 2) {
                            *(u16*)(p + 0xA) += 0x30;
                            *(u16*)(p + 0xE) += 0x30;
                        }
                        *(u16*)(p + 0xE) = D_800F9648_ovl11[((s8*)a0)[2]][1] +
                                           ty[random_byte() & 7];
                        *(u16*)(p + 0x40) =
                            D_80098118[func_8002B5B4(0x93)] >> 7;
                        a = func_8002B5B4(0x93);
                        *(s32*)(p + 0x3C) =
                            (s32)D_1F800020.u32s + D_1F800020.u32s[a];
                        a = func_8002B5B4(0x93);
                        b = func_8002B5B4(0x93);
                        *(u16*)(p + 0x42) = ((a * 4 + 0x18) % 16) |
                                            ((((b + 6) / 4) + 0x1E0) << 6);
                        p[0x14] = g_Player[0x14];
                    }
                }
            }
        }
    } else {
        t = (s8)a0[2];
        if (t == 5) {
            D_800D1C26 = 1;
        } else if (t == 6) {
            D_800D1C26 = 2;
        }
    }
    if (*(s16*)(a0 + 0x7C) >= 0x5B) {
        clear_object_slot(a0);
    } else {
        *(s16*)(a0 + 0x7C) += 1;
    }
}
