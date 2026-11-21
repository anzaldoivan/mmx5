#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800FA214_ovl00 D_80077204

#define func_800EEB64_ovl00 func_8004B124
#include "shared/func_800EEB64_ovl00.c"
#undef func_800EEB64_ovl00
#undef D_800FA214_ovl00

void func_8004B160(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        obj[3] = 0;
        obj[4] = 3;
    }
    func_8002D9EC(obj, 0x40, 0xA0);
}

#include "shared/func_8004B1AC.c"
