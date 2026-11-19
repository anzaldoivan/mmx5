#include "types.h"
#include "mmx5/globals.h"

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
    animate_object(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
