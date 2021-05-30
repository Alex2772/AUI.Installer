//
// Created by alex2 on 5/30/2021.
//

#include "InstallingPage.h"
#include <AUI/Util/UIBuildingHelpers.h>
#include <Window/MainWindow.h>

void InstallingPage::inflate(const _<AViewContainer>& container, InstallerModel& model) {
    container->setLayout(_new<AVerticalLayout>());
    container->addView(Vertical {
            _new<ALabel>("Installing...") << ".title",
            _new<ALabel>("<path>"),
    } << ".padded-page");

    Autumn::get<MainWindow>()->getBackButton()->setVisibility(Visibility::GONE);
    Autumn::get<MainWindow>()->getNextButton()->setVisibility(Visibility::GONE);
}

void InstallingPage::deflate(const _<AViewContainer>& container, InstallerModel& model) {

}
