import { Injectable } from '@angular/core';
import { interval, Observable } from 'rxjs';
import { switchMap } from 'rxjs/operators';
import { Param } from '../../model/domain';
import { DatabaseService } from '../db/database.service';

@Injectable({
  providedIn: 'root'
})
export class SensorService {

  constructor(private databaseService: DatabaseService) { }

  public getSensors(): Observable<Param[]> {
    const url = "http://localhost:8000/app_api/sensor/";
    return interval(1000).pipe(
      switchMap(() => this.databaseService.get(url))
    );
  }

}
