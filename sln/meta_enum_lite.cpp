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

namespace test
{
    meta_enum(MyEnum, int, A = 65, B = 66, C = 67);
}

int main()
{
    debugPrint("*** meta_enum_lite tests begin ***\n");
    {
        const auto & members = getEnumMembers<test::MyEnum>();
        for (auto i = 0; i < members.size(); ++i)
            debugPrint("#%u %.*s = %u\n", i, members[i].name.size(), members[i].name.data(), members[i].value);

        debugPrint("(string) test::MyEnum::A = \"%s\"\n", getEnumString(test::MyEnum::A).c_str());

        debugPrint("getEnumValue<%s>(0) = %u\n", getEnumString(getEnumValue<test::MyEnum>(0)).c_str(), getEnumValue<test::MyEnum>(0));
    }
    debugPrint("*** meta_enum_lite tests end ***\n");
}
