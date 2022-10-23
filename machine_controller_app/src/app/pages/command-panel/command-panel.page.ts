import { Component, OnInit } from '@angular/core';
import { CommandService } from 'src/app/services/command/command.service';
import { Param } from '../../model/domain';
import { StateService } from '../../services/state/state.service';

@Component({
  selector: 'app-command-panel',
  templateUrl: './command-panel.page.html',
  styleUrls: ['./command-panel.page.scss'],
})
export class CommandPanelPage implements OnInit {
  params: Param[] = [];
  subsc;

  constructor(private stateService: StateService, private commandService: CommandService) { }

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

  send(command_id: number) {
    console.log("command_id", command_id);
    this.commandService.execute(command_id);
  }

  ionViewDidLeave() {
    this.subsc.unsubscribe();
  }

}
