#include "types.h"
#include "mmx5/globals.h"

void func_800F72A0_ovl29(u8* obj) {
    u8* sub = *(u8**)(obj + 0x7C);

    func_800317B8(obj);
    animate_object(obj);
    func_8002D9EC(obj, 0x30, 0x30);
    if (*(s8*)(sub + 5) != 7) {
        obj[5] = 0;
        obj[6] = 0;
        obj[4]++;
    }
}
