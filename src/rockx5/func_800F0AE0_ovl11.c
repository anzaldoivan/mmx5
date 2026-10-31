#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern void func_800F1148_ovl11(u8* obj);
extern void func_800F0F78_ovl11(u8* obj);
extern s8 D_800D1C00[];

void func_800F0AE0_ovl11(u8* obj) {
    func_80017248(obj);
    if (D_800D1C00[0x44] != (*(s32*)(obj + 0x84) & 1)) {
        func_800171E8(obj, 2);
    } else {
        func_800171E8(obj, 1);
    }
    if (*(s8*)(obj + 2) == 0) {
        if (*(s32*)(obj + 0x84) == 2 && D_800D1C00[0x44] == 0) {
            func_80016490(2, 0x2F, obj);
            func_800F1148_ovl11(obj);
        } else {
            func_80016490(2, 0x2F, obj);
            func_800F0F78_ovl11(obj);
        }
    } else {
        func_80016490(2, 0x2F, obj);
        func_800F0F78_ovl11(obj);
    }
    *(s16*)(obj + 0x7C) = 0x4B;
    if (*(s8*)(obj + 2) == 2) {
        *(s16*)(obj + 0x7C) = 0x32;
    }
    obj[6]++;
}
