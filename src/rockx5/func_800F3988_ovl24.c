/* Adapted from mmx6 @c1c892d src/shared/rock_20/func_800EFC74.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/menu.c:func_8001C5A8, AGPL-3.0; proven shared with X6 by exact signature e4a5fdbaa049 (see THIRD_PARTY.md). */
#include "types.h"
extern u8 D_800F51F8_ovl24[32];
extern u8 D_800F5218_ovl24[0x180];

void func_800F3988_ovl24(u8** arg0) {
    __builtin_memcpy(*arg0 + 0x60, D_800F51F8_ovl24, 0x20);
    __builtin_memcpy(*arg0 + 0x80, D_800F5218_ovl24, 0x180);
}
