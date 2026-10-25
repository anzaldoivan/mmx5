#include "types.h"

void func_8003DB8C(u8* p);
void func_8003DD3C(u8* p);
void func_8003EE38(u8* p);
void func_8003DF20(u8* p);

void func_8003ED94(u8* p) {
    s8 old;

    if (((s8*)p)[2] != 0) {
        func_8003DB8C(p);
        return;
    }
    old = ((s8*)p)[0x93];
    func_8003DD3C(p);
    func_8003EE38(p);
    if (old != ((s8*)p)[0x93]) {
        if (((s8*)p)[0x93] == 6) {
            if (p[0x91] != 0) {
                p[0x91] = 1;
            }
            if (p[0x92] != 0) {
                p[0x92] = 1;
            }
        }
        func_8003DF20(p);
    }
}
