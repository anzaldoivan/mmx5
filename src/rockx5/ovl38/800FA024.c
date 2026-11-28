#include "types.h"
#include "addr.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/system.h"

extern u8 D_80076600[];
extern u8 D_8009A0B4;
extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];
extern u8 D_800FD594_ovl38[];
extern u8 D_800FD598_ovl38[];
extern u8 D_800FD824_ovl38[];

void func_800FA024_ovl38(u8* obj) {

    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x65] = 0;
    obj[0x61] = 0;
    if (((s8*)obj)[2] == 0) {
        obj[0x5C] = 0;
        obj[0x60] = 0xC;
        obj[0] = 0x61;
        *(s16*)(obj + 0x40) = 0;
        *(s16*)(obj + 0x42) = 0x7CCC;
        load_palette(0x13C, D_1F800030, 4);
        load_palette(0x12C, D_1F800030 + 0x200, 4);
        obj[0x14] = D_8009A0B4;
        obj[0x67] = 0;
        *(u8**)(obj + 0x30) = D_800FD824_ovl38;
        obj[0x16] = 5;
        *(u8**)(obj + 0x58) = D_80076600;
        *(u8**)(obj + 0x54) = D_800FD578_ovl38;
        *(u8**)(obj + 0x50) = D_800FD574_ovl38;
        *(u8**)(obj + 0x68) = D_800FD57C_ovl38;
        obj[0x15] = 0;
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        D_1F80004C.bytes[0x8D] = 0;
        D_1F80004C.bytes[0x8E] = random_byte() & 7;
        D_1F80004C.bytes[0x8F] = 0;
        D_1F80004C.bytes[0x90] = 0;
        D_1F80004C.bytes[0x91] = 0;
        D_1F80004C.bytes[0x92] = 0;
        D_1F80004C.bytes[0x93] = 0;
        obj[3] = 0;
        obj[0x65] = 0;
        set_animation(obj, 3);
        obj[4] = 1;
        obj[5] = 2;
        obj[6] = 0;
    } else if (((s8*)obj)[2] < 4) {
        obj[0x15] = 0;
        obj[0x5C] = 8;
        obj[0x60] = 8;
        obj[0x16] = 4;
        obj[3] = 1;
        set_animation(obj, 0xB);
        *(u8**)(obj + 0x58) = D_80076600;
        *(u8**)(obj + 0x54) = D_800FD598_ovl38;
        *(u8**)(obj + 0x50) = D_800FD594_ovl38;
        *(s16*)(obj + 0x7C) = 0x1E;
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(u8**)(obj + 0x68) = 0;
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        switch (((s8*)obj)[2]) {
        case 1:
            *(s16*)(D_1F80004C.bytes + 0x84) = 0x156;
            break;
        case 2:
            *(s16*)(D_1F80004C.bytes + 0x84) = 0x6AB;
            break;
        case 3:
            *(s16*)(D_1F80004C.bytes + 0x84) = 0xC00;
            break;
        }
        obj[4] = 3;
        obj[5] = 1;
        obj[6] = 0;
    } else {
        obj[0] = 0x71;
        *(s16*)(obj + 0x42) = 0x7C8C;
        obj[0x16] = 7;
        obj[3] = 1;
        *(s16*)(obj + 0x7C) = 0x14;
        obj[0x60] = 0xC;
        *(u8**)(obj + 0x58) = 0;
        *(u8**)(obj + 0x68) = 0;
        obj[4] = 5;
    }
}

extern void func_800FCD04_ovl38(u8* obj, s32 arg1);
extern void* D_800FD8A4_ovl38[];
extern u8 D_8009A11A;
extern u8 D_80074EE0[];
extern u8 D_80076600[];

void func_800FA2D4_ovl38(u8* obj) {
    s32 r;
    u8 t;
    u8* s;

    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    ((void (*)(u8*))D_800FD8A4_ovl38[*(s8*)(obj + 5)])(obj);
    if (D_1F80004C.bytes[0x8D] != 0) {
        func_800317B8(obj);
        r = func_80031DD0(obj);
        if (r < 0) {
            D_8009A11A = 1;
            obj[4] = 2;
            obj[5] = 0;
            return;
        }
        if (r > 0 && r != 0x7F) {
            *(u8**)(obj + 0x58) = D_80074EE0;
            if ((u32)(r - 0x19) < 2) {
                D_1F80004C.bytes[0x8C] = 2;
            } else {
                D_1F80004C.bytes[0x8C] = 0x1E;
            }
            if ((r == 6 || r == 0xF || r == 0x25 || r == 0x40) &&
                ((s8*)D_1F80004C.bytes)[0x93] == 0) {
                func_800FCD04_ovl38(obj, 1);
                D_1F80004C.bytes[0x93] = 0x78;
                D_1F80004C.bytes[0x8C] = 0xB4;
            }
        }
        s = D_1F80004C.bytes;
        t = s[0x8C];
        if (t != 0) {
            s[0x8C] = t + 0xFF;
            if (t & 2) {
                *(u16*)(obj + 0x42) |= 0x8000;
            } else {
                *(u16*)(obj + 0x42) &= 0x7FFF;
            }
            if (D_1F80004C.bytes[0x8C] == 0) {
                *(u8**)(obj + 0x58) = D_80076600;
                *(u16*)(obj + 0x42) &= 0x7FFF;
            }
        }
        if (((s8*)D_1F80004C.bytes)[0x93] != 0) {
            D_1F80004C.bytes[0x93] = D_1F80004C.bytes[0x93] - 1;
        }
    }
}
