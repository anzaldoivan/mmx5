#include "types.h"
#include "addr.h"

extern u8 D_8009A0A0[];
extern u8 D_80098120[];
extern u8 D_800D1C00[];
extern void* D_80071168[];
extern int func_8002DAA0();

void func_80022084(void) {
    s8* obj;

    if ((s8)D_8009A0A0[0xCC] != 0) {
        return;
    }
    for (D_1F800050 = D_80098120; D_1F800050 < D_80098120 + 0x1380;
         D_1F800050 += 0x9C) {
        obj = (s8*)D_1F800050;
        if (obj[0] != 0) {
            if ((s8)D_8009A0A0[0xCC] != 0 ||
                ((s8)D_800D1C00[0x11] != 0 && !(*(u8*)obj & 8))) {
                if (obj[3] != 0) {
                    func_8002DAA0(obj);
                }
            } else {
                ((void (*)(u8*))D_80071168[obj[1]])((u8*)obj);
            }
        }
    }
}
