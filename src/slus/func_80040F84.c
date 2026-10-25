#include "types.h"

extern void func_8003A9AC(void);
extern void func_8002DED4(u8* obj);
extern void func_8003F294(u8* arg0, s32 arg1);

void func_80040F84(u8* obj) {
    if (obj[0x89] & 8) {
        func_8003A9AC();
        return;
    }
    func_8002DED4(obj);
    if (*(signed char*)(obj + 0x46) == 0) {
        func_8003F294(obj, 0xB);
        obj[5] = 7;
        obj[6] = 0;
    }
}
