#include "types.h"

extern s32 func_8002D800(u8* a0);
extern void func_8001296C(s32);
extern void func_8002DED4(u8* obj);
extern void func_8002D89C(u8* obj);
extern void func_8002D6FC(u8* obj);
extern s32 D_800FB694_ovl00;

void func_800FA044_ovl00(u8* obj) {
    obj[3] = 0;
    if (func_8002D800(obj) == 0) {
        switch ((s8)obj[5]) {
        case 0:
            if (D_800FB694_ovl00 == (s8)obj[2]) {
                obj[6] = 0;
                obj[5]++;
                obj[0x16] = 3;
                func_8001296C(4);
            }
            func_8002D89C(obj);
            break;
        case 1:
            func_8002DED4(obj);
            obj[6]++;
            if ((s8)obj[6] < 0x1F || (obj[6] & 1)) {
                func_8002D89C(obj);
            }
            break;
        }
    } else {
        func_8002D6FC(obj);
    }
}
