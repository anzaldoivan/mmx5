#include "types.h"
#include "mmx5/object.h"

void func_800EFD44_ovl09(u8* obj) {
    s8* p = *(s8**)(obj + 0x7C);

    if (p[7] > 0) {
        p[7]--;
    }
    clear_object_slot(obj);
}
