#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F2D48_ovl11(u8* obj) {
    u8 flags;

    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        flags = D_1F80004C.bytes[0x82];
        if (flags & 0x80) {
            switch (flags & 3) {
            case 0:
                set_animation(obj, 0xD);
                break;
            case 1:
                set_animation(obj, 0xC);
                break;
            case 2:
                set_animation(obj, 0xE);
                break;
            }
        } else {
            set_animation(obj, 0x1A);
        }
        obj[6]++;
    }
}

void func_800F2E20_ovl11(u8* obj) {
    u8* p;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        obj[6]++;
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x19;
            p[2] = D_1F80004C.bytes[0x82];
            *(s32*)(p + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            p[0x14] = obj[0x14];
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            p[0x15] = obj[0x15];
        }
    }
}

void func_800F2EFC_ovl11(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        set_animation(obj, 0xB);
        obj[6]++;
    }
}

void func_800F2F48_ovl11(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        if (D_1F80004C.bytes[0x85] != 2) {
            obj[5] = 5;
        } else {
            obj[5] = 7;
        }
        obj[6] = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x20) = 0;
        D_1F80004C.bytes[0x81] = 0;
        if (D_1F80004C.bytes[0x85] == 2) {
            D_1F80004C.bytes[0x83] = 0x5A;
        } else {
            D_1F80004C.bytes[0x83] = 0xB4;
        }
        set_animation(obj, 7);
    }
}
