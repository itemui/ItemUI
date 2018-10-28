#include "../include/CommonUtilities.h"
#include <wx/string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>

namespace FileManip_ItemUi
{
    //extensionToCheck - Extension without the '.' symbol
    bool hasExtension(const wxString &fileName, const wxString &extensionToCheck)
    {
        bool extensionPresent = true;

        size_t extStartPos = fileName.find_last_of(".");
        if(wxString::npos != extStartPos)
        {
            wxString extensionName = fileName.Mid(extStartPos + 1);

            if(extensionName.IsEmpty() || 0 != extensionName.Cmp(extensionToCheck))
            {
                extensionPresent = false;
            }
        }
        else
        {
            extensionPresent = false;
        }

        return extensionPresent;
    }

    void appendStringBeforeExt(wxString &fileName, const wxString &stringToAppend)
    {
        size_t extStartPos = fileName.find_last_of(".");
        wxString fileNameNoExt;
        wxString fileExtension;
        if(wxString::npos != extStartPos)
        {
            fileNameNoExt = fileName.Mid(0, extStartPos);
            fileExtension = fileName.Mid(extStartPos);
        }
        else
        {
            fileNameNoExt = fileName;
        }
        //ignoring case
        std::string data1 = std::string(fileNameNoExt.Mid(extStartPos-stringToAppend.length(),stringToAppend.length()).mb_str());
        std::transform(data1.begin(), data1.end(), data1.begin(), ::tolower);
        std::string data2 = std::string(stringToAppend.mb_str());
        std::transform(data2.begin(), data2.end(), data2.begin(), ::tolower);

        if(fileNameNoExt.length()>=4&&data1==data2)
        {
            //do nothing
        }
        else
        {
            fileNameNoExt = fileNameNoExt.Append(stringToAppend);
        }
        fileName = fileNameNoExt.Append(fileExtension);
    }
}
