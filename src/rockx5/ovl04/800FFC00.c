#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s32 func_8004FC64(u8* a0);

void func_800FFC00_ovl04(u8* a0) {
    animate_object(a0);
    move_object(a0);
    func_800317B8(a0);
    if (func_80031DD0(a0) < 0) {
        func_8004FC64(a0);
        a0[4]++;
    } else if (is_off_screen(a0, 0x40, 0x40) == 0) {
        func_8002D9EC(a0, 0x10, 0x10);
    } else {
        a0[4]++;
    }
}

extern u8 D_800D1C00[];

void func_800FFC98_ovl04(u8* obj) {
    u8* src;

    animate_object(obj);
    src = *(u8**)(obj + 0x7C);
    if (*(s8*)(obj + 0x45) == 1) {
        func_800317B8(obj);
        *(s16*)(obj + 0xA) = *(s16*)(src + 0xA) + 0xF0;
        *(s16*)(obj + 0xE) = *(s16*)(src + 0xE);
    } else if (*(s8*)(obj + 0x45) ==
               2) { /* same body as else: keeps the li 2 in the bne slot */
        *(s16*)(obj + 0xA) = *(s16*)(src + 0xA) + 0xDA;
        *(s16*)(obj + 0xE) = *(s16*)(src + 0xE);
    } else {
        *(s16*)(obj + 0xA) = *(s16*)(src + 0xA) + 0xDA;
        *(s16*)(obj + 0xE) = *(s16*)(src + 0xE);
    }
    if (++*(s16*)(obj + 0x88) >= 0x78 || (D_800D1C00[0x2A] & 4)) {
        obj[4]++;
        D_800D1C00[0x2B] = 0;
    }
}

extern u8 D_800D1C2A;

void func_800FFD68_ovl04(u8* self) {
    u8* parent;

    animate_object(self);
    if (*(s8*)(self + 0x45) == 1) {
        func_800317B8(self);
    }
    parent = *(u8**)(self + 0x7C);
    *(s16*)(self + 0xA) = *(s16*)(parent + 0xA) + 0x30;
    *(s16*)(self + 0xE) = *(s16*)(parent + 0xE);
    if (((s8*)&D_800D1C2A)[1] == 0) {
        self[4]++;
    }
    self[3] = 1;
}
