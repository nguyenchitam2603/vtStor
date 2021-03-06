/*
<License>
Copyright 2016 Virtium Technology

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http ://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
</License>
*/

#ifndef __TrimBufferFormatter_h__
#define __TrimBufferFormatter_h__
#pragma once

#include <memory>
#include <vector>

#include "Ata.h"
#include "IBuffer.h"

namespace vtStor
{
    namespace Ata
    {
        class cTrimBufferFormatter
        {
        public:
            cTrimBufferFormatter();
            ~cTrimBufferFormatter();

        public:
            static void AddLbaRangeEntryToBuffer(std::shared_ptr<IBuffer>& DataBuffer, U64 StartLba, U16 SectorCount, U32 LbaRangeEntryOffset);
            static void FillBufferWithLbaRangeEntries(std::shared_ptr<IBuffer>& DataBuffer, const std::vector<StorageUtility::Ata::sLbaRangeEntry>& LbaRangeEntries);
            static U32  CalculateSectorCountInput(const std::vector<StorageUtility::Ata::sLbaRangeEntry>& LbaRangeEntries);

        private:
            static const U32 LBA_SIZE_IN_BYTE = 6;
            static const U32 SECTOR_COUNT_SIZE_IN_BYTE = 2;
            static const U32 LBA_RANGE_ENTRY_SIZE_IN_BYTE = 8;
            static const U32 NUMBER_OF_BITS_OF_A_BYTE = 8;
            static const U32 ATA_SECTOR_SIZE_IN_BYTE = 512;
            static const U32 MAX_LBA_RANGE_ENTRIES_PER_512_BYTE_BLOCK = (ATA_SECTOR_SIZE_IN_BYTE / LBA_RANGE_ENTRY_SIZE_IN_BYTE);
        };

    }
}

#endif