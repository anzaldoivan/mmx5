/* W38 draft: copy state byte, place relative to parent by kind, dispatch state handler (rockx5 ovl04). */
#include "types.h"

extern u8 D_800D1C2A;
extern void (*D_80102CC8_ovl04[])(u8*);

void func_800FEB80_ovl04(u8* o) {
    u8* p;

    o[0x8E] = o[5];
    p = *(u8**)(o + 0x80);
    if (*(s8*)(o + 2) == 10) {
        *(s16*)(o + 0xA) = *(s16*)(p + 0xA) - 0x1A;
        *(s16*)(o + 0xE) = *(s16*)(p + 0xE) - 0x10;
    } else {
        *(s16*)(o + 0xA) = *(s16*)(p + 0xA) - 0x18;
        *(s16*)(o + 0xE) = *(s16*)(p + 0xE) + 0x58;
    }
    D_80102CC8_ovl04[*(s8*)(o + 5)](o);
    if (D_800D1C2A & 8) {
        o[4]++;
    }
}
