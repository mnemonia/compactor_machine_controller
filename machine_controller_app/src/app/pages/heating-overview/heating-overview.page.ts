import { Component, OnInit } from '@angular/core';
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

  constructor(private paramService: ParamService) {}

  ngOnInit() {
    this.paramService.getParams().subscribe(
      (params) => {
        console.log(params);
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
}
