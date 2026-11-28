#include "types.h"

extern s32 func_800FEC84_ovl07(u8*, s32, s32, s32);
extern s16 D_8010201A_ovl07;
extern s16 D_8010201C_ovl07;
extern s16 D_8010201E_ovl07;
extern s16 D_80102020_ovl07;
extern s16 D_80102022_ovl07;
extern s16 D_80102024_ovl07;

s32 func_800FD6AC_ovl07(u8* o, u8 id) {
    if (func_800FEC84_ovl07(o, id, D_80102022_ovl07, D_80102024_ovl07) != 0 &&
        func_800FEC84_ovl07(o, id, D_8010201A_ovl07, D_8010201E_ovl07) != 0 &&
        func_800FEC84_ovl07(o, id, D_8010201C_ovl07, D_8010201E_ovl07) != 0 &&
        func_800FEC84_ovl07(o, id, D_8010201A_ovl07, D_80102020_ovl07) != 0 &&
        func_800FEC84_ovl07(o, id, D_8010201C_ovl07, D_80102020_ovl07) != 0) {
        return 0;
    }
    return 1;
}
