#include "types.h"

extern void func_80017248(u8* obj);
extern Tbl800EE9A8 D_800EE9A8_ovl26;
extern Tbl800EE9A8 D_800EE9D8_ovl26;

void func_800F38F4_ovl26(u8* obj) {
    Tbl800EE9A8 a;
    Tbl800EE9A8 b;
    s8 v;

    a = D_800EE9A8_ovl26;
    b = D_800EE9D8_ovl26;
    func_80017248(obj);
    if (((s8*)*(u8**)(obj + 0x7C))[7] == 0) {
        if ((*(u8**)(obj + 0x7C))[0x96] == 0) {
            v = ((s8*)obj)[2];
            if (v < 8) {
                obj[2] = a.b[obj[0x94] - 3][v];
            }
        } else {
            v = ((s8*)obj)[2];
            if (v < 8) {
                obj[2] = b.b[obj[0x94] - 3][v];
            }
        }
        obj[6]++;
    }
}
