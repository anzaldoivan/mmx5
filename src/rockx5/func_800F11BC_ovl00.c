#include "types.h"

extern void func_800F1080_ovl00(u8* obj);
extern s32 func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern int func_8002D7A0();
extern s8 D_800D1C1D;
extern s16 D_8009A202;

void func_800F11BC_ovl00(u8* obj) {
    if (*(s8*)(obj + 4) == 0) {
        func_800F1080_ovl00(obj);
        return;
    }
    func_80017248(obj);
    if (D_800D1C1D == 0) {
        *(s16*)(obj + 0xA) = *(u16*)(obj + 0x54) - (D_8009A202 * 5) / 4;
        func_8002D9EC(obj, 0x60, 0x60);
    } else {
        func_8002D7A0(obj);
    }
}
