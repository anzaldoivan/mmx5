#include "types.h"
#include "addr.h"

extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
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
