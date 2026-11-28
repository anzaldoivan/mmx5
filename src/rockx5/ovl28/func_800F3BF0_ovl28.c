#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002B5B4(s32);
void func_8002A5C4(s32, s32, s32);
void start_pad_vibration(s32);
extern u8 D_80074E40[];
extern u8 D_800FE2CC_ovl28[];
extern u8 D_800FE2D0_ovl28[];
extern u8 D_800FE2D4_ovl28[];
extern u8 D_800FE2D8_ovl28[];
extern u8 D_800FE2DC_ovl28[];
extern u8 D_800FE2E0_ovl28[];
extern s8 D_800FE304_ovl28[][2];
extern u16 D_800FE308_ovl28[];

void func_800F3BF0_ovl28(void* self) {
    void* parent;
    void* g;
    s32 a;
    s32 b;
    s32 i;
    s8 dx;
    s32 t; // !FAKE: one temp set twice in case 2/3 (0x60 = 0xA, 5 = 2) keeps li;sb at block head (C0052)
    s8 dy;
    s32 pa;

    M2C_FIELD(self, u8*, 3) = 1;
    M2C_FIELD(self, u8*, 0x16) = 1;
    g = g_Player;
    M2C_FIELD(self, u8*, 0x14) = M2C_FIELD(g, u8*, 0x14);
    parent = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, void**, 0x68) = 0;
    switch (M2C_FIELD(self, u8*, 2) & 0xF) {
    case 0:
        M2C_FIELD(self, void**, 0x50) = D_800FE2CC_ovl28;
        M2C_FIELD(self, void**, 0x54) = D_800FE2CC_ovl28;
        M2C_FIELD(self, void**, 0x68) = D_800FE2D0_ovl28;
        M2C_FIELD(self, void**, 0x58) = D_80074E40;
        M2C_FIELD(self, u8*, 0x60) = 0xA;
        M2C_FIELD(self, s32*, 0x20) = 0xA0000;
        a = func_8002B5B4(0x40);
        b = func_8002B5B4(0x40);
        M2C_FIELD(self, u16*, 0x42) =
            ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s32*, 0x20) = -M2C_FIELD(self, s32*, 0x20);
        }
        M2C_FIELD(self, s32*, 0x24) = 0;
        set_animation(self, 0xF);
        M2C_FIELD(self, u8*, 5) = 0;
        play_sound(2, 0x6C, parent);
        play_sound(2, 0x74, parent);
        break;
    case 1:
        M2C_FIELD(self, void**, 0x50) = D_800FE2E0_ovl28;
        M2C_FIELD(self, u8*, 0x60) = 8;
        M2C_FIELD(self, void**, 0x54) = 0;
        M2C_FIELD(self, u8*, 0x8F) = 0;
        M2C_FIELD(self, s32*, 0x20) <<= 7;
        M2C_FIELD(self, s32*, 0x24) <<= 7;
        set_animation(self, 0x18);
        load_palette(0x13E, D_1F800024 + 0x6C0, 1);
        load_palette(0x13F, D_1F800024 + 0x6C0, 1);
        M2C_FIELD(self, u16*, 0x42) = 0x7CCE;
        M2C_FIELD(self, u8*, 5) = 1;
        play_sound(2, 0x6C, self);
        play_sound(2, 0x78, self);
        break;
    case 2:
    case 3:
        t = 0xA;
        M2C_FIELD(self, u8*, 0x60) = t;
        M2C_FIELD(self, void**, 0x50) = D_800FE2D4_ovl28;
        M2C_FIELD(self, void**, 0x54) = 0;
        if ((M2C_FIELD(self, u8*, 2) & 0xF) == 2) {
            i = 1;
            M2C_FIELD(self, s32*, 0x20) = 0x60000;
            M2C_FIELD(self, u8*, 0x15) = 0x40;
        } else {
            i = 0;
            M2C_FIELD(self, s32*, 0x20) = 0xFFFA0000;
            M2C_FIELD(self, u8*, 0x15) = 0;
        }
        dx = D_800FE304_ovl28[i][0];
        dy = D_800FE304_ovl28[i][1];
        if (M2C_FIELD(parent, u8*, 0x15) == 0) {
            pa = M2C_FIELD(parent, u16*, 0xA);
            M2C_FIELD(self, u16*, 0xA) = dx + pa;
        } else {
            M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(parent, u16*, 0xA) - dx;
            M2C_FIELD(self, s32*, 0x20) = -M2C_FIELD(self, s32*, 0x20);
            M2C_FIELD(self, u8*, 0x15) ^= 0x40;
        }
        pa = M2C_FIELD(parent, u16*, 0xE);
        M2C_FIELD(self, u16*, 0xE) = dy + pa;
        M2C_FIELD(self, s32*, 0x24) = 0;
        set_animation(self, 0x10);
        t = 2;
        M2C_FIELD(self, u8*, 5) = t;
        break;
    case 4:
    case 5:
    case 7:
        func_8002A5C4(0x20, 8, 1);
    case 6:
    case 8:
    case 9:
        if ((M2C_FIELD(self, u8*, 2) & 0xF) == 4) {
            set_animation(self, 0x12);
            // !FAKE: block-local g copies (cases 4/5/6) split the pseudo: value reg != addr reg
            {
                void* p = g_Player;
                M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p, u16*, 0xA);
            }
        } else if ((M2C_FIELD(self, u8*, 2) & 0xF) == 5) {
            set_animation(self, 0x13);
            {
                void* p = g_Player;
                M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p, u16*, 0xA) + 0x2E;
            }
            M2C_FIELD(self, u8*, 0x15) = 0;
        } else if ((M2C_FIELD(self, u8*, 2) & 0xF) == 6) {
            set_animation(self, 0x13);
            {
                void* p = g_Player;
                M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(p, u16*, 0xA) - 0x2E;
            }
            M2C_FIELD(self, u8*, 0x15) = 0x40;
        } else {
            set_animation(self, 0x12);
            M2C_FIELD(self, u16*, 0xA) =
                (&D_8009A1F8.row[M2C_FIELD(self, s8*, 0x14)])->unkA + 0xA0;
            M2C_FIELD(self, u16*, 0xA) +=
                D_800FE308_ovl28[(M2C_FIELD(self, u8*, 2) & 0xF) - 7];
        }
        M2C_FIELD(self, u8*, 0x60) = 0xC;
        M2C_FIELD(self, void**, 0x54) =
            0; // 0x54 before 0x50: source order sets the sb/lui schedule
        M2C_FIELD(self, void**, 0x50) = D_800FE2D8_ovl28;
        M2C_FIELD(self, u16*, 0xE) = 0x260;
        M2C_FIELD(self, s32*, 0x20) = 0;
        M2C_FIELD(self, s32*, 0x24) = 0xFFFA0000;
        M2C_FIELD(self, u8*, 5) = 4;
        play_sound(2, 0x6C, self);
        start_pad_vibration(3);
        break;
    case 10:
        set_animation(self, 0x1C);
        M2C_FIELD(self, u8*, 0x60) = 0xC;
        M2C_FIELD(self, void**, 0x58) = D_80074E40;
        M2C_FIELD(self, void**, 0x50) = D_800FE2DC_ovl28;
        M2C_FIELD(self, void**, 0x54) = D_800FE2DC_ovl28;
        M2C_FIELD(self, u8*, 5) = 6;
        M2C_FIELD(self, u8*, 0x8D) = 0x5A;
        break;
    }
    M2C_FIELD(self, u8*, 4)++;
    func_8002D9EC(self, 0x20, 0x14);
}
