import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { CommandPanelPageRoutingModule } from './command-panel-routing.module';

import { CommandPanelPage } from './command-panel.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    CommandPanelPageRoutingModule
  ],
  declarations: [CommandPanelPage]
})
export class CommandPanelPageModule {}
