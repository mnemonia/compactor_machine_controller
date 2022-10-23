import { Component, OnInit } from '@angular/core';
import { Param } from '../../model/domain';
import { ParamService } from '../../services/param/param.service';

@Component({
  selector: 'app-param',
  templateUrl: './param.page.html',
  styleUrls: ['./param.page.scss'],
})
export class ParamPage implements OnInit {
  params: Param[] = [];

  constructor(private paramService: ParamService) { }

  ngOnInit() {
    this.paramService.getParams().subscribe(
      (params) => {
        //console.log(params);
        this.params = params;
      });
  }

  onSubmit(event) {
    console.log("save", event);
    this.paramService.apply(this.params);
  }  
}
