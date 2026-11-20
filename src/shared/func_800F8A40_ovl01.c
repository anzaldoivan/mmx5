/* Shared body (DK-5), from the banked draft of func_800F8A40_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl01.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FD590_ovl01[];
extern u8 D_800FD594_ovl01[];
extern u8 D_800FD598_ovl01[];
extern u8 D_800FD59C_ovl01[];
extern u8 D_800FD5A0_ovl01[];
extern u8 D_800FD5A4_ovl01[];

void DEDUP_NAME(u8* obj) {
    u8* child;

    animate_object(obj);
    switch (*(s16*)(obj + 0x7C)) {
    case 0:
        play_sound(2, 9, obj);
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x1F;
            child[2] = 0;
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            child[0x14] = obj[0x14];
            *(s32*)(child + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(child + 0xC) = *(s32*)(obj + 0xC);
            child[0x15] = obj[0x15];
            *(u8**)(child + 0x7C) = obj;
            child[4] = 0;
        }
        break;
    case 8:
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x1F;
            child[2] = 1;
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            child[0x14] = obj[0x14];
            *(s32*)(child + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(child + 0xC) = *(s32*)(obj + 0xC);
            child[0x15] = obj[0x15];
            *(u8**)(child + 0x7C) = obj;
            child[4] = 0;
        }
        break;
    case 16:
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x1F;
            child[2] = 2;
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            child[0x14] = obj[0x14];
            *(s32*)(child + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(child + 0xC) = *(s32*)(obj + 0xC);
            child[0x15] = obj[0x15];
            *(u8**)(child + 0x7C) = obj;
            child[4] = 0;
        }
        break;
    case 24:
        set_animation(obj, 0);
        func_800FB308_ovl01(obj);
        *(s16*)(obj + 0x7C) = 0x28;
        obj[6] = 2;
        break;
    }
    (*(s16*)(obj + 0x7C))++;
    switch (obj[0x47]) {
    case 18:
        *(u8**)(obj + 0x50) = D_800FD590_ovl01;
        *(u8**)(obj + 0x54) = D_800FD594_ovl01;
        break;
    case 19:
        *(u8**)(obj + 0x50) = D_800FD598_ovl01;
        *(u8**)(obj + 0x54) = D_800FD59C_ovl01;
        break;
    case 20:
    case 21:
        *(u8**)(obj + 0x50) = D_800FD5A0_ovl01;
        *(u8**)(obj + 0x54) = D_800FD5A4_ovl01;
        break;
    }
}
