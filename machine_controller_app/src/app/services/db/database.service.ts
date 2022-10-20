import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class DatabaseService {

  constructor(private httpClient: HttpClient) { }

  public get(url): Observable<any> {
    const httpHeaders: HttpHeaders = new HttpHeaders({
      "Content-Type": 'application/json'
    });
    return this.httpClient.get(url, { headers: httpHeaders, responseType: "json" });
  }

  public put(url, data): Observable<any> {
    const httpHeaders: HttpHeaders = new HttpHeaders({
      "Content-Type": 'application/json'
    });
    return this.httpClient.put(url, data, { headers: httpHeaders, responseType: "json" });
  }

}
