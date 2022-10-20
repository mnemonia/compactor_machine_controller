import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { CommandPanelPage } from './command-panel.page';

const routes: Routes = [
  {
    path: '',
    component: CommandPanelPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class CommandPanelPageRoutingModule {}
