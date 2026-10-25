#include "types.h"

void func_80026CAC(u8* p, s32 n);

void func_80027370(u8* p) {
    if (p[0xFA] == 1) {
        func_80026CAC(p, p[0x155] + 3);
        func_80026CAC(p, p[0x155]);
        func_80026CAC(p, p[0x155] + 2);
        func_80026CAC(p, p[0x155] + 1);
    } else if (p[0xFA] == 4) {
        func_80026CAC(p, p[0x155]);
    } else if (((s8*)p)[5] != 1 || p[0x47] != 0x7E) {
        func_80026CAC(p, p[0x155]);
    }
}
