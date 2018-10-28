#ifndef COMMONUTILITIES_H_INCLUDED
#define COMMONUTILITIES_H_INCLUDED

class wxString;

namespace FileManip_ItemUi
{
    bool hasExtension(const wxString &fileName, const wxString &extensionToCheck);
    void appendStringBeforeExt(wxString &fileName, const wxString &stringToAppend);
}


#endif // COMMONUTILITIES_H_INCLUDED
