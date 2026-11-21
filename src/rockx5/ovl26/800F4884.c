#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/object.h"

void func_800F4884_ovl26(u8* obj) {
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    animate_object(obj);
    obj[6]++;
}

void func_800F48BC_ovl26(u8* obj) {
    animate_object(obj);
    if (*(signed char*)(obj + 0x45) != 0) {
        *(s16*)(obj + 0x7C) = 0x1E;
        obj[6]++;
    }
}

void func_800F4900_ovl26(Obj* o) {
    if (--o->timer != 0) {
        return;
    }
    switch (D_1F80004C.scr2074->unk94) {
    case 0:
        set_animation(o, 0xC);
        break;
    case 1:
        set_animation(o, 0x1C);
        break;
    case 2:
        set_animation(o, 0x1F);
        break;
    case 3:
        set_animation(o, 0x22);
        break;
    case 4:
        set_animation(o, 0x25);
        break;
    case 5:
        set_animation(o, 0x28);
        break;
    case 6:
        set_animation(o, 0x2B);
        break;
    case 7:
        set_animation(o, 0x2E);
        break;
    }
    o->timer = 20;
    o->step++;
}

void func_800F4A24_ovl26(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        *(s16*)(obj + 0x7C) = 0x1E;
        obj[6]++;
    }
}

void func_800F4A74_ovl26(Obj* o) {
    animate_object(o);
    if (--o->timer != 0) {
        return;
    }
    switch (D_1F80004C.scr2074->unk94) {
    case 0:
        set_animation(o, 0xD);
        break;
    case 1:
        set_animation(o, 0x1D);
        break;
    case 2:
        set_animation(o, 0x20);
        break;
    case 3:
        set_animation(o, 0x23);
        break;
    case 4:
        set_animation(o, 0x26);
        break;
    case 5:
        set_animation(o, 0x29);
        break;
    case 6:
        set_animation(o, 0x2C);
        break;
    case 7:
        set_animation(o, 0x2F);
        break;
    }
    o->step++;
}

void func_800F4B98_ovl26(u8* obj) {
    u8* p;

    animate_object(obj);
    if (((s8*)obj)[0x45] != 0) {
        p = *(u8**)(D_1F80004C.bytes + 0x80);
        if (p[0x8F] == 0) {
            p[0x92] = 0;
            (*(u8**)(D_1F80004C.bytes + 0x80))[0x8C] = 0;
            obj[6]++;
        }
    }
}

#define D_800EEBA0_ovl00 func_800F4C1C_ovl26
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

void func_800F4C3C_ovl26(u8* obj) {
    animate_object(obj);
    if (*(signed char*)(obj + 0x45) != 0) {
        *(s16*)(obj + 0x7C) = 0x3C;
        obj[6]++;
    }
}

void func_800F4C80_ovl26(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0xD);
        obj[6]++;
    }
}

void func_800F4CD4_ovl26(u8* obj) {
    animate_object(obj);
    if (((s8*)obj)[0x45] != 0) {
        (*(u8**)(D_1F80004C.bytes + 0x80))[0x92] = 0;
        clear_object_slot(obj);
    }
}
