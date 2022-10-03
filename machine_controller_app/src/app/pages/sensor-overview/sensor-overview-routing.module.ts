import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { SensorOverviewPage } from './sensor-overview.page';

const routes: Routes = [
  {
    path: '',
    component: SensorOverviewPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class SensorOverviewPageRoutingModule {}
