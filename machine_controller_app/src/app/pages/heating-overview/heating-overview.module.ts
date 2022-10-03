import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { HeatingOverviewPageRoutingModule } from './heating-overview-routing.module';

import { HeatingOverviewPage } from './heating-overview.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    HeatingOverviewPageRoutingModule
  ],
  declarations: [HeatingOverviewPage]
})
export class HeatingOverviewPageModule {}
