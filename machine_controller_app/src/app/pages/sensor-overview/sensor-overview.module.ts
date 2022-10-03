import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { SensorOverviewPageRoutingModule } from './sensor-overview-routing.module';

import { SensorOverviewPage } from './sensor-overview.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    SensorOverviewPageRoutingModule
  ],
  declarations: [SensorOverviewPage]
})
export class SensorOverviewPageModule {}
