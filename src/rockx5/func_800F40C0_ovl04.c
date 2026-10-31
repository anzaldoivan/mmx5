#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_80044DE0();
extern s32 func_80016490(s32, s32, void*);
extern Bg800F3EA0 D_8009A1F8;
extern Glb800F3EA0 D_800D1C00;

void func_800F40C0_ovl04(u8* obj) {
    func_80017248(obj);
    if (func_80044DE0() == 0 && *(s8*)(obj + 0x45) == 1) {
        if (D_800D1C00.unkC != 0xC) {
            D_8009A1F8.unk26 = 0x1550;
            D_8009A1F8.unk24 = 0x1590;
        } else {
            D_8009A1F8.unk26 = 0x440;
            D_8009A1F8.unk24 = 0x480;
        }
        if (*(s8*)(obj + 0x5C) < D_800D1C00.unkA2) {
            if (--*(s16*)(obj + 0x7C) == 0) {
                func_80016490(0, 0xE, 0);
                *(s16*)(obj + 0x7C) = 3;
            }
            obj[0x5C]++;
        } else {
            *(s16*)(obj + 0x7C) = 0x3C;
            obj[5]++;
        }
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
    }
}
