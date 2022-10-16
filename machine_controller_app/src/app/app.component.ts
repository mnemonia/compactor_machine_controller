import { Component } from '@angular/core';
@Component({
  selector: 'app-root',
  templateUrl: 'app.component.html',
  styleUrls: ['app.component.scss'],
})
export class AppComponent {
  public appPages = [
    { title: 'Temperierung', url: 'heating-overview', icon: 'flame' },
    { title: 'Sensoren', url: 'sensor-overview', icon: 'pulse' },
    { title: 'Zustände', url: 'state-overview', icon: 'pulse' },
  ];
  constructor() {}
}
