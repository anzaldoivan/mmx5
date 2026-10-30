#include "types.h"
#include "addr.h"

extern u8 D_8009A0A0[];
extern u8 D_80096D98[];
extern u8 D_800D1C00[];
extern int func_8002DAA0();

void func_800221B0(void) {
    s8* obj;

    if ((s8)D_8009A0A0[0xCC] != 0) {
        return;
    }
    for (D_1F800050 = D_80096D98; D_1F800050 < D_80096D98 + 0x1380;
         D_1F800050 += 0x9C) {
        obj = (s8*)D_1F800050;
        if (obj[0] != 0) {
            if ((s8)D_8009A0A0[0xCC] != 0 ||
                ((s8)D_800D1C00[0x13] != 0 && !(*(u8*)obj & 8))) {
                if (obj[3] != 0) {
                    func_8002DAA0(obj);
                }
            } else {
                D_1F800084[obj[1]]((u8*)obj);
            }
        }
    }
}
