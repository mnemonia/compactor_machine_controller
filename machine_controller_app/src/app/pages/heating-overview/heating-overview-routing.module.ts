import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { HeatingOverviewPage } from './heating-overview.page';

const routes: Routes = [
  {
    path: '',
    component: HeatingOverviewPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class HeatingOverviewPageRoutingModule {}
