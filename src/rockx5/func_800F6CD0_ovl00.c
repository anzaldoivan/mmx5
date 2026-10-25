#include "types.h"

extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017768(void);
extern void func_8002D720(u8* arg0);
extern s8 D_800D1C1D;

void func_800F6CD0_ovl00(u8* obj) {
    func_8002D9EC(obj, 0x7F, 0x7F);
    if (((s8*)obj)[2] == 1) {
        if (D_800D1C1D == 3) {
            func_80017768();
            func_8002D720(obj);
        }
    } else if (((s8*)obj)[2] == 0x70) {
        obj[3] = 0;
        if (D_800D1C1D == 3) {
            obj[3] = 1;
        }
    }
}
