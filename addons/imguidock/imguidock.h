#ifndef IMGUIDOCK_H_
#define IMGUIDOCK_H_

// based on https://github.com/nem0/LumixEngine/blob/master/external/imgui/imgui_dock.h
// Lumix Engine Dock. From: https://github.com/nem0/LumixEngine/blob/master/src/editor/imgui/imgui_dock.h
/*
The MIT License (MIT)

Copyright (c) 2013-2016 Mikulas Florek

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
// modified from https://bitbucket.org/duangle/liminal/src/tip/src/liminal/imgui_dock.h

// USAGE:
/*
        // Outside any ImGuiWindow.
        // You may want to use a fullscreen window with no titlebar.
        if (ImGui::Begin("imguidock window (= lumix engine's dock system)",NULL,ImVec2(500, 500),0.95f,ImGuiWindowFlags_NoScrollbar)) {
            ImGui::BeginDockspace();
            static char tmp[128];
            for (int i=0;i<10;i++)  {
                sprintf(tmp,"Dock %d",i);
                if (i==9) ImGui::SetNextDock(ImGuiDockSlot_Bottom);// optional
                if(ImGui::BeginDock(tmp))  {
                    ImGui::Text("Content of dock window %d goes here",i);
                }
                ImGui::EndDock();
            }
            ImGui::EndDockspace();
        }
        ImGui::End();
*/

#ifndef IMGUI_API
#include <imgui.h>
#endif //IMGUI_API
 
typedef enum ImGuiDockSlot {
    ImGuiDockSlot_Left,
    ImGuiDockSlot_Right,
    ImGuiDockSlot_Top,
    ImGuiDockSlot_Bottom,
    ImGuiDockSlot_Tab,

    ImGuiDockSlot_Float,
    ImGuiDockSlot_None
} ImGuiDockSlot;

namespace ImGui{

IMGUI_API void BeginDockspace();
IMGUI_API void EndDockspace();
IMGUI_API void ShutdownDock();
IMGUI_API void SetNextDock(ImGuiDockSlot slot);
IMGUI_API bool BeginDock(const char* label, bool* opened = NULL, ImGuiWindowFlags extra_flags = 0);
IMGUI_API void EndDock();
IMGUI_API void SetDockActive();
IMGUI_API void DockDebugWindow();

// TODO: consider porting LoadDock/SaveDock to imguihelper.h
//IMGUI_API void SaveDock(Lumix::FS::OsFile& file);
//IMGUI_API void LoadDock(lua_State* L);

} // namespace ImGui

#endif //IMGUIDOCK_H_

