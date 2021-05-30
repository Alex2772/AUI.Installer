//
// Created by alex2 on 5/30/2021.
//

#pragma once


#include "IPage.h"

class InstallingPage: public IPage {
public:
    void inflate(const _<AViewContainer>& container, InstallerModel& model) override;

    void deflate(const _<AViewContainer>& container, InstallerModel& model) override;
};


