#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern u8 D_800767E0[];
extern u8 D_80101014_ovl07[];
extern u8 D_80101018_ovl07[];
extern u8 D_80101028_ovl07[];
extern u8 D_8010102C_ovl07[];

void func_800F2DAC_ovl07(u8* obj) {
    *(u8**)(obj + 0x58) = D_800767E0;
    if (*(s8*)(obj + 0x66) > 0) {
        set_animation(obj, 9);
        *(u8**)(obj + 0x54) = D_80101028_ovl07;
        *(u8**)(obj + 0x68) = D_80101014_ovl07;
    } else {
        set_animation(obj, 10);
        *(u8**)(obj + 0x54) = D_8010102C_ovl07;
        *(u8**)(obj + 0x68) = D_80101018_ovl07;
    }
    *(u32*)(obj + 0x50) = 0;
    obj[6]++;
}

void func_800F2E30_ovl07(u8* obj) {
    s8* p = *(s8**)(obj + 0x7C);

    if (p[5] == 4) {
        if (p[6] < 2) {
            animate_object(obj);
            *(s32*)(obj + 0x54) = 0;
            *(s32*)(obj + 0x68) = 0;
        } else if (p[6] != 3) {
            obj[6]++;
        }
    }
}

void func_800F2EA8_ovl07(u8* obj) {
    if (*(u16*)(*(u8**)(obj + 0x7C) + 0x88) == 0) {
        if (*(s8*)(obj + 0x66) > 0) {
            set_animation(obj, 0xD);
        } else {
            set_animation(obj, 0xE);
        }
        play_sound(0, 0x11, obj);
        obj[6]++;
    }
}

extern u8* func_8002D078();
extern u8 D_80101028_ovl07[];
extern u8 D_8009A0B4;

void func_800F2F2C_ovl07(u8* obj) {
    u8* child;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        *(u8**)(obj + 0x50) = D_80101028_ovl07;
        child = func_8002D078();
        if (child != 0) {
            child[0] = 1;
            child[1] = 0x37;
            if (*(s8*)(obj + 0x66) > 0) {
                child[2] = 1;
            } else {
                child[2] = 2;
            }
            child[0x14] = D_8009A0B4;
            *(u8**)(child + 0x7C) = obj;
            *(u16*)(child + 0xA) = *(u16*)(obj + 0xA);
            *(u16*)(child + 0xE) = *(u16*)(obj + 0xE);
        }
        obj[6] = 0;
    }
}
