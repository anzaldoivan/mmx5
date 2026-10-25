#include "types.h"

/* Step a byte countdown at +0x44; on expiry advance the script pointer at +0x34
 * by the signed stride at +0x46 and reload the word it points at into +0x44. */
void func_80017248(u8* obj) {
    s32* script;

    obj[0x44] = obj[0x44] - 1;
    if (((s8*)obj)[0x44] == 0) {
        script = *(s32**)(obj + 0x34) + *(s8*)(obj + 0x46);
        *(s32**)(obj + 0x34) = script;
        *(s32*)(obj + 0x44) = *script;
    }
}
