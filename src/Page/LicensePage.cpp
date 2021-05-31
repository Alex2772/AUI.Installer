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


#include <AUI/Util/UIBuildingHelpers.h>
#include <AUI/View/ATextField.h>
#include <AUI/View/ACheckBox.h>
#include <AUI/View/ATextArea.h>
#include <Window/MainWindow.h>
#include "LicensePage.h"
#include <AUI/ASS/ASS.h>

using namespace ass;

void LicensePage::inflate(const _<AViewContainer>& container, InstallerModel& model) {
    mBinding = _new<ADataBinding<InstallerModel>>(&model);

    container->setLayout(_new<AVerticalLayout>());

    container->addView(Vertical {
            _new<ALabel>("License") << ".title",
            _new<ALabel>("Please read the following license:"),
            _new<ATextArea>(AString::fromUtf8(AByteBuffer::fromStream(AUrl(":license/en.txt").open()))) with_style {
                Expanding { 2, 2, },
                FontSize { 12_pt }
            },
            _new<ACheckBox>("I agree with the license above") && mBinding(&InstallerModel::licenseAgree)
    } << ".padded-page");

    Autumn::get<MainWindow>()->getNextButton() && mBinding(&InstallerModel::licenseAgree, &AView::setEnabled);
}

void LicensePage::deflate(const _<AViewContainer>& container, InstallerModel& model) {
    Autumn::get<MainWindow>()->getNextButton()->enable();
    mBinding = nullptr;
}
