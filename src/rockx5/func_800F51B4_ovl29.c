#include "types.h"

extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void (*D_800FA374_ovl29[])(u8* obj);
extern u8 D_800F9890_ovl29[];
extern u8 D_800F988C_ovl29[];

void func_800F51B4_ovl29(u8* obj) {
    D_800FA374_ovl29[*(s8*)(obj + 6)](obj);
    if ((u8)(obj[0x47] - 0x19) < 2) {
        *(u8**)(obj + 0x54) = D_800F9890_ovl29;
    } else {
        *(u8**)(obj + 0x54) = D_800F988C_ovl29;
    }
    func_8002D9EC(obj, 0x40, 0x40);
}
