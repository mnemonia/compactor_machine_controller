import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { StateOverviewPage } from './state-overview.page';

const routes: Routes = [
  {
    path: '',
    component: StateOverviewPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class StateOverviewPageRoutingModule {}
