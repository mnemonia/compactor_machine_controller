import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { StateOverviewPageRoutingModule } from './state-overview-routing.module';

import { StateOverviewPage } from './state-overview.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    StateOverviewPageRoutingModule
  ],
  declarations: [StateOverviewPage]
})
export class StateOverviewPageModule {}
