### Sincronització

Pthreads ofereix mecanismes de sync amb MUTEX i variables de condició a nivell d'usuari.

* MUTEX: Exclusió mútua, es pot bloquejar i desbloquejar.

* Condvar: Evitan fer esperes actives, es combinen amb els mutex.

  `````c
  pthread_cond_t cond;
  res = pthread_cond_init (&cond, attr);
  pthread_mutex_lock (&mutex);
  while (!expr) {
  	res = pthread_cond_wait (&cond, &mutex);
  }
  pthread_cond_signal (&cond); //desperta un flux
  pthread_cond_broadcast(&cond);
  pthread_mutex_unlock (&mutex);
  `````

Futex es una interfície de Linux a nivell de sistema.

Grand Central Dispatch: Substitueix la interfície de pthreads.

### Rendiment

Temps d'execucció: Temps emprat.

Acceleració(speedup): Relacio del temps d'execució de diverses versions.

Ample de banda (bandwidht): Relació entre dades i temps invertit.

Latència: Cost d'iniciar operacions/comunicacions.

El sistema proporciona eines per veure el rendiment. top, htop, ps, time, vmstat, iostat

### Virtualització

Entorn virtual sencer a l'SO i les aplicacions. Es tracta d'un procés en el sistema host.