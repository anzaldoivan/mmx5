#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002DF54(u8* a0);
extern s32 func_8002DF78(void);
extern void func_800FCC24_ovl38(u8* obj, s32 state);
extern signed char D_800D1CA2;
extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];
extern u8 D_800FD58C_ovl38[];
extern u8 D_800FD590_ovl38[];

void func_800FA950_ovl38(u8* obj) {
    u8 flags;

    flags = obj[0x70];
    if (flags & 8) {
        func_800171E8(obj, 3);
        *(u8**)(obj + 0x50) = D_800FD574_ovl38;
        *(u8**)(obj + 0x54) = D_800FD578_ovl38;
        *(u8**)(obj + 0x68) = D_800FD57C_ovl38;
        if (D_1F80004C.bytes[0x91] == 0 && D_800D1CA2 / 2 >= ((s8*)obj)[0x5C] &&
            (func_8002DF78() & 1)) {
            obj[5] = 9;
        } else {
            obj[5] = 3;
        }
        obj[6] = 0;
        return;
    }
    if (obj[0x15] == 0) {
        if (flags & 2) {
            obj[0x15] = 0x40;
            func_800171E8(obj, 7);
            *(u8**)(obj + 0x50) = D_800FD58C_ovl38;
            *(u8**)(obj + 0x54) = D_800FD590_ovl38;
            *(s16*)(obj + 0x7C) = 10;
            obj[6] = 0;
            return;
        }
    } else if (flags & 1) {
        obj[0x15] = 0;
        func_800171E8(obj, 7);
        *(u8**)(obj + 0x50) = D_800FD58C_ovl38;
        *(u8**)(obj + 0x54) = D_800FD590_ovl38;
        *(s16*)(obj + 0x7C) = 10;
        obj[6] = 0;
        return;
    }
    func_8002DF54(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        *(s16*)(obj + 0x7C) = 8;
        func_800FCC24_ovl38(obj, 5);
    }
}
