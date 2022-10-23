import { Component, OnInit } from '@angular/core';
import { Param } from 'src/app/model/domain';
import { StateService } from 'src/app/services/state/state.service';

@Component({
  selector: 'app-state-overview',
  templateUrl: './state-overview.page.html',
  styleUrls: ['./state-overview.page.scss'],
})
export class StateOverviewPage implements OnInit {

  params: Param[] = [];
  subsc;

  constructor(private stateService: StateService) {}

  ngOnInit() {
    this.subsc = this.stateService.getStates().subscribe(
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
