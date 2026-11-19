#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern void func_80047B10(u8* obj);
extern void (*D_80076FE8[])(u8*);
extern u8 D_80076FC8[];
extern u8 D_80076FCC[];

void func_80047654(u8* obj) {
    if (is_off_screen(obj, 0x2C, 0x20) == 0) {
        if (*(s8*)(obj + 0x98) != 0) {
            func_80047B10(obj);
        } else {
            animate_object(obj);
            D_80076FE8[*(s8*)(obj + 5)](obj);
            if (*(u8**)(obj + 0x50) != 0) {
                if (obj[0x17] == 2) {
                    *(u8**)(obj + 0x50) = D_80076FCC;
                } else {
                    *(u8**)(obj + 0x50) = D_80076FC8;
                }
            }
        }
    } else {
        func_80047B10(obj);
    }
}
