#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_800F857C_ovl00(u8* obj) {
    *(s16*)(obj + 0x7C) += 1;
    if ((s16)(*(s16*)(obj + 0x7C) % 5) == 0) {
        D_800D50DE--;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
        if (D_800D50DE == 0) {
            obj[6]++;
        }
    }
    func_80017248(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
