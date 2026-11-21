#include "types.h"
#include "mmx5/ovl38.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_800FD580_ovl38[];
extern u8 D_800FD584_ovl38[];
extern u8 D_800FD588_ovl38[];

void func_800FA4B8_ovl38(u8* obj) {
    s32 v;
    s32 a;
    s32 c;

    func_800FCAA0_ovl38(obj);
    set_animation(obj, 5);
    *(u8**)(obj + 0x50) = D_800FD580_ovl38;
    *(u8**)(obj + 0x54) = D_800FD584_ovl38;
    *(u8**)(obj + 0x68) = D_800FD588_ovl38;
    if (obj[0x15] == 0) {
        c = rcos(0x79C);
        a = 0x79C;
    } else {
        c = rcos(0x64);
        a = 0x64;
    }
    *(s32*)(obj + 0x20) = c * 16;
    *(volatile s32*)(obj + 0x24) =
        rsin(a) * 16; // !FAKE: volatile pins the store order
    v = *(
        volatile s32*)(obj +
                       0x20); // !FAKE: volatile keeps the lw below the 0x24 store
    if (v != 0) {
        *(s32*)(obj + 0x20) = v * 11 / 2;
    } else {
        *(s32*)(obj + 0x20) = 0;
    }
    v = *(s32*)(obj + 0x24);
    if (v != 0) {
        *(s32*)(obj + 0x24) = v * 11 / 2;
    } else {
        *(s32*)(obj + 0x24) = 0;
    }
    *(s16*)(obj + 0x7C) = 8;
    obj[6]++;
}

extern void func_800FCC24_ovl38(u8* obj, s32 state);
extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];
extern u8 D_800FD58C_ovl38[];
extern u8 D_800FD590_ovl38[];

void func_800FA5C0_ovl38(u8* obj) {
    u8 flags;

    flags = obj[0x70];
    if (flags & 4) {
        set_animation(obj, 3);
        *(u8**)(obj + 0x50) = D_800FD574_ovl38;
        *(u8**)(obj + 0x54) = D_800FD578_ovl38;
        *(u8**)(obj + 0x68) = D_800FD57C_ovl38;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0x1800;
        obj[6] = 3;
        return;
    }
    if (obj[0x15] == 0) {
        if (flags & 2) {
            obj[0x15] = 0x40;
            set_animation(obj, 8);
            *(u8**)(obj + 0x50) = D_800FD58C_ovl38;
            *(u8**)(obj + 0x54) = D_800FD590_ovl38;
            *(s16*)(obj + 0x7C) = 10;
            obj[6] = 2;
            return;
        }
    } else if (flags & 1) {
        obj[0x15] = 0;
        set_animation(obj, 8);
        *(u8**)(obj + 0x50) = D_800FD58C_ovl38;
        *(u8**)(obj + 0x54) = D_800FD590_ovl38;
        *(s16*)(obj + 0x7C) = 10;
        obj[6] = 2;
        return;
    }
    move_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        *(s16*)(obj + 0x7C) = 8;
        func_800FCC24_ovl38(obj, 5);
    }
}

extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_800FD580_ovl38[];
extern u8 D_800FD584_ovl38[];

void func_800FA6E4_ovl38(u8* obj) {
    s32 v;

    if (--*(s16*)(obj + 0x7C) != 0) {
        return;
    }
    if (*(s16*)(obj + 0xE) >= 0x7E1) {
        set_animation(obj, 5);
        *(u8**)(obj + 0x50) = D_800FD580_ovl38;
        *(u8**)(obj + 0x54) = D_800FD584_ovl38;
        if (*(s16*)(obj + 0xA) >= 0x1211) {
            obj[0x15] = 0;
            *(s32*)(obj + 0x20) = rcos(0x79C) * 16;
            *(s32*)(obj + 0x24) = rsin(0x79C) * 16;
        } else {
            obj[0x15] = 0x40;
            *(s32*)(obj + 0x20) = rcos(0x64) * 16;
            *(s32*)(obj + 0x24) = rsin(0x64) * 16;
        }
        v = *(s32*)(obj + 0x20);
        if (v != 0) {
            *(s32*)(obj + 0x20) = v * 11 / 2;
        } else {
            *(s32*)(obj + 0x20) = 0;
        }
        v = *(s32*)(obj + 0x24);
        if (v != 0) {
            *(s32*)(obj + 0x24) = v * 11 / 2;
        } else {
            *(s32*)(obj + 0x24) = 0;
        }
        *(s16*)(obj + 0x7C) = 8;
        obj[6] = 1;
        return;
    }
    *(s16*)(obj + 0x7C) = 0;
    obj[5] = 6;
    obj[6] = 0;
}
