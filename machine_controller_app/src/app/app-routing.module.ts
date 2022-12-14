import { NgModule } from '@angular/core';
import { PreloadAllModules, RouterModule, Routes } from '@angular/router';

const routes: Routes = [
  {
    path: '',
    redirectTo: 'heating-overview',
    pathMatch: 'full'
  },
  {
    path: 'sensor-overview',
    loadChildren: () => import('./pages/sensor-overview/sensor-overview.module').then( m => m.SensorOverviewPageModule)
  },
  {
    path: 'heating-overview',
    loadChildren: () => import('./pages/heating-overview/heating-overview.module').then( m => m.HeatingOverviewPageModule)
  },
  {
    path: 'state-overview',
    loadChildren: () => import('./pages/state-overview/state-overview.module').then( m => m.StateOverviewPageModule)
  },
  {
    path: 'param',
    loadChildren: () => import('./pages/param/param.module').then( m => m.ParamPageModule)
  },
  {
    path: 'command-panel',
    loadChildren: () => import('./pages/command-panel/command-panel.module').then( m => m.CommandPanelPageModule)
  },
];

@NgModule({
  imports: [
    RouterModule.forRoot(routes, { preloadingStrategy: PreloadAllModules })
  ],
  exports: [RouterModule]
})
export class AppRoutingModule {}
