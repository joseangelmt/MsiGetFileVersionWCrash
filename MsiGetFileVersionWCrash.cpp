#include "pch.h"
#include <windows.h>
#include <Msi.h>
#include <vector>
#include <iostream>

#pragma comment(lib, "msi")

int main()
{
    wchar_t versionBuff[20];
    DWORD cchVersionBuf = _countof(versionBuff);
    wchar_t langBuff[20];
    DWORD cchLangBuf = _countof(langBuff);

    std::vector<const wchar_t*> files = {
        L"Digi21.DigiTab.EstiloOldDigiTab.dll",
        L"Digi21.Ide.PanelTareas.dll",
    };

    while (true) {
        for (auto file : files) {
            MsiGetFileVersionW(
                file,
                versionBuff,
                &cchVersionBuf,
                langBuff,
                &cchLangBuf);

            cchVersionBuf = _countof(versionBuff);
            cchLangBuf = _countof(langBuff);
            std::cout << "*";
        }

        std::cout << "ok";
    }

    return 0;
}
