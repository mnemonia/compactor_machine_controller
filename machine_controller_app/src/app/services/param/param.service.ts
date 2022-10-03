import { Injectable } from '@angular/core';
import { interval, Observable, of } from 'rxjs';
import { switchMap } from 'rxjs/operators';

import { Param } from '../../model/domain';
import { DatabaseService } from '../db/database.service';

@Injectable({
  providedIn: 'root'
})
export class ParamService {

  constructor(private databaseService: DatabaseService) { }

  public getParams(): Observable<Param[]> {
    const url = "http://localhost:8000/app_api/param/";
   /* return interval(5000).pipe(
      switchMap(() => this.databaseService.get(url))
    ); */
    return this.databaseService.get(url);
  }
}
