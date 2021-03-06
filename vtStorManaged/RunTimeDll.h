/*
<License>
Copyright 2015 Virtium Technology

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

#ifndef __vtStorRunTimeDll_h__
#define __vtStorRunTimeDll_h__
#pragma once

#include "IRunTimeDll.h"

namespace vtStor
{
    namespace Managed
    {
        public ref class cRunTimeDll : public IRunTimeDll
        {
        public:
            cRunTimeDll(HMODULE Module, System::String^ ModulePath);
            ~cRunTimeDll();

        protected:
            !cRunTimeDll();

        public:
            virtual FARPROC GetFunction(LPCSTR name);

        private:
            HMODULE m_Module;
            System::String^ m_ModulePath;
        };
    }
}

#endif // end __vtStorRunTimeDll_h__