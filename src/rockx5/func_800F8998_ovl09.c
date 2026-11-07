#include "types.h"
#include "addr.h"

extern void func_8002DF54(u8* a0);

void func_800F8998_ovl09(u8* a0) {
    func_8002DF54(a0);
    switch (D_1F80004C.bytes[0x84]) {
    case 1:
        if (*(s16*)(a0 + 0xE) >= 0x898) {
            *(s16*)(a0 + 0xE) = 0x898;
            a0[6]++;
        }
        break;
    case 2:
        if (*(s16*)(a0 + 0xE) >= 0x8D0) {
            *(s16*)(a0 + 0xE) = 0x8D0;
            a0[6]++;
        }
        break;
    case 3:
        if (*(s16*)(a0 + 0xE) >= 0x908) {
            *(s16*)(a0 + 0xE) = 0x908;
            a0[6]++;
        }
        break;
    }
}
