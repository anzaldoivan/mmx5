#include "types.h"

void func_8003F250(u8* p);
void func_8003EE38(u8* p);
void func_8003DF20(u8* p);

void func_8003ED10(u8* p) {
    if (((s8*)p)[2] == 0) {
        if (((s8*)p)[0x93] == 6) {
            if (p[0x91] != 0) {
                p[0x91] = 1;
            }
            if (p[0x92] != 0) {
                p[0x92] = 1;
            }
        }
        p[0x93] = 0;
        func_8003F250(p);
        func_8003EE38(p);
        func_8003DF20(p);
    }
}
