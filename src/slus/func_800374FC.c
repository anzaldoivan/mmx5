#include "types.h"

extern void func_800376EC(u8* arg0);
extern void func_8003D344(void* arg0);
extern void func_8003A94C(u8* obj);
extern void func_8003CFA8(u8* arg0);

void func_800374FC(u8* arg0) {
    func_800376EC(arg0);
    func_8003D344(arg0);
    if (((s8*)arg0)[6] == 0) {
        arg0[6]++;
    } else if (((s8*)arg0)[0x61] == 0x3C) {
        func_8003A94C(arg0);
        if (((s8*)arg0)[0xD3] != 0) {
            arg0[0xA4] = 0;
            arg0[0x61] = 0;
        } else {
            func_8003CFA8(arg0);
            ((s8*)arg0)[0xA4] = -1;
        }
    }
}
