#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800FB514_ovl00[])(u8*);
extern u8 D_800FB3DC_ovl00[];
extern u8 D_800FB3E0_ovl00[];
extern u8 D_800FB3E8_ovl00[];
extern u8 D_800FB3EC_ovl00[];
extern u8 D_80074EE0[];
extern u8 D_80075AC0[];

void func_800F87F8_ovl00(u8* obj) {
    D_800FB514_ovl00[*(s8*)(obj + 6)](obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
    if (obj[0x47] == 6) {
        *(u8**)(obj + 0x50) = D_800FB3E0_ovl00;
        *(u8**)(obj + 0x54) = D_800FB3EC_ovl00;
        *(u8**)(obj + 0x58) = D_80075AC0;
    } else {
        *(u8**)(obj + 0x50) = D_800FB3DC_ovl00;
        *(u8**)(obj + 0x54) = D_800FB3E8_ovl00;
        *(u8**)(obj + 0x58) = D_80074EE0;
    }
}
