import { Routes } from '@angular/router';

export const routes: Routes = [
  {path: 'miruta', loadComponent: () => import('./pages/home/home.component').then(m => m.HomeComponent)},
  {path: '', redirectTo: 'home'},
];
