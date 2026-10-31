#include "types.h"
#include "addr.h"

extern u8 D_8009A0A0[];
extern u8 D_800C6A10[];
extern u8 D_800D1C00[];
extern int func_8002DAA0();

void func_800224F8(void) {
    s8* obj;

    if ((s8)D_8009A0A0[0xCC] != 0) {
        return;
    }
    for (D_1F800060 = D_800C6A10; D_1F800060 < D_800C6A10 + 0x2900;
         D_1F800060 += 0xA4) {
        obj = (s8*)D_1F800060;
        if (obj[0] != 0) {
            if ((s8)D_8009A0A0[0xCC] != 0 ||
                ((s8)D_800D1C00[0x16] != 0 && !(*(u8*)obj & 8))) {
                if (obj[3] != 0) {
                    func_8002DAA0(obj);
                }
            } else {
                D_1F800094[obj[1]]((u8*)obj);
            }
        }
    }
}
