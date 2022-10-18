import { Injectable } from '@angular/core';
import { interval, Observable } from 'rxjs';
import { switchMap } from 'rxjs/operators';
import { Param } from '../../model/domain';
import { DatabaseService } from '../db/database.service';

@Injectable({
  providedIn: 'root'
})
export class StateService {

  constructor(private databaseService: DatabaseService) { }

  public getStates(): Observable<Param[]> {
    const url = "http://localhost:8000/app_api/state/";
    return interval(500).pipe(
      switchMap(() => this.databaseService.get(url))
    );
  }

}
