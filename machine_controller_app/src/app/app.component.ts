import { Component } from '@angular/core';
@Component({
  selector: 'app-root',
  templateUrl: 'app.component.html',
  styleUrls: ['app.component.scss'],
})
export class AppComponent {
  public appPages = [
    { title: 'Heizungen', url: 'heating-overview', icon: 'flame' },
    { title: 'Sensoren', url: 'sensor-overview', icon: 'pulse' },
  ];
  constructor() {}
}
