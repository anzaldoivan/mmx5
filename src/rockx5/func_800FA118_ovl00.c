#include "types.h"

extern void func_8002D6FC(u8* obj);
extern void func_8002D89C(u8* obj);
extern s32 D_800FB694_ovl00;

void func_800FA118_ovl00(u8* obj) {
    s8 state;
    u8 next;

    state = obj[5];
    next = obj[5];
    obj[3] = 0;
    switch (state) {
    case 0:
        if (D_800FB694_ovl00 == ((s8)obj[2] - 4)) {
            obj[6] = 0;
            obj[5] = next + 1;
        }
        break;
    case 1:
        if (D_800FB694_ovl00 == 30000) {
            obj[5] = next + 1;
        }
        obj[6]++;
        if (obj[6] & 1) {
            obj[0x47] = obj[2] + 4;
        } else {
            obj[0x47] = obj[2];
        }
        break;
    case 2:
        func_8002D6FC(obj);
        break;
    }
    func_8002D89C(obj);
}
