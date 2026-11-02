#include "types.h"

extern void func_80017248(u8* obj);
extern void func_80016490(s32, s32, void*);
extern u8 D_8009A1F8[];
extern signed char D_800D1C0C;

void func_80054758(u8* obj, u8* arg1) {
    u8* p;

    if (*(s8*)(obj + 0x45) < 2) {
        func_80017248(obj);
        if (*(s8*)(obj + 0x45) == 1) {
            func_80016490(0, 0x11, obj);
            obj[0x45] = 0;
        }
        return;
    }
    arg1[0x10] = 0;
    arg1[0x12] = 0;
    p = D_8009A1F8;
    *(s16*)(p + 0x26) = *(u16*)(obj + 0xA);
    *(s16*)(p + 0x24) = *(u16*)(obj + 0xA);
    *(s32*)(obj + 0x84) = 0xA400;
    switch (*(s8*)(obj + 2)) {
    case 1: {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) + 0x50;
    } break;
    case 10: {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) + 0x10;
    } break;
    case 12: {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) + 0x60;
    } break;
    case 4: {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) + 0x530;
    } break;
    case 3: {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) + 0x170;
    } break;
    case 5: {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) - 0x10;
    } break;
    case 9: {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) + 0x110;
    } break;
    case 14: {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) + 0x130;
    } break;
    case 7:
        if (D_800D1C0C == 0x10) {
            u8* p = D_8009A1F8;
            *(s16*)(p + 0x26) = *(u16*)(obj + 0xA) - 0x60;
            *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) - 0x60;
            *(s32*)(obj + 0x84) = 0x14800;
        } else if (D_800D1C0C == 0x11) {
            u8* p = D_8009A1F8;
            *(s16*)(p + 0x26) = *(u16*)(obj + 0xA) - 0x70;
            *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) - 0x70;
            *(s32*)(obj + 0x84) = 0x14800;
        } else if (D_800D1C0C == 0x12) {
            u8* p = D_8009A1F8;
            *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) + 0x150;
        } else if (D_800D1C0C == 0xC) {
            u8* p = D_8009A1F8;
            *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) + 0x290;
        }
        break;
    case 8:
        if (D_800D1C0C == 0x10) {
            u8* p = D_8009A1F8;
            *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) + 0x90;
        } else if (D_800D1C0C == 0x11) {
            u8* p = D_8009A1F8;
            *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) + 0x10;
        } else if (D_800D1C0C == 0x12) {
            u8* p = D_8009A1F8;
            *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) + 0x30;
        }
        break;
    case 2:
    case 11:
    case 13: {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x24) = *(u16*)(obj + 0xA) + 0x30;
    } break;
    }
    if (*(s8*)(obj + 2) == 5) {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x26) -= 0x10;
    }
    if (*(s8*)(obj + 2) == 6) {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x24) = 0xCA0;
        *(s16*)(p + 0x2E) = 0xC0;
        *(s16*)(p + 0x26) += 0x10;
    }
    obj[5] = 3;
}
