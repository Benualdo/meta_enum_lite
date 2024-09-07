#include <windows.h>
#include <string>
#include "meta_enum.hpp"

void debugPrint(const char * _format, ...)
{
    const int bufferSize = 4096;
    char tempBuffer[bufferSize];
    tempBuffer[0] = 0;
    va_list args;
    va_start(args, _format);
    vsnprintf_s(tempBuffer, bufferSize - 1, _format, args);
    OutputDebugStringA(tempBuffer);
    va_end(args);
}

meta_enum(Amiga, int, Amiga600 = 0x68000, Amiga1200 = 0x68020);

int main()
{
    debugPrint("*** meta_enum_lite tests begin ***\n");

    debugPrint("Amiga_meta.string = \"%s\"\n", ((std::string)Amiga_meta.string).c_str());

    debugPrint("*** meta_enum_lite tests end ***\n");
}
