#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/title.h"

void func_800F6BBC_ovl28(u8* obj) {
    animate_object(obj);
    func_800317B8(obj);
    func_8002D9EC(obj, 0x20, 0x14);
    if (*(s8*)(obj + 0x45) == 1) {
        set_animation(obj, 0x11);
        obj[5]++;
    }
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 2) {
        obj[4] = 2;
    }
}

void func_800F6C3C_ovl28(u8* obj) {
    u8* p;

    if ((u16)(*(u16*)(obj + 0xA) - 0x18E1) < 0x18F) {
        func_800317B8(obj);
        animate_object(obj);
        move_object(obj);
        func_8002D9EC(obj, 0x20, 0x14);
    } else {
        if ((obj[2] >> 4) == 1) {
            p = *(u8**)(obj + 0x7C);
            p[0x8C]++;
        }
        obj[4]++;
    }
    if (*(signed char*)(*(u8**)(obj + 0x7C) + 4) == 2) {
        obj[4] = 2;
    }
}

void func_800F6CFC_ovl28(u8* obj) {
    animate_object(obj);
    func_800317B8(obj);
    func_8002D9EC(obj, 0xC0, 0x40);
    if (*(s8*)(obj + 0x45) == 1) {
        play_sound(2, 0x77, obj);
        obj[5]++;
    }
}

void func_800F6D64_ovl28(u8* obj) {
    u8* p;

    if (is_off_screen(obj, 0xF0, 0x60) == 0) {
        animate_object(obj);
        func_800317B8(obj);
        move_object(obj);
        func_8002D9EC(obj, 0xC0, 0x40);
    } else {
        if ((obj[2] >> 4) == 1) {
            p = *(u8**)(obj + 0x7C);
            p[0x8C]++;
        }
        obj[4]++;
    }
    if (*(signed char*)(*(u8**)(obj + 0x7C) + 4) == 2) {
        obj[4] = 2;
    }
}

void func_800F6E20_ovl28(u8* obj) {
    u8 n;

    animate_object(obj);
    func_800317B8(obj);
    n = obj[0x8D];
    if (n != 0) {
        if (n == 1) {
            set_animation(obj, 0x1D);
        }
        obj[0x8D]--;
    }
    if (func_80031DD0(obj) < 0 || ((s8*)obj)[0x45] == 1) {
        obj[4]++;
        (*(u8**)(obj + 0x7C))[0x8D] = 0;
    }
    if (((s8*)*(u8**)(obj + 0x7C))[4] == 2) {
        obj[4] = 2;
    }
}
