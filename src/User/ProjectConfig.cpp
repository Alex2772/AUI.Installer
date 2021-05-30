//
// Created by alex2 on 5/30/2021.
//

#include "ProjectConfig.h"

#include <Page/WelcomePage.h>
#include <Page/LicensePage.h>
#include <Page/InstallDirPage.h>
#include <Page/InstallingPage.h>

/**
 * Setups pages for your installer.
 * @param pages container for all your pages. The order will be kept
 */
void ProjectConfig::setupPages(AVector<_<IPage>>& pages) {
    pages << _new<WelcomePage>()
          << _new<LicensePage>()
          << _new<InstallDirPage>()
          << _new<InstallingPage>();
}
