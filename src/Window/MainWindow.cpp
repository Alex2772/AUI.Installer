/**
 * =====================================================================================================================
 * Copyright (c) 2021 Alex2772
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 * Original code located at https://github.com/Alex2772/aui
 * =====================================================================================================================
 */

//
// Created by alex2 on 5/19/2021.
//


#include <AUI/Util/UIBuildingHelpers.h>
#include "MainWindow.h"
#include <AUI/ASS/ASS.h>
#include <User/ProjectConfig.h>

using namespace ass;

MainWindow::MainWindow():
        AWindow(CPACK_PACKAGE_NAME, 400_dp, 400_dp, nullptr, WS_NO_MINIMIZE_MAXIMIZE )
{
    setContents(Vertical {
        Horizontal {

            Vertical {
                mContent = _new<AViewContainer>() with_style { Expanding {2, 2} }
            } with_style { BackgroundSolid { 0xffffff_rgb }, Expanding {2, 2} }

        } with_style { Expanding {2, 2} },

        Horizontal {
            _new<ASpacer>(),
            mBackButton = _new<AButton>("< Back").connect(&AButton::clicked, this, [&] {
                setPage(mCurrentPageId - 1);
            }),
            mNextButton = _new<AButton>("Next >").connect(&AButton::clicked, this, [&] {
                setPage(mCurrentPageId + 1);
            }),
            _new<AButton>("Cancel").connect(&AView::clicked, me::close) with_style { Margin { {}, {}, {}, 8_dp } }
        } with_style { Padding { 8_dp } }
    } with_style { Expanding {2, 2} });

    setCustomAss({
        Padding { 0_dp }
    });

    ProjectConfig::setupPages(mPages);

    setPage(0);
}

void MainWindow::setPage(int pageId) {
    if (mCurrentPageId >= 0) {
        mPages[mCurrentPageId]->deflate(mContent, mInstallerModel);
    }
    mCurrentPageId = pageId;
    mPages[pageId]->inflate(mContent, mInstallerModel);
    mBackButton->setEnabled(pageId != 0);
    mContent->updateLayout();
}
