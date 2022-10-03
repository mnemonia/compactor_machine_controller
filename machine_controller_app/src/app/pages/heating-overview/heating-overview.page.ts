import { Component, OnInit } from '@angular/core';
import { Param } from '../../model/domain';
import { ParamService } from '../../services/param/param.service';

@Component({
  selector: 'app-heating-overview',
  templateUrl: './heating-overview.page.html',
  styleUrls: ['./heating-overview.page.scss'],
})
export class HeatingOverviewPage implements OnInit {
  params: Param[] = [];

  constructor(private paramService: ParamService) {}

  ngOnInit() {
    this.paramService.getParams().subscribe(
      (params) => {
        console.log(params);
        this.params = params;
      },
      (err) => console.warn(err),
      () => {}
    );
  }

}
