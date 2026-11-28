#include "types.h"
#include "mmx5/ovl33.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/object.h"
#include "mmx5/ovl06.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

extern u8* find_free_visual_obj(void);
extern u8 D_80075FC0[];
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_800FED70_ovl33[];
extern u8 D_800FEAD0_ovl33[];
extern u8 D_800FEACC_ovl33[];
extern u8 D_800FEAF4_ovl33[];

void func_800FA004_ovl33(u8* obj) {
    u8* p;
    u8* prev;
    s32 i;
    u8* b;
    u16 x;
    u16 y;

    D_1F80004C.bytes[0x86] = 0x36;
    obj[0x60] = 5;
    obj[0x5C] = 0;
    obj[0x61] = 0;
    *(u8**)(obj + 0x58) = D_80075FC0;
    if (g_playthrough_state.s[0xC] != 0xC) {
        *(s16*)(obj + 0x40) = (*D_80098118 >> 7) + 0x130;
    } else {
        *(s16*)(obj + 0x40) = (*D_80098118 >> 7) + 0x290;
        *(u8**)(obj + 0x3C) = D_1F80009C + *(s32*)D_1F80009C;
        *(s16*)(obj + 0x42) = 0x7CCC;
    }
    if (g_playthrough_state.s[0xC] != 0xC) {
        D_800FF054_ovl33 = 0;
        D_800FF056_ovl33 = 0;
    } else {
        D_800FF054_ovl33 = -0x960;
        D_800FF056_ovl33 = 0x10;
    }
    obj[0x14] = D_8009A0B4;
    func_8003D29C(0x14, 0x40);
    x = D_800FF054_ovl33;
    y = D_800FF056_ovl33;
    *(s32*)(obj + 0x8) = 0;
    *(u8**)(obj + 0x30) = D_800FED70_ovl33;
    obj[0x16] = 5;
    *(u8**)(obj + 0x54) = D_800FEAD0_ovl33;
    *(u8**)(obj + 0x50) = D_800FEACC_ovl33;
    *(s16*)(obj + 0xA) = x + 0x1250;
    *(s16*)(obj + 0xE) = y + 0x60;
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = 0;
    *(u8**)(obj + 0x68) = D_800FEAF4_ovl33;
    obj[0x15] = 0;
    D_1F80004C.bytes[0x85] = 0;
    D_1F80004C.bytes[0x87] = 0;
    D_1F80004C.bytes[0x88] = 0;
    D_1F80004C.bytes[0x89] = 0;
    *(s16*)(D_1F80004C.bytes + 0x8E) = 0;
    D_1F80004C.bytes[0x8A] = 0;
    D_1F80004C.bytes[0x8B] = 0;
    obj[0x3] = 0;
    obj[0x65] = 0;
    set_animation(obj, 2);
    obj[0x4] = 1;
    obj[0x5] = 2;
    obj[0x6] = 0;
    b = D_8009A1F8.u;
    *(s32*)(obj + 0x90) = ((s8*)b)[0x48];
    b[0x48] = 1;
    for (i = 0; i < 2; i++) {
        p = find_free_visual_obj();
        if (p != 0) {
            p[0] = 0x51;
            p[1] = 6;
            p[2] = i + 0x20;
            p[0x14] = obj[0x14];
            *(s32*)(p + 0x38) = *(s32*)(obj + 0x38);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(s16*)(p + 0x40) = *(s16*)(obj + 0x40);
            if (g_playthrough_state.s[0xC] != 0xC) {
                load_palette(i * 4 + 0x130, D_1F800030 + i * 0x80, 4);
                *(s16*)(p + 0x42) =
                    ((i * 4 + 0x130) % 16) | (((i + 0x4C) / 4 + 0x1E0) << 6);
            } else {
                load_palette(i * 4 + 0x12C, D_1F800030 + (i * 0x80 + 0x80), 4);
                *(s16*)(p + 0x42) =
                    ((i * 4 + 0x12C) % 16) | (((i + 0x4B) / 4 + 0x1E0) << 6);
            }
            p[0x16] = 6;
            *(u8**)(p + 0x50) = obj;
            if (i != 0) {
                *(u8**)(p + 0x5C) = prev;
            } else {
                *(u8**)(p + 0x5C) = obj;
            }
            prev = p;
        }
    }
}

#define D_800FF54C_ovl06 D_800FEE4C_ovl33

#define func_800F7DF0_ovl06 func_800FA3B4_ovl33
#include "shared/func_800F7DF0_ovl06.c"
#undef func_800F7DF0_ovl06
#undef D_800FF54C_ovl06

#define func_800F7F84_ovl06 func_800FA548_ovl33
#include "shared/func_800F7F84_ovl06.c"
#undef func_800F7F84_ovl06

#define D_800FF94C_ovl06 D_800FF054_ovl33
#define D_800FF94E_ovl06 D_800FF056_ovl33
#define func_800FAFFC_ovl06 func_800FD5C0_ovl33

#define func_800F8084_ovl06 func_800FA648_ovl33
#include "shared/func_800F8084_ovl06.c"
#undef func_800F8084_ovl06
#undef D_800FF94C_ovl06
#undef D_800FF94E_ovl06
#undef func_800FAFFC_ovl06

#define func_800FAFFC_ovl06 func_800FD5C0_ovl33

#define func_800F81FC_ovl06 func_800FA7C0_ovl33
#include "shared/func_800F81FC_ovl06.c"
#undef func_800F81FC_ovl06
