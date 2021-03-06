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
// Created by alex2 on 5/21/2021.
//


#include "InstallDirPage.h"
#include <AUI/Util/UIBuildingHelpers.h>
#include <AUI/View/ATextField.h>
#include <AUI/View/ACheckBox.h>
#include <AUI/View/APathChooserView.h>

void InstallDirPage::inflate(const _<AViewContainer>& container, InstallerModel& model) {
    mBinding = _new<ADataBinding<InstallerModel>>(&model);
    container->setLayout(_new<AVerticalLayout>());
    container->addView(Vertical {
        _new<ALabel>("Install folder") << ".title",
        _new<ALabel>("Please specify program installation folder:"),
        _new<APathChooserView>() && mBinding(&InstallerModel::installationFolder)
    } << ".padded-page");
}

void InstallDirPage::deflate(const _<AViewContainer>& container, InstallerModel& model) {
    mBinding = nullptr;
}
