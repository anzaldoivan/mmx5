#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern void func_800F9E98_ovl10(u8* obj);
extern int func_8002D7A0();

void func_800F9F9C_ovl10(u8* obj) {
    if (*(s8*)(obj + 4) == 0) {
        func_800F9E98_ovl10(obj);
    } else {
        animate_object(obj);
        if (is_off_screen(obj, 0x80, 0x80) == 0) {
            func_8002D9EC(obj, 0x80, 0x80);
        } else {
            func_8002D7A0(obj);
        }
    }
}
