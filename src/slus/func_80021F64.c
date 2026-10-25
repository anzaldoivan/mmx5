#include "types.h"
#include "addr.h"

extern u8 D_8009A0A0[];
extern u8 D_80092090[];
extern u8 D_800D1C00[];
extern int func_8002DAA0();

void func_80021F64(void) {
    s8* obj;

    if ((s8)D_8009A0A0[0xCC] != 0) {
        return;
    }
    for (D_1F80004C.bytes = D_80092090; D_1F80004C.bytes < D_80092090 + 0x1D40;
         D_1F80004C.bytes += 0x9C) {
        obj = (s8*)D_1F80004C.bytes;
        if (obj[0] != 0) {
            if ((s8)D_8009A0A0[0xCC] != 0 ||
                ((s8)D_800D1C00[0x12] != 0 && !(*(u8*)obj & 8))) {
                if (obj[3] != 0) {
                    func_8002DAA0(obj);
                }
            } else {
                D_1F800080[obj[1]]((u8*)obj);
            }
        }
    }
}
