import { Injectable } from '@angular/core';
import { Command } from 'src/app/model/domain';
import { DatabaseService } from '../db/database.service';

@Injectable({
  providedIn: 'root'
})
export class CommandService {
  url = "http://localhost:8000/app_api/command/";

  constructor(private databaseService: DatabaseService) { }


  execute(command_id: number) {
    const cmd = new Command();
    cmd.command_id = command_id;
    cmd.must_run = true;
    this.databaseService.put(this.url + cmd.command_id + "/", cmd).subscribe(
      (res) => console.log(res)
    );
  }
}
