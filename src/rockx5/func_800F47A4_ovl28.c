#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D0E4(void);
extern s32 func_8002DF78(void);
extern void func_8002C338(s32, void*, s32);

void func_800F47A4_ovl28(u8* obj) {
    u8* p = *(u8**)(obj + 0x50);
    u8* n;
    s32 t;

    obj[3] = 1;
    func_80017248(obj);
    *(s32*)(obj + 8) = *(s32*)(p + 8);
    *(s32*)(obj + 0xC) = *(s32*)(p + 0xC);
    if (((s8*)obj)[2] == 3) {
        if (((s8*)obj)[0x45] == 1) {
            n = func_8002D0E4();
            if (n != 0) {
                n[0] = 0x61;
                n[1] = 0xB;
                n[2] = 4;
                *(u16*)(n + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(n + 0x30) = *(s32*)(obj + 0x30);
                *(s32*)(n + 0x3C) = *(s32*)(obj + 0x3C);
                *(u16*)(n + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                n[0x15] = obj[0x15];
                *(s32*)(n + 8) = *(s32*)(obj + 8);
                *(s32*)(n + 0xC) = *(s32*)(obj + 0xC);
                *(u8**)(n + 0x50) = p;
            }
        } else if (((s8*)obj)[0x45] == 2) {
            if (((s8*)p)[5] == 5) {
                obj[0x60] = (func_8002DF78() & 3) * 10 + 10;
            } else {
                obj[0x60] = 10;
            }
        }
        t = (obj[0x5C] + 1) & 3;
        obj[0x5C] = t;
        if (t >= 2) {
            switch (p[0x8B]) {
            case 5:
                func_8002C338(0x13C, D_1F800030 + 0x60, 1);
                func_8002C338(0x13D, D_1F800030 + 0x80, 1);
                break;
            case 9:
                func_8002C338(0x13C, D_1F800030 + 0x120, 1);
                func_8002C338(0x13D, D_1F800030 + 0x140, 1);
                break;
            case 10:
                func_8002C338(0x13C, D_1F800030 + 0xE0, 1);
                func_8002C338(0x13D, D_1F800030 + 0x100, 1);
                break;
            case 11:
                func_8002C338(0x13C, D_1F800030 + 0xA0, 1);
                func_8002C338(0x13D, D_1F800030 + 0xC0, 1);
                break;
            }
            *(s16*)(obj + 0x42) = 0x7CCC;
        } else {
            if (((s8*)obj)[0x60] != 0 || ((s8*)p)[7] >= 2) {
                if (p[0x8B] != 5) {
                    func_8002C338(0x13C, D_1F800030 + 0x1A0, 1);
                    func_8002C338(0x13D, D_1F800030 + 0x1C0, 1);
                } else {
                    func_8002C338(0x13C, D_1F800030 + 0x220, 1);
                    func_8002C338(0x13D, D_1F800030 + 0x240, 1);
                }
                t = obj[0x60] - 1;
                obj[0x60] = t;
                if ((t << 24) == 0 && ((s8*)p)[7] == 1) {
                    p[7] = 2;
                }
            } else {
                func_8002C338(0x13C, D_1F800030 + 0x160, 1);
                func_8002C338(0x13D, D_1F800030 + 0x180, 1);
            }
            *(s16*)(obj + 0x42) = 0x7CCC;
        }
    }
    if (((s8*)p)[7] == 3) {
        obj[3] = 0;
        switch (p[0x8B]) {
        case 5:
            func_8002C338(0x13C, D_1F800030 + 0x60, 1);
            func_8002C338(0x13D, D_1F800030 + 0x80, 1);
            break;
        case 9:
            func_8002C338(0x13C, D_1F800030 + 0x120, 1);
            func_8002C338(0x13D, D_1F800030 + 0x140, 1);
            break;
        case 10:
            func_8002C338(0x13C, D_1F800030 + 0xE0, 1);
            func_8002C338(0x13D, D_1F800030 + 0x100, 1);
            break;
        case 11:
            func_8002C338(0x13C, D_1F800030 + 0xA0, 1);
            func_8002C338(0x13D, D_1F800030 + 0xC0, 1);
            break;
        }
        obj[4]++;
    }
}
