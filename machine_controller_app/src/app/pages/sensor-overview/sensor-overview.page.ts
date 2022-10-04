import { Component, OnInit } from '@angular/core';
import { Param } from 'src/app/model/domain';
import { SensorService } from 'src/app/services/sensor/sensor.service';

@Component({
  selector: 'app-sensor-overview',
  templateUrl: './sensor-overview.page.html',
  styleUrls: ['./sensor-overview.page.scss'],
})
export class SensorOverviewPage implements OnInit {
  params: Param[] = [];
  subsc;

  constructor(private sensorService: SensorService) {}

  ngOnInit() {
    this.subsc = this.sensorService.getSensors().subscribe(
      (params) => {
        //console.log(params);
        this.params = params;
      },
      (err) => console.warn(err),
      () => {}
    );
  }

  ionViewDidLeave() {
    this.subsc.unsubscribe();
  }

}
