import { Component, OnInit } from '@angular/core';
import { SensorService } from 'src/app/services/sensor/sensor.service';
import { Param } from '../../model/domain';
import { ParamService } from '../../services/param/param.service';

@Component({
  selector: 'app-heating-overview',
  templateUrl: './heating-overview.page.html',
  styleUrls: ['./heating-overview.page.scss'],
})
export class HeatingOverviewPage implements OnInit {
  heating_param_oben_oben = new Param();
  heating_param_oben_unten = new Param();
  heating_param_unten_oben = new Param();
  heating_param_unten_unten = new Param();
  cooling_param_oben_oben = new Param();
  cooling_param_oben_unten = new Param();
  cooling_param_unten_oben = new Param();
  cooling_param_unten_unten = new Param();

  heating_actual_oben_oben = new Param();
  heating_actual_oben_unten = new Param();
  heating_actual_unten_oben = new Param();
  heating_actual_unten_unten = new Param();

  subsc1;
  subsc2;

  constructor(private paramService: ParamService, private sensorService: SensorService) {}

  ngOnInit() {
    this.subsc1 = this.paramService.getParams().subscribe(
      (params) => {
        //console.log(params);
        params.forEach(p => {
          if (p.param_id === 11) {
            this.heating_param_oben_oben = p;
          } else if (p.param_id === 12) {
            this.heating_param_oben_unten = p;
          } else if (p.param_id === 13) {
            this.heating_param_unten_oben = p;
          } else if (p.param_id === 14) {
            this.heating_param_unten_unten = p;
          } else if (p.param_id === 21) {
            this.cooling_param_oben_oben = p;
          } else if (p.param_id === 22) {
            this.cooling_param_oben_unten = p;
          } else if (p.param_id === 23) {
            this.cooling_param_unten_oben = p;
          } else if (p.param_id === 24) {
            this.cooling_param_unten_unten = p;
          }
        });
      },
      (err) => console.warn(err),
      () => {}
    );

    this.subsc2 = this.sensorService.getSensors().subscribe(
      (params) => {
        //console.warn("Sensors", params);
        params.forEach(p => {
          console.log(p);
          if (p.param_id === 15) {
            this.heating_actual_oben_oben = p;
          } else if (p.param_id === 16) {
            this.heating_actual_oben_unten = p;
          } else if (p.param_id === 17) {
            this.heating_actual_unten_oben = p;
          } else if (p.param_id === 18) {
            this.heating_actual_unten_unten = p;
          }        
        });
      });
  }

  onSubmit(event) {
    console.log("save", event);
    this.paramService.apply([
      this.cooling_param_oben_oben,
      this.cooling_param_oben_unten,
      this.cooling_param_unten_oben,
      this.cooling_param_unten_unten,
      this.heating_param_oben_oben,
      this.heating_param_oben_unten,
      this.heating_param_unten_oben,
      this.heating_param_unten_unten
    ]);
  }

  ionViewDidLeave() {
    this.subsc1.unsubscribe();
    this.subsc2.unsubscribe();
  }

}
