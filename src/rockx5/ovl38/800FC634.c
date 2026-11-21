#include "types.h"
#include "mmx5/ovl38.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/system.h"

extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];

void func_800FC634_ovl38(u8* arg0) {
    set_animation(arg0, 0x14);
    play_sound(2, 0xA3, arg0);
    *(u8**)(arg0 + 0x50) = D_800FD574_ovl38;
    *(u8**)(arg0 + 0x54) = D_800FD578_ovl38;
    *(u8**)(arg0 + 0x68) = D_800FD57C_ovl38;
    func_800FCAA0_ovl38(arg0);
    arg0[6]++;
}

void func_800FC6A4_ovl38(u8* obj) {
    if ((s8)obj[0x45] == 1) {
        set_animation(obj, 0x17);
        *(s16*)(D_1F80004C.bytes + 0x88) = *(s16*)(obj + 0xA);
        *(s16*)(D_1F80004C.bytes + 0x8A) = *(s16*)(obj + 0xE);
        *(s16*)(obj + 0xA) = 0x1288;
        *(s16*)(obj + 0xE) = 0x7E0;
        obj[0x15] = 0;
        obj[6]++;
    }
}

void func_800FC724_ovl38(u8* obj) {
    if ((s8)obj[0x45] == 2) {
        play_sound(2, 0xA3, obj);
    } else if ((s8)obj[0x45] == 1) {
        set_animation(obj, 0xE);
        *(s16*)(obj + 0x7C) = 0x32;
        *(s16*)(obj + 0x7E) = random_byte() & 3;
        *(s16*)(D_1F80004C.bytes + 0x86) = 0;
        obj[6] = 4;
    }
}

void func_800FC7A4_ovl38(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0xE);
        *(s16*)(obj + 0x7C) = 50;
        obj[6]++;
    }
}

void func_800FC7FC_ovl38(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0x16);
        play_sound(2, 0xA3, obj);
        obj[6]++;
    }
}

void func_800FC860_ovl38(u8* obj) {
    if (((s8*)obj)[0x45] == 1) {
        set_animation(obj, 0x15);
        *(u16*)(obj + 0xA) = *(u16*)(D_1F80004C.bytes + 0x88);
        *(u16*)(obj + 0xE) = *(u16*)(D_1F80004C.bytes + 0x8A);
        obj[6]++;
        func_800FCAA0_ovl38(obj);
    }
}

void func_800FC8D0_ovl38(u8* obj) {
    s8 v = *(s8*)(obj + 0x45);

    if (v == 2) {
        play_sound(2, 0xA3, obj);
    } else if (v == 1) {
        set_animation(obj, 3);
        obj[5] = 3;
        obj[6] = 0;
    }
}
