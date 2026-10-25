#include "types.h"

extern void func_8003CE30(void);
extern void func_8003A94C(u8* obj);
extern void func_8003CD08(u8* arg0);

void func_800396E8(u8* obj) {
    s8 t = ((s8*)obj)[5];

    if (t == 0) {
        return;
    }
    if (t == 1) {
        return;
    }
    if (((s8*)obj)[0x67] != 0) {
        return;
    }
    if (((s8*)obj)[0xA4] > 0) {
        return;
    }
    if (((s8*)obj)[0xD5] < 0) {
        return;
    }
    if (((s8*)obj)[0xD4] != 0) {
        return;
    }
    if (obj[0x89] & 8) {
        return;
    }
    if (((s8*)obj)[2] != 0) {
        func_8003CE30();
    }
    func_8003A94C(obj);
    func_8003CD08(obj);
}
