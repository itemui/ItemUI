#ifndef ITEMUIDATA_H
#define ITEMUIDATA_H

#include "wx/string.h"
#include "ItemHeaders.h"
#include <string.h>
class ItemUIData
{
    public:
        enum DataSaveState {DATA_SAVE_STATE_UNKNOWN, DATA_SAVE_STATE_GOOD, DATA_SAVE_STATE_SAVED};

        ItemUIData();
        ~ItemUIData();

        bool IsNewData() {return m_newData;}
        void Intialise(const wxString &fileName, bool isNewData = false);

        void GetInputData(InputData &curr_data) {
        curr_data = m_inputData;}

        wxString GetUIDataFileFullPath() {return m_uiDataFileFullPath;}

        void SetUpdatedInputData(const InputData &updatedData);
        InputData *GetUpdateUIData() {return &m_updatedInputData;}

        void SetDataSaveState(const DataSaveState &saveState) {m_dataSaveState = saveState;}
        DataSaveState GetDataSaveState() {return m_dataSaveState;}

private:
        InputData m_inputData;
        InputData m_updatedInputData;
        bool m_newData;
        wxString m_uiDataFileFullPath;
        DataSaveState m_dataSaveState;
};

#endif // ITEMUIDATA_H
