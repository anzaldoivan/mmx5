#include "types.h"
#include "mmx5/graphics.h"

void set_animation(u8* obj, s32 idx) {
    s32* entry;

    entry = (*(s32***)(obj + 0x30))[idx];
    *(obj + 0x48) = 0xFF;
    *(s8*)(obj + 0x17) = idx;
    *(s32**)(obj + 0x34) = entry;
    *(s32*)(obj + 0x44) = *entry;
}
